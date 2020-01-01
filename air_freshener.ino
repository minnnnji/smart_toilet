int a;
int sen = A1;
int mot = 3;
int sr = 130;


void setup(){
  pinMode(sen,INPUT);
  pinMode(10, OUTPUT);
  pinMode(mot,OUTPUT);

  
  Serial.begin(9600);                            // sets serial port to 9600
}
 
void loop(){
  a = analogRead(sen);       // read analog input pin 0
  Serial.print("AirQua=");
  Serial.print(a, DEC);               // prints the value read
  Serial.println(" PPM");
  if(a<sr-50){
    digitalWrite(mot,LOW);
  }
  else if (a >= sr-50) {
    digitalWrite(mot,HIGH);
  }
  if (a>= sr){
     Serial.println("MOTOR");
     digitalWrite(10, HIGH);
     delay(200);
     digitalWrite(10,LOW);    
     delay(50000);
  }
  
  delay(1000);                                   // wait 100ms for next reading
}
