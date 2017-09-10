/**
 * @file ZeldaEffectone
 * @brief When the door open, sound a effect
 * @author Ryota ADACHI
 */

enum state {
  CLOSE,
  OPEN
} StateTypedef;

state State = CLOSE;

/**
 * @brief Init
 */
void setup() {
  pinMode(14, INPUT);
  pinMode(13, OUTPUT);
}

/**
 * @brief Main loop
 */
void loop() {
  if ( State == CLOSE && digitalRead(14) == HIGH) {
    digitalWrite(13, HIGH);
    EffectZelda(3, 150);
    digitalWrite(13, LOW);
    State = OPEN;
  }
  else if ( State == OPEN && digitalRead(14) == LOW) {
    State = CLOSE;
  }
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
