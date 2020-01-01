#define A 11

int order = 3;
int disorder = 5;
int echoPin = 12;
int trigPin = 11;
int hand_sensor =  A0;
int tower_sensor = A1;

float len;
float r;
int hand;
int tower;
int spd = 80;
float duration, distance;
float ttheta;

void setup() {
  pinMode(hand_sensor,INPUT);
  pinMode(tower_sensor,INPUT);  
  pinMode(order, OUTPUT);
  pinMode(disorder, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(order, LOW);  
  digitalWrite(disorder, LOW);
  Serial.begin(9600);
}

void loop() {
  tower = analogRead(tower_sensor);
  Serial.println(tower);
  /*
  hand = analogRead(hand_sensor);  
  len = dist();
  r = A-len;
  ttheta = (55/r)*(180/3.141592);
  
  Serial.print("hand : ");
  Serial.print(hand);
  Serial.print("  dist : ");
  Serial.print(len);
  Serial.print("   r : ");
  Serial.print(r);
  Serial.print("   @ : ");
  Serial.print(ttheta);
  Serial.print("   paper : ");
  Serial.println((r*ttheta)*(3.141592/180));
  if(hand<700){
    //ttheta = (55/(A-len))*(180/3.141592);
    //roll(ttheta,0);
  }
  */
  delay(500);
}

float dist(){
  
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance = ((float)(340 * duration) / 10000) / 2;  
  delay(10);
  return(distance);
}


void roll(float degree,int way){
  
  int t = degree/20;
  Serial.print("dgree : ");
  Serial.println(t);
  if(way==0){
   for(int k = 0; k<t; k++){
    analogWrite(order, spd);
    analogWrite(disorder, 0);
    delay(90);
    analogWrite(order,0);
    analogWrite(disorder,0);
    delay(5);
    }
  }
  else{
    for(int k = 0; k<t; k = k+20){
    analogWrite(disorder, spd+30);
    analogWrite(order, 0);
    delay(90);
    analogWrite(order,0);
    analogWrite(disorder,0);
    }
  }
  delay(100);
  
}
