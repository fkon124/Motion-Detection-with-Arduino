## Automatsko upravljanje LED trakom pomoću PIR senzora (Arduino)

Ovaj projekt prikazuje jednostavan **pametni sustav rasvjete** temeljen na **Arduino** mikroupravljaču, **PIR senzoru pokreta** i **adresabilnoj LED traci** (npr. WS2812B).  
Sustav detektira pokret pomoću PIR senzora i tada pali LED traku s efektom „pulsa” (LED-ice se pale jedna po jedna). Nakon određenog vremena bez pokreta, LED-ice se gase istim efektom.

Projekt je idealan kao uvod u **ugrađene sustave** i **kućnu automatizaciju**.

---

## Značajke

- **Automatsko paljenje rasvjete** pri detekciji pokreta
- **Puls efekt** – LED-ice se pale/gase jedna po jedna
- **Podesivo vrijeme svijetljenja** nakon zadnje detekcije pokreta
- **Podesiva brzina efekta** (brži/sporiji „puls”)
- Jednostavna nadogradnja (npr. senzor svjetla, Wi-Fi, dodatne scene rasvjete)

---

## Hardver

Potrebne komponente:

- Arduino (npr. **Arduino Uno**, Nano ili kompatibilan)
- **PIR senzor pokreta** (npr. HC‑SR501 ili sličan)
- **Adresabilna LED traka** (npr. WS2812B / „NeoPixel”)
- Izvor napajanja 5 V (ovisno o broju LED‑ica)
- Povezivanje žicama (jumper wires), po želji breadboard

### Shema spajanja

- **LED traka**
  - `5V` LED trake → `5V` napajanja (po potrebi eksterno, s GND zajedničkim s Arduinom)
  - `GND` LED trake → `GND` Arduina
  - `DI` (Data In) LED trake → **D4** na Arduinu

- **PIR senzor**
  - `VCC` PIR senzora → `5V` Arduina (ili prema specifikaciji senzora)
  - `GND` PIR senzora → `GND` Arduina
  - `SIG` (signal) PIR senzora → **D2** na Arduinu

> Napomena: Ako koristiš veću LED traku (puno LED‑ica), preporučuje se **posebno 5 V napajanje** za LED traku, uz zajednički GND s Arduinom.

---

## Softver i ovisnosti

- **Arduino IDE** (preporučeno zadnja verzija)  
  `https://www.arduino.cc/en/software`
- Arduino board paket za tvoju pločicu (npr. „Arduino AVR Boards” za Uno/Nano)
- Biblioteka **FastLED**:
  - Arduino IDE → **Sketch → Include Library → Manage Libraries…**
  - pretraži **“FastLED”** i instaliraj

---

## Arduino kod

Kod koji očekuje ovaj README temelji se na sljedećim postavkama:

- LED traka na pinu **D4**
- PIR senzor na pinu **D2**
- Adresabilna LED traka tipa **WS2812B**
- Efekt: „puls” (LED‑ice se pale/gase redom)

U projekt dodaj `.ino` datoteku i u nju kopiraj kod koji smo ranije definirali (ili svoju prilagođenu verziju).

Ključne konstante u kodu (primjer):

```cpp
#define LED_PIN     4      // DI s LED trake na D4
#define NUM_LEDS    9     // PROMIJENI na stvaran broj LED-ica na traci
#define PIR_PIN     2      // SIG s PIR senzora na D2

#define BRIGHTNESS  100    // 0–255
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

#define ON_TIME_MS  400  // koliko dugo traka ostaje upaljena nakon zadnje detekcije (10 s)
#define PULSE_DELAY 40     // kašnjenje između paljenja pojedine LED-ice (ms)

```

---

## Konfiguracija

U Arduino kodu možeš prilagoditi:

- **`NUM_LEDS`** – stvarni broj LED‑ica na tvojoj LED traci
- **`BRIGHTNESS`** – ukupni intenzitet rasvjete (0–255)
- **`ON_TIME_MS`** – koliko dugo LED‑ice ostaju upaljene nakon zadnje detekcije pokreta
- **`PULSE_DELAY`** – brzina „pulsa” (manje = brže, veće = sporije)
- Boju LED‑ica (u funkciji za paljenje trake), npr.:

```cpp
leds[i] = CRGB::Blue;   // možeš staviti CRGB::Red, CRGB::White, CRGB(0, 255, 0), ...
```

---

## Kako pokrenuti projekt

1. **Kloniraj ili preuzmi** ovaj repozitorij.
2. Otvori **Arduino IDE** i učitaj `.ino` datoteku s kodom.
3. U izborniku **Tools → Board** odaberi svoju Arduino pločicu.
4. U **Tools → Port** odaberi odgovarajući COM port.
5. Klikni **Verify** (✔) za kompilaciju, zatim **Upload** (→) za slanje koda na Arduino.
6. Spoji hardver prema shemi spajanja i napajaj sustav.

Kada PIR senzor detektira pokret, LED traka će se upaliti efektom „pulsa”. Ako nema pokreta određeno vrijeme (`ON_TIME_MS`), LED‑ice će se postupno ugasiti.

---

## Moguća proširenja

- Dodavanje **LDR (senzor svjetla)** tako da se rasvjeta pali samo u mraku
- Dodavanje **Wi‑Fi** (npr. ESP8266/ESP32) i web sučelja za konfiguraciju parametara
- Više efekata rasvjete (npr. „theater chase”, „rainbow”, različite scene)
- Ugradnja sustava u stvarni prostor (hodnik, stepenište, ormarić, radni stol)

---

## Napomena
- Ovaj projekt napravljen je za edukacijske svrhe



