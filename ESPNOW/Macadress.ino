/*
obtenemos el identificador unico del esp32, cada esp 32 tendra uno diferente. 
*/
#include "WiFi.h"
 
void setup(){
  Serial.begin(115200);
  WiFi.mode(WIFI_MODE_STA);
  Serial.println(WiFi.macAddress());//esto es propio de la libreria EIFI
}
 
void loop(){

}
