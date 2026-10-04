# 🔌 Pinologia ShadowSkaner

## ESP-WROOM-32

### GPS GY-NEO6MV2

| GPS | ESP32 | Uwagi |
|-----|-------|-------|
| VCC | VIN (5V) | **NIE 3.3V!** |
| GND | GND | wspólna masa |
| TX | GPIO16 | RX2 |
| RX | GPIO17 | TX2 |

### Czytnik Micro SD

| SD | ESP32 | Uwagi |
|----|-------|-------|
| VCC | 3.3V | bez stabilizatora |
| GND | GND | wspólna masa |
| CS | GPIO5 | Chip Select |
| MOSI | GPIO23 | |
| MISO | GPIO19 | |
| SCK/CLK | GPIO18 | |

### LCD 1602 I2C *(planowane)*

| LCD | ESP32 |
|-----|-------|
| VCC | VIN (5V) |
| GND | GND |
| SDA | GPIO21 |
| SCL | GPIO22 |

### Enkoder *(planowane)*

| Enkoder | ESP32 |
|---------|-------|
| CLK | GPIO32 |
| DT | GPIO33 |
| SW | GPIO25 |
| VCC | 3.3V |
| GND | GND |

### RFID RC522 *(planowane)*

| RFID | ESP32 |
|------|-------|
| SDA (CS) | GPIO21 |
| SCK | GPIO18 |
| MOSI | GPIO23 |
| MISO | GPIO19 |
| RST | GPIO26 |
| VCC | 3.3V |
| GND | GND |

**Uwaga:** SD i RFID współdzielą magistralę SPI (MOSI, MISO, SCK). Różne piny CS.
