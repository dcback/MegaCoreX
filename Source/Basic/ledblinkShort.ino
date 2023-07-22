#define ledPin 7              // MCU 7번 Pin을 LED구동 핀으로 정의한 후  

void setup() {
  pinMode(ledPin, OUTPUT);    // 이 핀을 출력으로 최초 실행 시 정의한 다음
}

void loop() {  // LED구동 핀을 로직(H/L)을 바꾸면서 1초 단위로 반복적으로 켜고 끈다.
  digitalWrite(ledPin, !digitalRead(ledPin));
  delay(1000);
}
