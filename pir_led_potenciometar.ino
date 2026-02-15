#include <FastLED.h>

// ----- PODEŠAVANJA -----
#define LED_PIN     4      // DI s LED trake na D4
#define NUM_LEDS    6     // PROMIJENI na stvaran broj LED-ica na traci
#define PIR_PIN     2      // SIG s PIR senzora na D2
#define POT_PIN     A0     // Potenciometar na analognom pinu A0

#define BRIGHTNESS  30    // 0–255 (početna vrijednost, mijenja se potenciometrom)
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

#define ON_TIME_MS  400  // koliko dugo traka ostaje upaljena nakon zadnje detekcije 
#define PULSE_DELAY 40     // kašnjenje između paljenja pojedine LED-ice (ms)

// ----- GLOBALNE VARIJABLE -----
CRGB leds[NUM_LEDS];
unsigned long lastMotionTime = 0;
bool ledsOn = false;
int currentBrightness = BRIGHTNESS;

void setup() {
  pinMode(PIR_PIN, INPUT);
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);

  turnOffStripInstant();  // u startu sve ugašeno
}

void loop() {
  // Čitanje potenciometra i podešavanje svjetline
  int potValue = analogRead(POT_PIN);
  currentBrightness = map(potValue, 0, 1023, 0, 255);  // mapiraj 0-1023 na 0-255
  FastLED.setBrightness(currentBrightness);
  
  int pirState = digitalRead(PIR_PIN);

  // Detekcija pokreta
  if (pirState == HIGH) {
    lastMotionTime = millis();
    if (!ledsOn) {
      pulseOnStrip();   // pokreni "puls" paljenja
      ledsOn = true;
    }
  }

  // Nakon isteka vremena bez pokreta – ugasi traku
  if (ledsOn && (millis() - lastMotionTime >= ON_TIME_MS)) {
    pulseOffStrip();    // efekt gašenja (jedna po jedna gasi)
    ledsOn = false;
  }

  delay(20);
}

// ----- FUNKCIJE -----

// Puls paljenja – LED-ice se pale jedna po jedna
void pulseOnStrip() {
  // prvo sve ugasi
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();

  // zatim pali jednu po jednu
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Blue;  // promijeni boju po želji: CRGB::Red, CRGB::Blue, ...
    FastLED.show();
    delay(PULSE_DELAY);
  }
}

// Puls gašenja – LED-ice se gase jedna po jedna (od kraja prema početku)
void pulseOffStrip() {
  for (int i = NUM_LEDS - 1; i >= 0; i--) {
    leds[i] = CRGB::Black;
    FastLED.show();
    delay(PULSE_DELAY);
  }
}

// Instant gašenje (bez efekta) – koristi se samo na početku
void turnOffStripInstant() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
}