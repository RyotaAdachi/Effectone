/**
 * @file ZeldaEffectone
 * @brief When the door open, sound a effect
 * @author Ryota ADACHI
 */
#define BUZZER_PIN 3
#define LED_PIN 13
#define SWITCH_PIN 11
#define SWITCH_PIN_REF 12

enum state {
  CLOSE,
  OPEN
} StateTypedef;

state State = CLOSE;

/**
 * @brief Init
 */
void setup() {
  pinMode(SWITCH_PIN, INPUT);
  pinMode(SWITCH_PIN_REF, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(SWITCH_PIN_REF, HIGH);
}

/**
 * @brief Main loop
 */
void loop() {
  digitalWrite(LED_PIN, digitalRead(SWITCH_PIN));
  if ( State == CLOSE && digitalRead(SWITCH_PIN) == LOW) {
    // Sound Effect
    EffectZelda(BUZZER_PIN, 170);

    // State -> OPEN
    State = OPEN;
  }
  else if ( State == OPEN && digitalRead(SWITCH_PIN) == HIGH) {
    // State -> CLOSE
    State = CLOSE;
  }
  delay(100);
}

/**
 * @brief Effect Zelda
 */
void EffectZelda(int pin, int beat) {
  tone(pin, 802); // ソ
  delay(beat);
  tone(pin, 747); // ♯ファ
  delay(beat);
  tone(pin, 639); // ♯レ
  delay(beat);
  tone(pin, 445); // ラ
  delay(beat);
  tone(pin, 416); // ♯ソ
  delay(beat);
  tone(pin, 668); // ミ
  delay(beat);
  tone(pin, 848); // ♯ソ
  delay(beat);
  tone(pin, 1076); // ド
  delay(beat);
  noTone(pin);    // 音を止める
}
