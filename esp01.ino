#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

// Firebase settings
#define FIREBASE_HOST "flutter-app-3953f-default-rtdb.asia-southeast1.firebasedatabase.app"  // Replace with your Firebase Database URL
#define FIREBASE_AUTH "UXxXvVzURyDwsO3Ow698ND5b8x5HZOVGTHa7noTh"  // Replace with your Firebase Database secret or authentication token

// WiFi settings
const char* ssid = "Pasindu 21s";  // Replace with your Wi-Fi SSID
const char* password = "PMSN20#03";  // Replace with your Wi-Fi password

// Firebase objects
FirebaseData firebaseData;          // Firebase data object
FirebaseAuth auth;                  // Firebase authentication object
FirebaseConfig config;              // Firebase configuration object

// Paths
String path_x = "/joystickData/x";
String path_y = "/joystickData/y";
String path_slider = "/slider";
String path_button_01 = "/emergency_state";
String path_button_02 = "/motor_state";



float y;
float x;

void setup() {
  Serial.begin(9600);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Connected to Wi-Fi!");

  // Firebase configuration
  config.host = FIREBASE_HOST;
  config.signer.tokens.legacy_token = FIREBASE_AUTH;

  // Initialize Firebase
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
  Serial.println("Firebase initialized!");
}

void loop() {
  if (Firebase.ready()) {
    // Reading X value
    if (Firebase.getFloat(firebaseData, path_x)) {
      x = firebaseData.floatData();
      //Serial.print("X: ");
      //Serial.println(x);
    } else {
      Serial.print("Error reading X: ");
      Serial.println(firebaseData.errorReason());
    }

    // Reading Y value
    if (Firebase.getFloat(firebaseData, path_y)) {
      y = firebaseData.floatData();
     // Serial.print("Y: ");
      //Serial.println(y);
    } else {
      Serial.print("Error reading Y: ");
      Serial.println(firebaseData.errorReason());
    }

    if(y < 0 && x > 0){
    Serial.println("FORWARD");
    }

    else if(y > 0 && x > 0){
    Serial.println("RIGHTSIDE");
    }

    else if(y < 0 && x < 0){
    Serial.println("LEFTSIZE");
    }

    else if(y > 0 && x < 0){
    Serial.println("BLACKWARD");
    }

    // Reading slider value
    if (Firebase.getFloat(firebaseData, path_slider)) {
      float sliderValue = firebaseData.floatData();
      //Serial.print("Slider Value: ");
      Serial.println(sliderValue);
    } else {
      Serial.print("Error reading Slider: ");
      Serial.println(firebaseData.errorReason());
    }

    // Reading emergebcy button value
    if (Firebase.getString(firebaseData, path_button_01)) {
      String Emer_buttonValue = firebaseData.stringData();
      //Serial.print("Button Value: ");
      Serial.println(Emer_buttonValue);
    } else {
      Serial.print("Error reading Button: ");
      Serial.println(firebaseData.errorReason());
    }

    if (Firebase.getString(firebaseData, path_button_02)) {
      String motor_buttonValue = firebaseData.stringData();
      //Serial.print("Button Value: ");
      Serial.println(motor_buttonValue);
    } else {
      Serial.print("Error reading Button: ");
      Serial.println(firebaseData.errorReason());
    }
  }

  delay(1000);  // Adjust delay as necessary
}
