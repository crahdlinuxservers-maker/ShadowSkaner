# 🛠️ Lista części (Bill of Materials)

## Podstawowe komponenty

| Komponent | Model | Ilość | Status |
|-----------|-------|-------|--------|
| Mikrokontroler | ESP-WROOM-32 | 1 | ✅ |
| GPS | GY-NEO6MV2 z anteną | 1 | ✅ |
| Czytnik kart | Micro SD SPI | 1 | ✅ |
| Karta pamięci | Micro SD 16GB FAT32 | 1 | ✅ |

## Planowane rozszerzenia

| Komponent | Model | Ilość |
|-----------|-------|-------|
| Wyświetlacz | LCD 1602 z konwerterem I2C | 1 |
| Enkoder | Obrotowy z przyciskiem (KY-040) | 1 |
| RFID | RC522 + karta/brelok | 1 |
| Baterie | 18650 | 2 |
| Ładowarka | TP4056 | 1 |
| Przetwornica step-up | MT3608 | 1 |
| Przetwornica step-down | MP1584 | 1 |
| Przełącznik | Suwakowy | 1 |

## Zasilanie

- **Baterie:** 2× 18650 (równolegle)
- **Ładowanie:** TP4056 przez USB
- **Step-up:** MT3608 → 5V dla GPS
- **Step-down:** MP1584 → 3.3V dla ESP32 i modułów
