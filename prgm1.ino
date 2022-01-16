
#include <Servo.h> 

// Declare the Servo pin 
int servoPin =3 ;
int servopin1=4 ; 
int inputp=6;
int inputp1=7;
int TRIG=1;
int ECHO=2;
int Empty;
int allSpace=10;
int countYes=0;
long distance,duration;
// Create a servo object 
Servo Servo1;
Servo Servo2; 

void setup() {
  // put your setup code here, to run once:
pinMode(inputp, INPUT);
Serial.begin(9600); 
 Servo1.attach(servoPin);
 Servo2.attach(servopin1);
 pinMode(TRIG,OUTPUT);
 pinMode(ECHO,INPUT); 
}
void loop() {
  while(1)
  {
  digitalWrite(TRIG,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW);
  duration=pulseIn(ECHO,HIGH);
  distance=(duration/2)/29;
  Serial.print("Centimeter:");
  Serial.println(distance);
  int irdetect=digitalRead(inputp);
  if (irdetect==0)
  {
    Servo1.write(90);
    Serial.print("input gate open");
    Serial.println("\n");
    delay(1000);
    
    
  }
  else
  {
  Servo1.write(0);
  Serial.print("inputgate close");
  Serial.println("\n");
    delay(1000);
  }
  int irdetect1=digitalRead(inputp1);
  if (irdetect1==0)
  {
    Servo2.write(90);
    Serial.print("exit gate open");
    Serial.println("\n");
    delay(1000);
    
    countYes=countYes-1;
    Empty=allSpace-countYes;
    
  }
  else
  {
  Servo2.write(0);
  Serial.print("exit gate close");
  Serial.println("\n");
    delay(1000);
  }
  if(distance<100)
  {
    Serial.println("slotisoccupied: ");
    Serial.println("\n");
    countYes=countYes+1;
    Empty=allSpace-countYes;
  
  }
 else if(distance>100)
  {
    Serial.println("slotisnotoccupied:");
    Serial.println("\t");
    //countYes=countYes-1;
    //Empty=allSpace-countYes;
  //delay(1000);
  }
  Serial.print("available_Slots");
  Serial.println("\t");
  Serial.println(Empty);
  //delay(1000);
  }
}
