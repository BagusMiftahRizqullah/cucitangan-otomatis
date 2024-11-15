#include <Arduino.h>

#define TRIG_PIN 9    // Trigger pin connected to Arduino pin 9
#define ECHO_PIN 10   // Echo pin connected to Arduino pin 10
#define RELAY_PIN 8 

void setup() {
  // Start serial communication
  Serial.begin(9600);
  
  // Set the trigPin as an OUTPUT and echoPin as an INPUT
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
  // Clear the TRIG pin by setting it LOW
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);  // Wait for a short time

  // Trigger the ultrasonic pulse by setting the TRIG pin HIGH for 10 microseconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the time it takes for the echo to return
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate the distance in cm
  // Speed of sound is 34300 cm/s, and the signal travels to the object and back
  long distance = duration * 0.0344 / 2;

  // Print the distance (Jarak) to the Serial Monitor
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if (distance < 32) { 
    digitalWrite(RELAY_PIN, HIGH);  
    Serial.println("Relay ON");
    delay(1000);
  } else {
  digitalWrite(RELAY_PIN, LOW); 
  Serial.println("Relay OFF");
  delay(1000);
  }
  // Wait before taking another reading
  
}
