#include <FastLED.h>

// ----- PODEŠAVANJA PIN-OVA -----
#define LED_PIN     4      // DI s LED trake na D4
#define NUM_LEDS    6      // Broj LED-ica
#define PIR_PIN     2      // SIG s PIR senzora na D2
#define LDR_PIN     A0     // LDR foto-otpornik na A0
#define POT_PIN     A1     // Potenciometar na A1

// ----- POSTAVKE EFEKATA -----
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define ON_TIME_MS  3000   // Koliko dugo traka svijetli (3 sekunde)
#define PULSE_DELAY 40     // Brzina paljenja/gašenja
#define LDR_THRESHOLD 400  // Granica mraka (manje = mračnije). Podesi po potrebi!

// ----- GLOBALNE VARIJABLE -----
CRGB leds[NUM_LEDS];
unsigned long lastMotionTime = 0;
bool ledsOn = false;

void setup() {
  pinMode(PIR_PIN, INPUT);
  
  // Inicijalizacija FastLED
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  
  // Početno gašenje
  turnOffStripInstant();
  
  // Serial monitor za kalibraciju (opcionalno, otvori ga na 9600 baud)
  Serial.begin(9600);
}

void loop() {
  // 1. Čitanje senzora
  int potValue = analogRead(POT_PIN);
  int ldrValue = analogRead(LDR_PIN);
  int pirState = digitalRead(PIR_PIN);

  // Mapiranje svjetline putem potenciometra (0-255)
  int currentBrightness = map(potValue, 0, 1023, 0, 255);
  FastLED.setBrightness(currentBrightness);

  // Ispis vrijednosti u Serial Monitor (pomaže kod podešavanja osjetljivosti)
  // Serial.print("LDR: "); Serial.println(ldrValue);

  // 2. Logika paljenja: Pokret + Mrak
  if (pirState == HIGH && ldrValue < LDR_THRESHOLD) {
    lastMotionTime = millis();
    if (!ledsOn) {
      pulseOnStrip();
      ledsOn = true;
    }
  }

  // 3. Ako je upaljeno, osvježavaj svjetlinu (ako vrtiš potenciometar dok svijetli)
  if (ledsOn) {
    FastLED.show();
  }

  // 4. Logika gašenja nakon isteka vremena
  if (ledsOn && (millis() - lastMotionTime >= ON_TIME_MS)) {
    pulseOffStrip();
    ledsOn = false;
  }

  delay(20);
}

// ----- FUNKCIJE -----

void pulseOnStrip() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Blue; // Možeš staviti i CRGB::White za klasično svjetlo
    FastLED.show();
    delay(PULSE_DELAY);
  }
}

void pulseOffStrip() {
  for (int i = NUM_LEDS - 1; i >= 0; i--) {
    leds[i] = CRGB::Black;
    FastLED.show();
    delay(PULSE_DELAY);
  }
}

void turnOffStripInstant() {
  FastLED.clear();
  FastLED.show();
}
