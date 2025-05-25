int relay1 = 5;  // Relay 1 (controls motor 1 plus trarminal)
int relay2 = 6;  //Relay 2 (controls motor 1 plus trarminal)

int relay4 = 7;  // Relay 3 (controls motor 2 plus trarminal)
int relay3 = 8;  // Relay 4 (controls motor 3 negative trarminal)


void setup() {

pinMode(relay4,OUTPUT);
pinMode(relay3,OUTPUT);
pinMode(relay1,OUTPUT);
pinMode(relay2,OUTPUT);

Serial.begin(9600);

digitalWrite(relay1,HIGH);
digitalWrite(relay2,HIGH);
digitalWrite(relay3,HIGH);
digitalWrite(relay4,HIGH);

}

void loop() {

if (Serial.available()){

  char x=Serial.read();

  if(x=='1'){
    forward();
  }

 else if(x=='2'){

    backword();
 }

 else if(x=='3'){

    stop_car();
 }
  
}

}

void forward(){

  digitalWrite(relay2,LOW);
  digitalWrite(relay1,HIGH);
  
  digitalWrite(relay4,LOW);
  digitalWrite(relay3,HIGH);
}

void backword(){

   digitalWrite(relay2,HIGH);
   digitalWrite(relay1,LOW);
  
   digitalWrite(relay4,HIGH);
   digitalWrite(relay3,LOW);
}

void stop_car(){

   digitalWrite(relay2,HIGH);
   digitalWrite(relay1,HIGH);
  
   digitalWrite(relay4,HIGH);
   digitalWrite(relay3,HIGH);
}
