// 2단계: 불꽃을 감지하면 경광등 켜기

int flameSensor = 2; // 불꽃 센서를 2번 핀에 연결 (디지털 핀)
int ledPin = 8;      // LED를 8번 핀에 연결

void setup() {
  pinMode(flameSensor, INPUT); // 불꽃 센서는 신호를 받아들이는 '입력'
  pinMode(ledPin, OUTPUT);     // LED는 신호를 내보내는 '출력'
  Serial.begin(9600);          // 컴퓨터 화면으로 상태를 확인하기 위한 통신 시작
}

void loop() {
  int fireState = digitalRead(flameSensor); // 불꽃 센서의 상태를 읽어서 fireState에 저장

  // 만약(if) 불꽃이 감지되었다면 (HIGH 신호가 들어오면)
  if (fireState == LOW) { 
    Serial.println("🔥 화재 발생! (불꽃 감지)");
    digitalWrite(ledPin, HIGH); // LED 켜기
  } 
  // 그렇지 않으면 (불꽃이 없다면)
  else { 
    Serial.println("안전 상태");
    digitalWrite(ledPin, LOW);  // LED 끄기
  }
  delay(200); // 0.2초마다 확인
}