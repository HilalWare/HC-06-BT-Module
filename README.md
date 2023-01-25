# HC-06-BT-Module

HC-06, bir Bluetooth modülüdür ve Arduino gibi mikrodenetleyicilerle kullanılabilir. Aşağıdaki kod parçacığı, HC-06 modülünün Arduino ile nasıl kullanılacağını gösterir:

```c++
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3); // RX, TX

void setup() {
  BTSerial.begin(9600); // başlangıç hızı
  Serial.begin(9600); // seri iletişim için başlangıç hızı
}

void loop() {
  if (BTSerial.available()) { // Bluetooth seri veri alınabiliyorsa
    Serial.write(BTSerial.read()); // veriyi seri porta yaz
  }
  
  if (Serial.available()) { // seri veri alınabiliyorsa
    BTSerial.write(Serial.read()); // veriyi Bluetooth seri porta yaz
  }
}
```

İlk olarak, "SoftwareSerial.h" kütüphanesi dahil edilir ve Bluetooth seri haberleşme için bir nesne oluşturulur. Bu nesne, Arduino'nun 2. ve 3. pinlerini kullanır.
Ayrıca, LED bağlantısı için 13 numaralı pin kullanılır.
setup() fonksiyonunda, Bluetooth seri haberleşme hızı 9600 bps olarak ayarlanır ve LED pin çıkış olarak ayarlanır.
loop() fonksiyonunda, herhangi bir Bluetooth seri veri alındığında, veri okunur ve '1' veya '0' olarak kontrol edilir.
Eğer veri '1' ise, LED'i yakar. Eğer veri '0' ise, LED'i söndürür.
