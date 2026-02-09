# Motion-Detection-with-Arduino (Arduino + PIR + WS2812B)

![Arduino](https://img.shields.io/badge/platform-Arduino-blue)
![Language](https://img.shields.io/badge/language-C%2B%2B-orange)
![Library](https://img.shields.io/badge/library-FastLED-green)
![Status](https://img.shields.io/badge/status-working-success)

Projekt implementira **automatsko upravljanje adresabilnom LED trakom (WS2812B)** pomoću **PIR senzora pokreta**.  
LED-ice se pale **sekvencijalno (pulse efekt)** kada se detektira pokret, a gase se istim efektom nakon određenog vremena bez aktivnosti.

---

## Značajke

- Detekcija pokreta pomoću PIR senzora  
- Sekvencijalno paljenje i gašenje LED-ica  
- Automatsko gašenje nakon neaktivnosti  
- Jednostavna konfiguracija  
- Korištenje FastLED biblioteke  

---

## Potreban hardware

- Arduino (Uno / Nano / ESP8266 / ESP32*)
- PIR senzor (npr. HC-SR501)
- WS2812B LED traka
- Otpornik ~330 Ω (preporučeno)
- 5V napajanje

\* Kod je kompatibilan s većinom Arduino-kompatibilnih ploča.

---

## Kako spojiti ?

| Komponenta | Arduino Pin |
|----------|-------------|
| PIR OUT  | D2 |
| LED DATA | D4 |
| VCC (PIR & LED) | 5V |
| GND | GND |

> ⚠️ Ako koristiš veći broj LED-ica, koristi **vanjsko napajanje** za LED traku.

---

## Konfiguracija

```cpp
#define LED_PIN     4
#define NUM_LEDS    9
#define PIR_PIN     2
```

### LED postavke

```cpp
#define BRIGHTNESS  100
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
```

### Timing

```cpp
#define ON_TIME_MS  400
#define PULSE_DELAY 40
```

---

## Kako započeti?

1. Instaliraj **FastLED** biblioteku (Arduino Library Manager)
2. Spoji komponente prema tablici
3. Otvori `sketch_detekcija_pokreta.ino`
4. Podesi `NUM_LEDS`
5. Uploadaj kod

---

## Kako radi?

1. PIR senzor detektira pokret
2. Pokreće se pulse ON efekt
3. Timer se resetira svakom novom detekcijom
4. Nakon isteka vremena – pulse OFF efekt

---

## Glavne funkcionalnosti
- `pulseOnStrip()` – pali LED-ice sekvencijalno  
- `pulseOffStrip()` – gasi LED-ice sekvencijalno  
- `turnOffStripInstant()` – trenutno gasi sve LED-ice  

---

## Promjena boje na LED traci

```cpp
leds[i] = CRGB::Blue;
```

Primjeri boja:
- `CRGB::Red`
- `CRGB::Green`
- `CRGB::White`
- `CRGB(255, 100, 0)`

---

## Korištene biblioteke

- https://github.com/FastLED/FastLED

---

## Licence

Free for personal and educational use.
