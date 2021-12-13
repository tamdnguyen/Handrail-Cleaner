  // defines variables

// HC-SR04_1 and HC-SR04_2 senses any walls or ostacles
// HC-SR04_3 and HC-SR04_4 check the end of handrails

#define echoPin1 9 // pin D2 Arduino to pin Echo of HC-SR04_1
#define trigPin1 8 // pin D3 Arduino to pin Trig of HC-SR04_1
#define echoPin2 11 // pin D9 Arduino to pin Echo of HC-SR04_2
#define trigPin2 10 // pin D10 Arduino to pin Trig of HC-SR04_2
#define echoPin3 12 // pin D12 Arduino to pin Echo of HC-SR04_3
#define trigPin3 13 // pin D13 Arduino to pin Trig of HC-SR04_3
#define echoPin4 A0 // pin A0 Arduino to pin Echo of HC-SR04_4
#define trigPin4 A1 // pin A1 Arduino to pin Trig of HC-SR04_4

long duration;
int distance;
int distance_1, distance_2, distance_3, distance_4; // variable for the distance measurement

void setup() {
  
  pinMode(trigPin1, OUTPUT); 
  pinMode(echoPin1, INPUT); 
  pinMode(trigPin2, OUTPUT); 
  pinMode(echoPin2, INPUT); 
  pinMode(trigPin3, OUTPUT); 
  pinMode(echoPin3, INPUT); 
  pinMode(trigPin4, OUTPUT); 
  pinMode(echoPin4, INPUT); 
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}


// function calculate the distance with the input is the trig and echo of each sensor
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


void read_sensor(){
  distance_1 = Sensor(trigPin1, echoPin1);
  distance_2 = Sensor(trigPin2, echoPin2);
  distance_3 = Sensor(trigPin3, echoPin3);
  distance_4 = Sensor(trigPin4, echoPin4);
}


void print_sensor_all(){
  Serial.print("Distance_1: ");
  Serial.print(distance_1);
  Serial.println(" cm");
  Serial.print("Distance_2: ");
  Serial.print(distance_2);
  Serial.println(" cm");
  Serial.print("Distance_3: ");
  Serial.print(distance_3);
  Serial.println(" cm");
  Serial.print("Distance_4: ");
  Serial.print(distance_4);
  Serial.println(" cm");
}


void loop() {
  read_sensor();
  print_sensor_all();
}
