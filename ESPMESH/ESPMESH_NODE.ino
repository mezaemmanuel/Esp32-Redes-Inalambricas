/* CONFIGURACION DE NODO
El esp32 creeara una red donde se interconectaran cada uno de ellos, 
la utilidad de este codigo es que solo actuara de puente entre los demas dispositivos, pero no afectara a ninguno de manera independiente, 
siendo asi solo un nodo para lectura de datos y trasmision a un master
*/
//***MESH**//
#include <painlessMesh.h>
#define   MESH_PREFIX     "SSID"
#define   MESH_PASSWORD   "PASSWORD"
#define   MESH_PORT       5555
painlessMesh  mesh;
Scheduler userScheduler;

uint8_t WIFIChannel=13;
void sendMessage() ; // Prototype so PlatformIO doesn't complain

Task taskSendMessage( TASK_SECOND * 5 , TASK_FOREVER, &sendMessage );
String msg="";
void sendMessage() {
  //msg = "Hi from node1: ";
  //msg += mesh.getNodeId();
  mesh.sendBroadcast( msg );
//  taskSendMessage.setInterval( random( TASK_SECOND * 1, TASK_SECOND * 5 ));
}

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

  mesh.init( MESH_PREFIX, MESH_PASSWORD, &userScheduler, MESH_PORT, WIFI_AP_STA, WIFIChannel);
  mesh.onReceive(&receivedCallback);
  userScheduler.addTask( taskSendMessage );
  taskSendMessage.enable();
  Serial.println("Mi indentificador de nodo en es:" + String(mesh.getNodeId()));
}

void loop() {
  // it will run the user scheduler as well
  /*int NumNodes = mesh.getNodeList().size();
  Serial.println(NumNodes);*/
  if (Serial.available()){
    msg = Serial.readString();  
    Serial.println("Sending:" + msg);  
    mesh.sendBroadcast(msg);
  }
  mesh.update();
}
