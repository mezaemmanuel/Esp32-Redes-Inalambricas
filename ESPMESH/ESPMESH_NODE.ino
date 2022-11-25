/* CONFIGURACION DE NODO
El esp32 creeara una red donde se interconectaran cada uno de ellos, 
la utilidad de este codigo es que solo actuara de puente entre los demas dispositivos, pero no afectara a ninguno de manera independiente, 
siendo asi solo un nodo para lectura de datos y trasmision a un master
*/
//***MESH**//
#include <painlessMesh.h>
#define   MESH_PREFIX     "SSID"          //Nombre de la red a creear
#define   MESH_PASSWORD   "PASSWORD"     // Contraseña de la red
#define   MESH_PORT       5555           // puerto de Conexion 

Scheduler userScheduler;
painlessMesh  mesh;

void sendMessage() ; 
Task taskSendMessage( TASK_SECOND * 1 , TASK_FOREVER, &sendMessage );// aqui configuramos la frecuencia con la que enviaremos los mensajes

void sendMessage() {
  
 String Mensaje = "Hola";
  Serial.println("El mensaje que voy a enviar es : " + Mensaje);
  Serial.println(Mensaje);
  mesh.sendBroadcast(Mensaje);
  //mesh.sendSingle(nodeidMaster, Mensaje);
}

// Needed for painless library-----------opcional.
void receivedCallback( uint32_t from, String &msg ) {
  Serial.printf("startHere: Received from %u msg=%s\n", from, msg.c_str());
}
void newConnectionCallback(uint32_t nodeId) {
    Serial.printf("--> startHere: New Connection, nodeId = %u\n", nodeId);
}
void changedConnectionCallback() {
  Serial.printf("Changed connections\n");
}
void nodeTimeAdjustedCallback(int32_t offset) {
    Serial.printf("Adjusted time %u. Offset = %d\n", mesh.getNodeTime(),offset);
}
void setup() {
  Serial.begin(115200);
  mesh.init( MESH_PREFIX, MESH_PASSWORD, &userScheduler, MESH_PORT, WIFI_AP_STA, 13);
  mesh.onReceive(&receivedCallback);

  taskSendMessage.setInterval( TASK_SECOND * 10);
  userScheduler.addTask(taskSendMessage);
  taskSendMessage.enable();

}

void loop() {
   mesh.update();

}
