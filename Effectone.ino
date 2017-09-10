/**
 * @file ZeldaEffectone
 * @brief When the door open, sound a effect
 * @author Ryota ADACHI
 */
#define BUZZER_PIN 3
#define LED_PIN 13
#define SWITCH_PIN 14

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
  pinMode(LED_PIN, OUTPUT);
}

/**
 * @brief Main loop
 */
void loop() {
  if ( State == CLOSE && digitalRead(SWITCH_PIN) == HIGH) {
    // LED ON
    digitalWrite(LED_PIN, HIGH);

    // Sound Effect
    EffectZelda(BUZZER_PIN, 150);

    // LED OFF
    digitalWrite(LED_PIN, LOW);

    // State -> OPEN
    State = OPEN;
  }
  else if ( State == OPEN && digitalRead(SWITCH_PIN) == LOW) {
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
