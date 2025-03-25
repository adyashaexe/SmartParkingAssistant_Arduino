// Define pins
const int trigPin = 9; // Trigger pin for ultrasonic sensor
const int echoPin = 10; // Echo pin for ultrasonic sensor
const int buzzer = 11;   // Buzzer pin

// Variables for distance calculation
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT); // Set trigPin as output
  pinMode(echoPin, INPUT);  // Set echoPin as input
  pinMode(buzzer, OUTPUT);   // Set buzzer as output

  Serial.begin(9600); // Start serial communication at 9600 baud rate
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigPin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echoPin and calculate distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Convert to cm

  // Activate buzzer based on distance
  if (distance < 20) {
    digitalWrite(buzzer, HIGH); // Turn on buzzer if too close
    Serial.println("Warning: Object too close!");
  } else {
    digitalWrite(buzzer, LOW); // Turn off buzzer if safe
    Serial.println("Safe distance.");
  }

  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500); // Wait before next measurement
}
