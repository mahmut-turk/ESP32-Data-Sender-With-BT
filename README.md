# ESP32 Bluetooth Data Sender

This project demonstrates how to send sensor data from an ESP32 to another device (e.g., PC or smartphone) via Bluetooth using the BluetoothSerial library.

## Features
- ESP32 reads analog sensor values.
- Sends the values over Bluetooth continuously.
- Easy to integrate with PC or mobile applications for real-time data monitoring.

## Hardware Required
- ESP32 Development Board
- Analog sensor (e.g., potentiometer, photoresistor) connected to GPIO32
- USB cable to program ESP32

## Software Required
- PlatformIO or Arduino IDE (I used the PlatformIO)
- BluetoothSerial library (built-in with ESP32 Arduino core)

## Setup Instructions

1. Connect your sensor to GPIO32 on the ESP32.
2. Upload the code to your ESP32 using PlatformIO or Arduino IDE.
3. Pair the ESP32 Bluetooth device named `ESP32_Mahmut` with your PC or smartphone.
4. Open a Bluetooth terminal application or custom program to read the sensor data.

## Code Overview

```cpp
#include <Arduino.h>
#include "BluetoothSerial.h"

BluetoothSerial Mahmut;    // set the bluetooth device name as "Mahmut"

void setup() {
    Serial.begin(115200);
    Mahmut.begin("ESP32_Mahmut");
    Serial.println("Bluetooth data started"); // if you want, you can monitor the data on the Serial Monitor
}

void loop() {
    int sensorValue = analogRead(32);   // reading analog data with GPIO32 of ESP32 
    Mahmut.println(sensorValue);  // sending data with Bluetooth 
    delay(100);  //  reading in 100 milisecond intervals
}
