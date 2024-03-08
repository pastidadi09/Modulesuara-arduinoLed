// Module sensor Suara KY-307

const int sensorSuaraPin = A5; // Pin sensor suara
const int jumlahLED = 8; // Jumlah LED yang akan berlari
const int delayLED = 70; // Waktu jeda antara perpindahan LED (dalam milidetik)
const int delayLED1 = 10; // Waktu jeda antara perpindahan LED (dalam milidetik)

int LEDPin[] = {2, 3, 4, 5, 6, 7, 8, 9}; // Pin untuk LED berurutan

void setup() {
  Serial.begin(9600);
  
  // Inisialisasi pin LED sebagai OUTPUT
  for (int i = 0; i < jumlahLED; i++) {
    pinMode(LEDPin[i], OUTPUT);
  }
}

void loop() {
  int nilaiSensorSuara = analogRead(sensorSuaraPin);

  // Baca nilai sensor suara
  Serial.println("Nilai Sensor Suara: " + String(nilaiSensorSuara));

  // Jika sensor suara mendeteksi suara, aktifkan LED berurutan
  if (nilaiSensorSuara > 1020) {
   
    for (int i = 0; i < jumlahLED; i++) {
      digitalWrite(LEDPin[i], HIGH);
      delay(delayLED);
      digitalWrite(LEDPin[i], LOW);
    }
  
  }  else if (nilaiSensorSuara > 500) { // Nilai ambang suara dapat disesuaikan
    // Iterasi dari tengah ke atas
    for (int i = 0; i < jumlahLED; i++) {
      digitalWrite(LEDPin[i], HIGH);
      delay(delayLED1);
      digitalWrite(LEDPin[i], LOW);
    }

    // Iterasi dari tengah ke bawah
    for (int i = jumlahLED - 1; i >= 0; i--) {
      digitalWrite(LEDPin[i], HIGH);
      delay(delayLED);
      digitalWrite(LEDPin[i], LOW);
    }


    
  } else {
    // Turn off all LEDs
    for (int i = 0; i < jumlahLED; i++) {
      digitalWrite(LEDPin[i], LOW);
    }
  }
}
