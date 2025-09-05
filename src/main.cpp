#include <Arduino.h>
#include "BluetoothSerial.h"

BluetoothSerial Mahmut;

void setup() {
Serial.begin(115200);
Mahmut.begin("ESP32_Mahmut");
Serial.println("Bluetooth data started");
}

void loop() {
  int sensorValue = analogRead(32);
  Mahmut.println(sensorValue);
  delay(100);
}
