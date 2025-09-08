#include <Arduino.h>
#include "BluetoothSerial.h"

BluetoothSerial Mahmut; // Bluetooth device name "Mahmut"
int btn = 0;
const int btnPin = 27;
const int ledPin = 33;
const int adcPin = 32;

void setup() {
  Serial.begin(115200);
  Mahmut.begin("ESP32_Mahmut");
  Serial.println("Bluetooth data started");

  pinMode(btnPin, INPUT_PULLUP);   
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(adcPin);

  // sending ADC data
  String adcStr = "ADC:" + String(sensorValue);
  Mahmut.println(adcStr);
  Serial.println(adcStr);

  // controlling button
  if (digitalRead(btnPin) == LOW) {
    btn++;
    digitalWrite(ledPin, HIGH);

    String btnStr = "BTN:The button was pressed " + String(btn) + " time(s).";
    Mahmut.println(btnStr);
    Serial.println(btnStr);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(100); // reading in 100 milisecond intervals
}
