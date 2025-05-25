int value = 0;
#define StarterRelay 3 //Starter Relay Pin
#define EmergencyRelay 4 // Emergency Relay pin

void setup() {

  pinMode (StarterRelay, OUTPUT); 
  pinMode (2, INPUT); //test
  Serial.begin(9600);

}

void loop() {

  if(Serial.available()){
    char SerialValue = Serial.read();
    
    EmergencyStop(SerialValue);
    StarterMotor(SerialValue);
  }
}

void StarterMotor (char value){

  if (value == 'x'){
    
    digitalWrite (StarterRelay, HIGH);
    Serial.println("RelayOn");
  }

  if (value == 'y'){
    
    digitalWrite (StarterRelay, LOW);
    Serial.println("RelayOff");
  } 
}

void EmergencyStop (char value){

  if (value == 'R'){

    digitalWrite(EmergencyRelay, HIGH);
    Serial.println("EMERGENCY STOP!!");   
  }
}
