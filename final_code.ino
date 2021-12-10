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

int motor1pin1 = 2;
int motor1pin2 = 3;
int motor1_ena = 6;

int motor2pin1 = 4;
int motor2pin2 = 7;
int motor2_enb = 5;

int motor_direction = 0; // motor_direction = 0 means running toward sensor_1 direction
                         // motor_direction = 1 means running toward sensor_2 direction

int distance_1, distance_2, distance_3, distance_4; // variable for the distance measurement
float Sensor(int trigPin, int echoPin);
void read_sensor();
void change_direction();
void print_sensor_all();

// INITIAL SET UP
void setup() {

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(motor1_ena, OUTPUT);
  pinMode(motor2_enb, OUTPUT);

  // set the speed to 40-45%
  analogWrite(motor1_ena, 120);
  analogWrite(motor2_enb, 120);
  
  // set the initial direction of the motor
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}

// MAIN FUNCTION
void loop() {
  read_sensor();
//   if the device runs toward the sensor_1 direction, the motor_direction = 0
//   we only check the data from sensor_1 and sensor_3
//   we need the motor to run faster to climb up the hill
  if (motor_direction == 0){
    if (distance_1 <= 10){
      change_direction();
    }
    if (distance_3 >= 6.5){
      change_direction();
    }
  }
  // the other case is the device runs toward the sensor_2 direction, the motor_direction = 1
  // we only check the data from sensor_2 and sensor_4
  // we need the motor to run slower going down the hill
  else{
    if (distance_2 <= 10){
      change_direction();
    }
  
    if (distance_4 >= 6.5){
      change_direction();
    }
  }
  
  print_sensor_all();
}



// function calculate the distance with the input is the trig and echo of each sensor
float Sensor(int trigPin, int echoPin)
{
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  float duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  float distance = duration * 0.034 / 2;

  return distance;
}// END of the Sensor function


void read_sensor() {
  distance_1 = Sensor(trigPin1, echoPin1);
  distance_2 = Sensor(trigPin2, echoPin2);
  distance_3 = Sensor(trigPin3, echoPin3);
  distance_4 = Sensor(trigPin4, echoPin4);
}

void change_direction(){
  if(motor_direction == 0){
    // the machine going down the hill
    // stop the motor for 1 second
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
    delay(1000);

//    // set the power of motor lower
//    // set the speed to 30%
//    analogWrite(motor1_ena, 75);
//    analogWrite(motor2_enb, 75);
    //reverse the direction of motor
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);
    motor_direction = 1;
  }
  else{
    // the machine going up the handrail
    // stop the motor for 1 second
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
    delay(1000);

    // set the power of motor higher
//    // set the speed to 80%
//    analogWrite(motor1_ena, 255);
//    analogWrite(motor2_enb, 255);
    //reverse the direction of motor
    
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
  
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
    motor_direction = 0;
  }
}


//void stop_motor(){
//  if(motor_direction == 0){
//    //stop the motor for 1 second
//    digitalWrite(motor1pin1, LOW);
//    digitalWrite(motor1pin2, LOW);
//    
//    digitalWrite(motor2pin1, LOW);
//    digitalWrite(motor2pin2, LOW);
//  }
//  else{
//    //stop the motor for 1 second
//    digitalWrite(motor1pin1, LOW);
//    digitalWrite(motor1pin2, LOW);
//    
//    digitalWrite(motor2pin1, LOW);
//    digitalWrite(motor2pin2, LOW);
//  }
//}


void print_sensor_all() {
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
  Serial.println(motor_direction);
}
