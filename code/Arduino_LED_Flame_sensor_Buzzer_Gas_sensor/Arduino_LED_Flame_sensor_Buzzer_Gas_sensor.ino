// 4단계: 불꽃 또는 가스가 감지되면 울리는 스마트 복합 경보기

int flameSensor = 2; // 불꽃 센서: 2번 핀
int gasSensor = 3;   // 가스(연기) 센서(MQ-2): 3번 핀
int ledPin1 = 8;     // 불꽃 감지 확인용 LED: 8번 핀
int ledPin2 = 7;     // 가스 감지 확인용 LED: 7번 핀
int buzzerPin = 9;   // 피에조 부저: 9번 핀

void setup() {
  pinMode(flameSensor, INPUT);
  pinMode(gasSensor, INPUT); 
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT); 
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int fireState = digitalRead(flameSensor); 
  int gasState = digitalRead(gasSensor);    

  // 둘 다 감지된 경우 (&& 기호는 '그리고(AND)'를 의미)
  if (fireState == LOW && gasState == LOW) { 
    // 비상 작동: 두 LED 모두 깜빡이고 사이렌 울림
    digitalWrite(ledPin1, HIGH); // LED가 LOW일 때 켜진다면 LOW로 수정하세요
    digitalWrite(ledPin2, HIGH);
    tone(buzzerPin, 1000);
    delay(200); 
    
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    tone(buzzerPin, 800); 
    delay(200);
    
  } 
  // 불꽃만 감지된 경우
  else if (fireState == LOW) { 
    digitalWrite(ledPin1, HIGH); // 불꽃 LED 켜짐
    digitalWrite(ledPin2, LOW);  // 가스 LED 꺼짐
    noTone(buzzerPin);           // 부저 안 울림
  } 
  // 가스만 감지된 경우
  else if (gasState == LOW) { 
    digitalWrite(ledPin1, LOW);  // 불꽃 LED 꺼짐
    digitalWrite(ledPin2, HIGH); // 가스 LED 켜짐
    noTone(buzzerPin);           // 부저 안 울림
  } 
  // 둘 다 감지되지 않은 평상시
  else { 
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    noTone(buzzerPin);
  }
}