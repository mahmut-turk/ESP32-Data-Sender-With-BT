#include <Arduino.h>
#include "BluetoothSerial.h"

BluetoothSerial Mahmut; // Bluetooth device name "Mahmut"

const int btnPin = 27;
const int ledPin = 33;
const int adcPin = 32;
const int ecgPin = 34;

bool ledState = false;   // LED durumu
int btnCounter = 0;

void setup() {
  Serial.begin(115200);
  Mahmut.begin("ESP32_Mahmut");
  Serial.println("Bluetooth data started");

  pinMode(btnPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void sendADC() {
  int sensorValue = analogRead(adcPin);
  String adcStr = "ADC:" + String(sensorValue);
  Mahmut.println(adcStr);
  Serial.println(adcStr);
}

void sendECG() {
  int sensorECG = analogRead(ecgPin);
  String ecgStr = "ECG:" + String(sensorECG);
  Mahmut.println(ecgStr);
  Serial.println(ecgStr);
}

void sendButtonLED() {
  // Buton toggle
  if (digitalRead(btnPin) == LOW) {
    btnCounter++;
    ledState = !ledState;
    digitalWrite(ledPin, ledState ? HIGH : LOW);

    // LED durumu bildir
    String ledStr = ledState ? "LED:ON" : "LED:OFF";
    Mahmut.println(ledStr);
    Serial.println(ledStr);

    // Buton mesajı
    String btnStr = "BTN:The button was pressed " + String(btnCounter) + " time(s).";
    Mahmut.println(btnStr);
    Serial.println(btnStr);

    delay(300); // debounce
  }
  // LED durumunu sabitle
  digitalWrite(ledPin, ledState ? HIGH : LOW);
}

void receiveBluetooth() {
  while(Mahmut.available()){
    char c = Mahmut.read();
    if(c == '1'){
      ledState = true;
      digitalWrite(ledPin, HIGH);
      Mahmut.println("LED:ON");
      Serial.println("LED ON (Bluetooth)");
    } 
    else if(c == '0'){
      ledState = false;
      digitalWrite(ledPin, LOW);
      Mahmut.println("LED:OFF");
      Serial.println("LED OFF (Bluetooth)");
    }
  }
}

void loop() {
  receiveBluetooth();
  sendADC();
  sendECG();
  sendButtonLED();
  delay(100);
}
