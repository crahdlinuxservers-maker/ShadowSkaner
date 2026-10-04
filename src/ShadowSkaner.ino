/*
 * ShadowSkaner - Tactical Signal Intelligence Node
 * 
 * Autor: Stanisław Kozioł
 * GitHub: https://github.com/crahdlinuxservers-maker/ShadowSkaner
 * 
 * Logger GPS -> karta SD (format CSV)
 * Platforma: ESP-WROOM-32
 * 
 * Pinologia:
 *   GPS VCC -> VIN (5V)
 *   GPS TX  -> GPIO16
 *   GPS RX  -> GPIO17
 *   SD CS   -> GPIO5
 *   SD MOSI -> GPIO23
 *   SD MISO -> GPIO19
 *   SD SCK  -> GPIO18
 */

#include <HardwareSerial.h>
#include <SPI.h>
#include <SD.h>

// === Konfiguracja pinów ===
#define SD_CS     5
#define GPS_RX    16
#define GPS_TX    17

// === Obiekty globalne ===
HardwareSerial gpsSerial(2);
unsigned long lastLog = 0;

// === Inicjalizacja ===
void setup() {
  Serial.begin(115200);
  
  // Inicjalizacja karty SD
  SPI.begin(18, 19, 23, SD_CS);
  if (!SD.begin(SD_CS)) {
    Serial.println("SD ERROR - sprawdz karte i polaczenia");
    while(1);
  }
  Serial.println("SD OK");
  
  // Inicjalizacja GPS
  gpsSerial.begin(9600, SERIAL_8N1, GPS_RX, GPS_TX);
  Serial.println("GPS start - czekam na fix");
  
  // Nagłówek pliku CSV (tylko jeśli plik nie istnieje)
  if (!SD.exists("/shadow.csv")) {
    File f = SD.open("/shadow.csv", FILE_WRITE);
    if (f) {
      f.println("czas,lat,lon,sats,alt");
      f.close();
      Serial.println("Utworzono shadow.csv");
    }
  }
}

// === Główna pętla ===
void loop() {
  if (gpsSerial.available()) {
    String line = gpsSerial.readStringUntil('\n');
    Serial.println(line);
    
    // Interesuje nas tylko linia GPGGA
    if (line.startsWith("$GPGGA")) {
      
      // Sprawdzenie czy jest fix (7 pole po przecinkach)
      int commaCount = 0;
      int fixPos = -1;
      for (int i = 0; i < line.length(); i++) {
        if (line[i] == ',') {
          commaCount++;
          if (commaCount == 6) {
            fixPos = i + 1;
            break;
          }
        }
      }
      
      // Zapisujemy tylko jeśli fix = 1
      if (fixPos != -1 && line[fixPos] == '1') {
        
        // Parsowanie pól
        int idx = 0;
        String field[10];
        for (int i = 0; i < 10; i++) {
          int next = line.indexOf(',', idx);
          if (next == -1) break;
          field[i] = line.substring(idx, next);
          idx = next + 1;
        }
        
        // Wyciągnięcie danych
        String czas   = field[0].substring(0, 6);  // HHMMSS
        String rawLat = field[1];                   // 5058.88057
        String rawLon = field[3];                   // 01813.07239
        String sats   = field[6];                   // ilość satelitów
        String alt    = field[8];                   // wysokość
        
        // Konwersja na stopnie dziesiętne
        float lat = rawLat.substring(0,2).toFloat() + (rawLat.substring(2).toFloat() / 60.0);
        float lon = rawLon.substring(0,3).toFloat() + (rawLon.substring(3).toFloat() / 60.0);
        
        // Zapis na SD co 2 sekundy
        if (millis() - lastLog > 2000) {
          File f = SD.open("/shadow.csv", FILE_APPEND);
          if (f) {
            f.print(czas);   f.print(",");
            f.print(lat, 6); f.print(",");
            f.print(lon, 6); f.print(",");
            f.print(sats);   f.print(",");
            f.println(alt);
            f.close();
            Serial.println("LOGGED");
            lastLog = millis();
          } else {
            Serial.println("SD WRITE ERROR");
          }
        }
      }
    }
  }
}
