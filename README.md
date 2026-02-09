## Automatsko upravljanje LED trakom pomoću PIR senzora (Arduino)

Ovaj projekt prikazuje jednostavan **pametni sustav rasvjete** temeljen na **Arduino mikroupravljaču**, **PIR senzoru pokreta** i **adresabilnoj LED traci** (npr. WS2812B).  
Sustav detektira pokret pomoću PIR senzora te u tom slučaju pali LED traku koristeći **sekvencijalni “pulse” efekt** (LED-ice se pale jedna po jedna). Nakon što prođe definirano vrijeme bez nove detekcije pokreta, LED-ice se gase istim efektom, ali obrnutim redoslijedom.

Projekt je prikladan kao **uvodni primjer rada s ugrađenim sustavima**, senzorima i adresabilnom rasvjetom, ali i kao osnova za **kućnu automatizaciju**.

---

## Značajke

- Automatsko paljenje rasvjete pri detekciji pokreta  
- Puls efekt paljenja i gašenja LED-ica  
- Praćenje vremena bez blokiranja programa (`millis()`)  
- Podesivo vrijeme svijetljenja nakon zadnje detekcije  
- Podesiva brzina efekta (pulse delay)    
- Jednostavna nadogradnja sustava  

---

## Hardver

### Potrebne komponente

- Arduino (npr. Arduino Uno, Nano ili kompatibilan)
- PIR senzor pokreta (npr. HC-SR501)
- Adresabilna LED traka (npr. WS2812B / NeoPixel)
- Izvor napajanja 5 V
- Jumper žice, po potrebi breadboard

---

### Shema spajanja

**LED traka**
- 5V → 5V napajanja  
- GND → GND Arduina  
- DI → D4  

**PIR senzor**
- VCC → 5V  
- GND → GND  
- SIG → D2  

> Napomena: Kod većeg broja LED-ica preporučuje se zasebno 5 V napajanje uz zajednički GND.

---

## Softver i ovisnosti

- Arduino IDE  
- Arduino board paket  
- FastLED biblioteka (instalacija preko Library Managera)

---

## Arduino kod – osnovna ideja

Program koristi PIR senzor za detekciju pokreta i FastLED biblioteku za upravljanje LED trakom. Stanje sustava prati se pomoću varijable `ledsOn`, a vrijeme se mjeri funkcijom `millis()`.

---

## Ključne konstante

```cpp
#define LED_PIN     4
#define NUM_LEDS    9
#define PIR_PIN     2

#define BRIGHTNESS  100
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

#define ON_TIME_MS  400
#define PULSE_DELAY 40
```

---

## Objašnjenje rada

- Detekcija pokreta aktivira pulse efekt paljenja
- Svaka nova detekcija resetira timer
- Nakon isteka vremena bez pokreta aktivira se pulse efekt gašenja
- Sustav se vraća u stanje čekanja

---

## Funkcije

- `pulseOnStrip()` – sekvencijalno pali LED-ice  
- `pulseOffStrip()` – sekvencijalno gasi LED-ice  
- `turnOffStripInstant()` – trenutno gasi sve LED-ice  

---

## Konfiguracija

Moguće je prilagoditi:
- broj LED-ica
- svjetlinu
- vrijeme automatskog gašenja
- brzinu pulse efekta
- boju LED-ica

---

## Kako pokrenuti projekt

1. Preuzmi repozitorij  
2. Otvori `.ino` datoteku u Arduino IDE-u  
3. Odaberi pločicu i port  
4. Učitaj kod  
5. Spoji hardver  

---

## Moguća proširenja

- LDR senzor (paljenje samo u mraku)
- Wi-Fi povezivanje (ESP8266 / ESP32)
- Dodatni svjetlosni efekti
- Web ili serijska konfiguracija

---

## Napomena

Projekt je izrađen u edukacijske svrhe.
