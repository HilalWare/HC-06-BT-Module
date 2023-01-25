#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3); // RX, TX
int ledPin = 13; // LED bağlantısı için pin

void setup() {
  BTSerial.begin(9600); // başlangıç hızı
  pinMode(ledPin, OUTPUT); // LED pin çıkış olarak ayarla
}

void loop() {
  if (BTSerial.available()) { // Bluetooth seri veri alınabiliyorsa
    char data = BTSerial.read(); // veriyi oku
    if (data == '1') { // eğer veri 1 ise
      digitalWrite(ledPin, HIGH); // LED'i yak
    } else if (data == '0') { // eğer veri 0 ise
      digitalWrite(ledPin, LOW); // LED'i söndür
    }
  }
}
