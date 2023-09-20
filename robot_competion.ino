#include <Wire.h>
#include <math.h>
#include <Adafruit_MPU6050.h>

#define echoPin_1 5
#define trigPin_1 6
#define echoPin_2 7
#define trigPin_2 8
#define echoPin_3 9
#define trigPin_3 10

#define startX 0.75
#define startY 0.1


Adafruit_MPU6050 imu;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();

  pinMode(echoPin_1, OUTPUT);
  pinMode(trigPin_1, OUTPUT);
  pinMode(echoPin_2, OUTPUT);
  pinMode(trigPin_2, OUTPUT);
  pinMode(echoPin_3, OUTPUT);
  pinMode(trigPin_3, OUTPUT);

  Serial.begin(9600);


  // Initialize MPU6050
  if (!imu.begin()) {
    Serial.println("MPU6050 initialization failed. Please check your connections.");
    while (1);
  }
  
  // declare the the target point
  float targetX;
  float targetY;

  // Define the positions of green areas (adjust as needed)
  float greenArea1X = 0.2; // X-coordinate of the first green area
  float greenArea1Y = 0.5; // Y-coordinate of the first green area
  float greenArea2X = 0.2; // X-coordinate of the second green area
  float greenArea2Y = 1.2; // Y-coordinate of the second green area
  float greenArea3X = 0.2; // X-coordinate of the first green area
  float greenArea3Y = 0.5; // Y-coordinate of the first green area
  float greenArea4X = 0.2; // X-coordinate of the second green area
  float greenArea4Y = 1.2; // Y-coordinate of the second green area
  float MiaAreaX = 1.9; // X-coordinate of the Mia area
  float MiaAreaY = 0.6; // Y-coordinate of the Mia area
  // Add more green areas as needed


  float currentX = startX;
  float currentY = startY;
}

void loop() {
  // put your main code here, to run repeatedly:
  float accX, accY, accZ;
  float gyroX, gyroY, gyroZ;
  


} 

// Function to read distance from an ultrasonic sensor
float getUltrasonicReading(int trigPin, int echoPin){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  float duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2.0;

  return distance;
}

// Function to calculate the distance between two points
float distance(float x1, float y1, float x2, float y2) {
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}


