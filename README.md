
# Esp32 Redes Inalambricas

## Descripcion

Configuración y código para esp32 usando redes inalámbricas

El ESP32 puede Utilizarce para comincarse de distintas maneras. en el apartado de redes inalambricas, el repositorio abarca lo denominado como ESPNOW y ESPMESH

## ESP32MESH 

Utilizada y recomendada para tener una comunicacion descentralizada, esta red se autoadministra, eligiendo quien es el nodo central y quienes son los secundarios. 

basada en la libreria ["painlessMesh"](https://gitlab.com/painlessMesh/painlessMesh)
se puede ver otros ejemplos y expicacion de su uso [ aquí](https://randomnerdtutorials.com/esp-mesh-esp32-esp8266-painlessmesh/)

## ESPNOW
Utilizada y recomendada para tener una comunicación centralizada en un mismo nodo. (Master) quien a su vez administra y comunica en forma individual con cada uno de los ESP_seguidores/esclavos.  

basada en la libreria ["painlessMesh"](https://gitlab.com/painlessMesh/painlessMesh)
se puede ver otros ejemplos y expicacion de su uso [ aquí](https://randomnerdtutorials.com/esp-now-esp32-arduino-ide/)


## Carga Inalambrica

Este apartado lo incluyo para cuando ya estamos en campo y nos es tan fácil desmontar y volver a montar nuestros dispositivos para carga y descarga de código. 


basada en la libreria ["OTA"](https://www.arduinolibraries.info/libraries/arduino-ota)
se puede ver otros ejemplos y expicacion de su uso [ aquí](https://randomnerdtutorials.com/esp8266-ota-updates-with-arduino-ide-over-the-air/)

## Documentation

[painlessMesh libreria](https://gitlab.com/painlessMesh/painlessMesh)

[OTA libreria](https://www.arduinolibraries.info/libraries/arduino-ota)


