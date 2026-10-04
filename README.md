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

Sklonuj repozytorium:

`git clone https://github.com/crahdlinuxservers-maker/ShadowSkaner.git`

Następnie otwórz plik `src/ShadowSkaner.ino` w Arduino IDE, wybierz płytkę **ESP32 Dev Module** oraz odpowiedni port COM, wgraj kod i otwórz **Serial Monitor** z prędkością 115200 baud.

### Format danych wyjściowych

Plik `shadow.csv` na karcie SD ma następującą strukturę:

`czas,lat,lon,sats,alt`

`205118,50.981343,18.217873,05,184.9`

`205119,50.981342,18.217868,05,184.6`

---

## 📊 Status projektu

| Moduł | Status |
|-------|--------|
| GPS → SD | ✅ działa |
| LCD | ⏳ planowane |
| Enkoder | ⏳ planowane |
| RFID | ⏳ planowane |
| Wi-Fi scanner | ⏳ planowane |
| BLE scanner | ⏳ planowane |

Ostatnia aktualizacja: **październik 2026**

---

## ⚠️ Zastrzeżenie

Projekt służy **wyłącznie do celów edukacyjnych** i **testów własnej infrastruktury**. Autor nie ponosi odpowiedzialności za użycie urządzenia w sposób niezgodny z prawem.

**Nie używaj tego narzędzia do:**

- Śledzenia osób bez ich zgody
- Nieautoryzowanego dostępu do sieci
- Działań szpiegowskich

---

## 👤 Autor

**Stanisław Kozioł**

- GitHub: [@crahdlinuxservers-maker](https://github.com/crahdlinuxservers-maker)
- Email: crahdlinuxservers@gmail.com

---

## 📜 Licencja

Projekt na licencji **MIT** – szczegóły w pliku [LICENSE](LICENSE).
