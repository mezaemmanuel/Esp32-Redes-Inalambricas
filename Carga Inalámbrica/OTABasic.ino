#include <ArduinoOTA.h>                                               
#include <WiFi.h> 


const char * ssid = "SSID"; 
const char * pwd = "PASSWORD"; 

void setup()                                                           
{
Serial.begin(115200);                                                  
IPAddress IP(192,168,137,13); //1-254                                 
IPAddress GW(197,168,137,1);                                                 
IPAddress SN(255,255,255,0);                                          
WiFi.config(IP, GW, SN);                                              
WiFi.begin(ssid, pwd);                                                 
  ArduinoOTA                                                           
  .onStart([]()
  {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH)
      type = "sketch";
    else // U_SPIFFS
      type = "filesystem";
    // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
    Serial.println("Start updating " + type);
  }
  )
    .onEnd([]()
    {
      Serial.println("\nEnd");
    }
  )
    .onProgress([](unsigned int progress, unsigned int total)
    {
      Serial.printf("Progress: %u%%\r",(progress / (total / 100)));
    }
  )
    .onError([](ota_error_t error)
    {
      Serial.printf("Error[%u]: ", error);
      if (error == OTA_AUTH_ERROR)
        Serial.println("Auth Failed");
      else
        if (error == OTA_BEGIN_ERROR)
          Serial.println("Begin Failed");
      else
        if (error == OTA_CONNECT_ERROR)
          Serial.println("Connect Failed");
      else
        if (error == OTA_RECEIVE_ERROR)
          Serial.println("Receive Failed");
      else
        if (error == OTA_END_ERROR)
          Serial.println("End Failed");
    }
  );                           
                       
  ArduinoOTA.begin();              
}

void loop() {
 ArduinoOTA.handle();                           
}
