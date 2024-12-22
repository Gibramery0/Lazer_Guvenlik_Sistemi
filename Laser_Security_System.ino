// Pin tanımlamaları
const int lazerPini = 2;      // Lazer modülü pini
const int ldrPini = A0;       // LDR pini
const int buzzerPini = 3;     // Buzzer pini

// LDR eşik değeri (kalibre etmeniz gerekebilir)
const int esikDegeri = 500;   // Işığın kesildiği algılama seviyesi

void setup() {
  pinMode(lazerPini, OUTPUT);
  pinMode(buzzerPini, OUTPUT);
  digitalWrite(lazerPini, HIGH); // Lazer çalışsın
  Serial.begin(9600);            // Seri monitör için
}

void loop() {
  int ldrDegeri = analogRead(ldrPini); // LDR'den değer oku
  Serial.println(ldrDegeri);          // Değeri seri monitörde göster
  
  if (ldrDegeri < esikDegeri) {       // Eğer ışık kesilirse
    digitalWrite(buzzerPini, HIGH);   // Buzzer aktif
  } else {
    digitalWrite(buzzerPini, LOW);    // Buzzer kapalı
  }

  delay(100); // Biraz bekle
}
