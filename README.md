# Pametna LED rasvjeta s PIR senzorom, LDR-om i potenciometrom (Arduino)

Ovaj projekt prikazuje napredniji sustav **automatske LED rasvjete** temeljen na **Arduino** mikroupravljaču, **PIR senzoru pokreta**, **LDR senzoru svjetla**, **potenciometru** i **adresabilnoj LED traci** (WS2812B / NeoPixel).

Sustav automatski pali LED traku kada:

* PIR senzor detektira pokret
* prostorija je dovoljno tamna (LDR)

Svjetlina LED trake može se ručno podešavati pomoću potenciometra, a LED-ice se pale i gase elegantnim „pulse” efektom.

Projekt je idealan kao uvod u:

* ugrađene sustave (embedded systems)
* pametnu rasvjetu
* kućnu automatizaciju
* rad sa senzorima i adresabilnim LED trakama

---

# Značajke

* Automatsko paljenje LED rasvjete pri detekciji pokreta
* Rasvjeta radi samo u mraku pomoću LDR senzora
* Podesiva svjetlina pomoću potenciometra
* „Pulse” efekt paljenja i gašenja LED-ica
* Automatsko gašenje nakon određenog vremena bez pokreta
* Jednostavna nadogradnja za Wi-Fi, dodatne efekte i pametne funkcije

---

# Hardver

Potrebne komponente:

* Arduino Uno / Nano / kompatibilna pločica
* PIR senzor pokreta (npr. HC-SR501)
* WS2812B / NeoPixel adresabilna LED traka
* LDR fotootpornik
* Potenciometar (10k preporučeno)
* Otpornik za LDR (npr. 10kΩ)
* 5 V napajanje
* Jumper žice i po želji breadboard

---

# Shema spajanja

## LED traka

* `5V` → 5V napajanje
* `GND` → GND Arduina
* `DI` → D4 na Arduinu

## PIR senzor

* `VCC` → 5V
* `GND` → GND
* `SIG` → D2

## LDR senzor

* Jedan kraj LDR-a → 5V
* Drugi kraj → A0 i otpornik prema GND

## Potenciometar

* Jedan kraj → 5V
* Drugi kraj → GND
* Srednji pin → A1

> Napomena: Kod većeg broja LED-ica preporučuje se zasebno 5 V napajanje za LED traku uz zajednički GND s Arduinom.

---

# Softver i ovisnosti

Potrebno:

* Arduino IDE
  `https://www.arduino.cc/en/software`

* Biblioteka **FastLED**

  * Arduino IDE → `Sketch → Include Library → Manage Libraries`
  * pretraži `"FastLED"` i instaliraj biblioteku

---

# Arduino kod

Projekt koristi sljedeće pinove i postavke:

```cpp
#define LED_PIN     4
#define NUM_LEDS    6
#define PIR_PIN     2
#define LDR_PIN     A0
#define POT_PIN     A1
```

Ključne postavke efekata:

```cpp
#define ON_TIME_MS   3000
#define PULSE_DELAY  40
#define LDR_THRESHOLD 400
```

---

# Kako sustav radi

1. PIR senzor detektira pokret
2. LDR provjerava je li prostor dovoljno taman
3. Ako su oba uvjeta zadovoljena:

   * LED traka se pali „pulse” efektom
4. Potenciometar određuje svjetlinu LED-ica u stvarnom vremenu
5. Nakon isteka vremena bez pokreta:

   * LED traka se postupno gasi

---

# Konfiguracija

U kodu možeš prilagoditi:

| Konstanta       | Opis                                          |
| --------------- | --------------------------------------------- |
| `NUM_LEDS`      | broj LED-ica                                  |
| `ON_TIME_MS`    | vrijeme svijetljenja nakon pokreta            |
| `PULSE_DELAY`   | brzina efekta                                 |
| `LDR_THRESHOLD` | osjetljivost na mrak                          |
| boju LED-ica    | npr. `CRGB::Blue`, `CRGB::White`, `CRGB::Red` |

Primjer promjene boje:

```cpp
leds[i] = CRGB::White;
```

---

# Podešavanje LDR senzora

Za pravilno podešavanje granice mraka koristi `Serial Monitor`.

U kodu odkomentiraj:

```cpp
// Serial.print("LDR: "); Serial.println(ldrValue);
```

Zatim prati vrijednosti senzora i prilagodi:

```cpp
#define LDR_THRESHOLD 400
```

Manja vrijednost = potrebno je više mraka za paljenje.

---

# Kako pokrenuti projekt

1. Kloniraj ili preuzmi repozitorij
2. Otvori `.ino` datoteku u Arduino IDE-u
3. Instaliraj FastLED biblioteku
4. Odaberi svoju Arduino pločicu u:

   * `Tools → Board`
5. Odaberi COM port:

   * `Tools → Port`
6. Klikni:

   * `Verify`
   * `Upload`
7. Spoji hardver prema shemi

Nakon uploadanja sustav će automatski raditi.

---

# Moguća proširenja

* ESP8266 / ESP32 Wi-Fi kontrola
* Web sučelje za podešavanje
* RGB animacije i scene
* Reakcija na glazbu
* OLED zaslon za prikaz senzora
* Upravljanje preko mobilne aplikacije
* Integracija sa smart home sustavima

---

# Napomena

* Projekt je izrađen u edukacijske svrhe.
* Vrijednosti senzora mogu varirati ovisno o komponentama i osvjetljenju prostora.
* Za veće LED trake koristi zasebno napajanje dovoljne snage.
