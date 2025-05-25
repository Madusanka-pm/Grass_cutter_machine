int value = 0;
#define starterRelay 7
#define emergencyRelay 8
#define relayRF 3
#define relayRB 4 
#define relayLF 5
#define relayLB 6

//Ultra Sonic

#define trig1 9
#define trig2 10
#define trig3 11
#define trig4 12
#define trig5 13
#define trig6 14
#define trig7 15
#define trig8 16

#define echo1 17
#define echo2 18
#define echo3 19
#define echo4 20
#define echo5 21
#define echo6 22
#define echo7 23
#define echo8 24


void setup() {
  
  pinMode (starterRelay, OUTPUT);
  pinMode (emergencyRelay, OUTPUT);
  pinMode (relayRF, OUTPUT); 
  pinMode (relayRB, OUTPUT); 
  pinMode (relayLF, OUTPUT); 
  pinMode (relayLB, OUTPUT); 

  pinMode(trig1,OUTPUT);
  pinMode(trig2,OUTPUT);
  pinMode(trig3,OUTPUT);
  pinMode(trig4,OUTPUT);
  pinMode(trig5,OUTPUT);
  pinMode(trig6,OUTPUT);
  pinMode(trig7,OUTPUT);
  pinMode(trig8,OUTPUT);

  pinMode(echo1,INPUT);
  pinMode(echo2,INPUT);
  pinMode(echo3,INPUT);
  pinMode(echo4,INPUT);
  pinMode(echo5,INPUT);
  pinMode(echo6,INPUT);
  pinMode(echo7,INPUT);
  pinMode(echo8,INPUT);

  Serial.begin(9600);
}

void loop() {

  if(Serial.available()){
    char serialValue = Serial.read();
    
    EmergencyStop(serialValue);
    StarterMotor(serialValue);
    Movement(serialValue);
  }  
}

void StarterMotor (char value){

  if (value == 'x'){
    
    digitalWrite (starterRelay, LOW);
    Serial.println("Starter Relay On");
  }

  if (value == 'y'){
    
    digitalWrite (starterRelay, HIGH);
    Serial.println("Starter Relay Off");
  } 
}

void EmergencyStop (char value){

  if (value == 'R'){

    digitalWrite(emergencyRelay, LOW);
    Serial.println("EMERGENCY STOP!!");   
  }
}

void Movement (char value){

  if (value == '1'){

    digitalWrite(relayRF, LOW);
    digitalWrite(relayRB, HIGH);
    digitalWrite(relayLF, LOW);
    digitalWrite(relayLB, HIGH);

    Serial.println("Forward");
     
   }
   
   if (value == '3'){

     digitalWrite(relayRF, HIGH);
     digitalWrite(relayRB, LOW);
     digitalWrite(relayLF, HIGH);
     digitalWrite(relayLB, LOW);

     Serial.println("Backword");
     
   }

    if (value == '2'){

     digitalWrite(relayRF, LOW);
     digitalWrite(relayRB, LOW);
     digitalWrite(relayLF, HIGH);
     digitalWrite(relayLB, HIGH);

     Serial.println("Righ Turn");
     
    }

    if (value == '4'){

      digitalWrite(relayRF, HIGH);
      digitalWrite(relayRB, HIGH);
      digitalWrite(relayLF, LOW);
      digitalWrite(relayLB, LOW);

      Serial.println("Left Turn");
     
    } 
}
/*
void Ultrasonic(){

  digitalWrite(trig1,LOW);
  delayMicroseconds(2);
  digitalWrite(trig1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1,LOW);

  long t1 = pulseIn(echo1,HIGH);
  long distance1 = t1/29/2;

  digitalWrite(trig2,LOW);
  delayMicroseconds(2);
  digitalWrite(trig2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2,LOW);

  long t2 = pulseIn(echo2,HIGH);
  long distance2 = t2/29/2;

  digitalWrite(trig3,LOW);
  delayMicroseconds(2);
  digitalWrite(trig3,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig3,LOW);

  long t3 = pulseIn(echo3,HIGH);
  long distance3 = t1/29/2;

  digitalWrite(trig1,LOW);
  delayMicroseconds(2);
  digitalWrite(trig1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1,LOW);

  long t1 = pulseIn(echo1,HIGH);
  long distance1 = t1/29/2;

  digitalWrite(trig1,LOW);
  delayMicroseconds(2);
  digitalWrite(trig1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1,LOW);

  long t1 = pulseIn(echo1,HIGH);
  long distance1 = t1/29/2;

  digitalWrite(trig1,LOW);
  delayMicroseconds(2);
  digitalWrite(trig1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1,LOW);

  long t1 = pulseIn(echo1,HIGH);
  long distance1 = t1/29/2;

  digitalWrite(trig1,LOW);
  delayMicroseconds(2);
  digitalWrite(trig1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1,LOW);

  long t1 = pulseIn(echo1,HIGH);
  long distance1 = t1/29/2;
  
} */
