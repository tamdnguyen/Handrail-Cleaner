// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Re-writed by Arbi Abdul Jabbaar
// Using Arduino IDE 1.8.7
// Using HC-SR04 Module
// Tested on 17 September 2019
// ---------------------------------------------------------------- //

#define echoPin1 9 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin1 8 //attach pin D3 Arduino to pin Trig of HC-SR04
#define echoPin2 11 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin2 10 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int distance1, distance2;

void setup() {
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin1, INPUT); // Sets the echoPin as an INPUT
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin2, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}

float Sensor(int trigPin,int echoPin)
{
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; 
  
  return distance;
}// END of the Sensor function


void loop() {
  // Clears the trigPin condition
  distance1 = Sensor(trigPin1, echoPin1);
  distance2 = Sensor(trigPin2, echoPin2);
  Serial.print("Distance1: ");
  Serial.print(distance1);
  Serial.println(" cm");

  
  Serial.print("Distance2: ");
  Serial.print(distance2);
  Serial.println(" cm");
}
