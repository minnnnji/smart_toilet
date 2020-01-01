int led =  13;
int sw = 7;
int button;

void setup() {
  pinMode(sw, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  button = digitalRead(sw);
  Serial.println(button);
  delay(300);
}

//2
#include <Servo.h>

Servo motor2;

int sw = 7;
int sen = A0;
int led = 13;
int ant = 5;


int angle;
int slw;
int i;
int d = 0;
int n = 0;
int one = 0;
void doorclose(){
  if (angle != 120){
    Serial.println("close");
    for (i=0;i<=120;i++){
      motor2.write(i);
      delay(15);
    }
    angle = 120;
  }
}


void setup() {
  
  Serial.begin(9600);
  pinMode(13,OUTPUT); //LED연결 13번 핀 출력
  pinMode(A0,INPUT); // 센서 연결 A0핀 입력
  pinMode(ant,OUTPUT);
  pinMode(sw,INPUT_PULLUP);
  digitalWrite(13,0);
  motor2.attach(9);
  
}

void loop() {
  int data = analogRead(A0); // 센서의 입력값을 data변수에 저장
  slw=digitalRead(sw);
  
  if (slw==1){
    Serial.println("not Sit");
    if (data <= 300 && data >= 100){ // 측정값이 물 100가 아니면
      digitalWrite(13,LOW);
      Serial.print(data);
      Serial.println(" Clean!");
      dooropen();
    }
    else {
      digitalWrite(13, HIGH); // LED에 HIGH출력
      Serial.print(data);
      Serial.println(" Dirty!");
      doorclose();
    }
    d = 0;
    n = 0;
    delay(1000);
  }
  else{
    Serial.print("Sit ");
    Serial.print("  time : ");
    Serial.print(d);
    Serial.print("  DDong : ");
    Serial.print(n);
    Serial.print("  dirt clea : ");
    Serial.print(data);
    if(data>300){
      Serial.println("  Drity!");
    }
    else{
      Serial.println("  Clean!");
    }
    
    if(d>=10&&n>=1){//앉은지 5초 && 물이 더러움
      Serial.println(" ");
      Serial.println("papper tower");
      Serial.println(" ");
      digitalWrite(ant,HIGH);//변기에 전송
      delay(100);
      digitalWrite(ant,LOW);
    }
    if(analogRead(A0) >300){
      n = 1;
    }
    d++;    
    delay(1000);
  }
}


void dooropen(){
  if (angle != 0){
    Serial.println("open");
    for (i=120;i>=0;i--){
      motor2.write(i);
      delay(15);
    }
    angle=0;
  }
}
