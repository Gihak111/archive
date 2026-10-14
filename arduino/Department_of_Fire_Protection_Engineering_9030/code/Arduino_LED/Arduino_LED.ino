// 1단계: 소방차 경광등 (LED 깜빡이기)

int ledPin = 8; // LED를 아두이노 8번 핀에 연결합니다.

void setup() {
  pinMode(ledPin, OUTPUT); // 8번 핀을 출력(전기를 내보내는) 역할로 설정합니다.
}

void loop() {
  digitalWrite(ledPin, HIGH); // LED 켜기 (불빛 ON)
  delay(500);                 // 0.5초(500밀리초) 동안 기다리기
  digitalWrite(ledPin, LOW);  // LED 끄기 (불빛 OFF)
  delay(500);                 // 0.5초 동안 기다리기
}