// 3단계: 불꽃 감지 시 경광등과 사이렌(부저) 동시 작동

int flameSensor = 2; // 불꽃 센서: 2번 핀
int ledPin = 8;      // LED: 8번 핀
int buzzerPin = 9;   // 피에조 부저: 9번 핀

void setup() {
  pinMode(flameSensor, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT); // 부저도 소리를 내보내는 '출력'
}

void loop() {
  int fireState = digitalRead(flameSensor);

  if (fireState == LOW) { // 불꽃이 감지되면
    // 대피를 알리는 시청각 경보 작동!
    digitalWrite(ledPin, HIGH);   // 경광등 ON
    tone(buzzerPin, 1000);        // 1000Hz 높이의 삐~ 소리 출력
  } else {                 // 평상시에는
    digitalWrite(ledPin, LOW);    // 경광등 OFF
    noTone(buzzerPin);            // 부저 소리 끄기
  }
  delay(100);
}