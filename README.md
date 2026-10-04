# 🕶️ ShadowSkaner

> Mobilny terminal rozpoznania elektronicznego (Tactical Signal Intelligence Node) zbudowany na ESP32.

[![Status](https://img.shields.io/badge/status-active-success.svg)]()
[![Platform](https://img.shields.io/badge/platform-ESP32-blue.svg)]()
[![License](https://img.shields.io/badge/license-MIT-green.svg)]()

---

## 📖 O projekcie

**ShadowSkaner** to kieszonkowe, autonomiczne narzędzie do pasywnego rozpoznania elektronicznego. Urządzenie mapuje infrastrukturę sieciową i wykrywa obecność urządzeń bez pozostawiania śladów w sieci.

Projekt powstał z myślą o edukacji, testach bezpieczeństwa i badaniu infrastruktury telekomunikacyjnej w terenie.

### 🎯 Główne funkcje

- ✅ **Logowanie GPS** – zapis współrzędnych na kartę SD (format CSV)
- ⏳ **Wyświetlacz LCD** – podgląd danych na żywo *(w planach)*
- ⏳ **Skaner Wi-Fi** – mapowanie sieci bezprzewodowych *(w planach)*
- ⏳ **Skaner BLE** – wykrywanie urządzeń Bluetooth *(w planach)*
- ⏳ **Blokada RFID** – autoryzacja operatora *(w planach)*

---

## 🔧 Sprzęt

| Komponent | Model | Status |
|-----------|-------|--------|
| Mikrokontroler | ESP-WROOM-32 | ✅ |
| GPS | GY-NEO6MV2 | ✅ |
| Pamięć | Czytnik Micro SD | ✅ |
| Wyświetlacz | LCD 1602 I2C | ⏳ |
| Interfejs | Enkoder obrotowy | ⏳ |
| Autoryzacja | RFID RC522 | ⏳ |

Pełna lista części: [`docs/hardware.md`](docs/hardware.md)

---

## 🔌 Pinologia

| Moduł | PIN ESP32 |
|-------|-----------|
| GPS VCC | VIN (5V) |
| GPS TX | GPIO16 |
| GPS RX | GPIO17 |
| SD CS | GPIO5 |
| SD MOSI | GPIO23 |
| SD MISO | GPIO19 |
| SD SCK | GPIO18 |

Pełna pinologia: [`docs/pinout.md`](docs/pinout.md)

---

## 🚀 Szybki start

### Wymagania

- Arduino IDE 2.x
- Płytka: **ESP32 Dev Module**
- Biblioteki: `SD`, `SPI`, `HardwareSerial` (wbudowane)

### Instalacja

1. Sklonuj repozytorium:
   ```bash
   git clone https://github.com/crahdlinuxservers-maker/ShadowSkaner.git
