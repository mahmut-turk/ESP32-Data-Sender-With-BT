#include <Arduino.h>
#include "BluetoothSerial.h"

BluetoothSerial Mahmut;                    // set the bluetooth device name as "Mahmut"

void setup() {
Serial.begin(115200);
Mahmut.begin("ESP32_Mahmut");
Serial.println("Bluetooth data started");  // if you want, you can monitor the data on the Serial Monitor
}

void loop() {
  int sensorValue = analogRead(32);   // reading analog data with GPIO32 of ESP32 
  Mahmut.println(sensorValue);        // sending data with Bluetooth 
  delay(100);                         //  reading in 100 milisecond intervals
}
