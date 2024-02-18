// Arduino Traffic Light with Pedestrian Call

// Pin assignments for traffic lights
const int greenCarPin = 2;   // Green light for cars
const int yellowCarPin = 3;  // Yellow light for cars (optional)
const int redCarPin = 4;     // Red light for cars
const int greenPedestrianPin = 5;  // Green light for pedestrians
const int redPedestrianPin = 6;    // Red light for pedestrians

// Pin assignments for push buttons
const int pedestrianButtonPin = 8; // Pedestrian button
const int carButtonPin = 9;        // Car button

// Variables to store button states
int pedestrianButtonState = 0;
int carButtonState = 0;

void setup() {
  // Initialize pin modes
  pinMode(greenCarPin, OUTPUT);
  pinMode(yellowCarPin, OUTPUT);
  pinMode(redCarPin, OUTPUT);
  pinMode(greenPedestrianPin, OUTPUT);
  pinMode(redPedestrianPin, OUTPUT);
  pinMode(pedestrianButtonPin, INPUT);
  pinMode(carButtonPin, INPUT);
}

void loop() {
  // Default state: Green for cars, Red for pedestrians
  digitalWrite(greenCarPin, HIGH);
  digitalWrite(redPedestrianPin, HIGH);

  // Read button states
  pedestrianButtonState = digitalRead(pedestrianButtonPin);
  carButtonState = digitalRead(carButtonPin);

  // Check if pedestrian button is pressed
  if (pedestrianButtonState == HIGH) {
    pedestrianSequence(); // Activate pedestrian crossing sequence
  }

  // Check if car button is pressed
  if (carButtonState == HIGH) {
    carSequence(); // Activate car traffic sequence
  }
}

// Function to control pedestrian crossing sequence
void pedestrianSequence() {
  delay(3500); // Wait for cars to stop
  digitalWrite(greenCarPin, LOW); // Stop cars
  delay(1500); // Delay for safety
  digitalWrite(redCarPin, HIGH); // Turn red for cars
  digitalWrite(greenPedestrianPin, HIGH); // Allow pedestrians to cross
  delay(4000); // Pedestrian crossing time
  digitalWrite(greenPedestrianPin, LOW); // Stop pedestrian crossing
  delay(1500); // Delay before resetting lights
  digitalWrite(redPedestrianPin, LOW); // Turn off pedestrian light
  digitalWrite(redCarPin, LOW); // Turn off car red light
  digitalWrite(greenCarPin, HIGH); // Allow cars to proceed
}

// Function to control car traffic sequence
void carSequence() {
  delay(3500); // Wait for pedestrian crossing
  digitalWrite(greenCarPin, LOW); // Stop cars
  delay(1500); // Delay for safety
  digitalWrite(redCarPin, HIGH); // Turn red for cars
  delay(1500); // Delay before allowing pedestrians to cross again
  digitalWrite(redPedestrianPin, LOW); // Turn off pedestrian red light
  digitalWrite(greenPedestrianPin, HIGH); // Allow pedestrians to cross
  delay(4000); // Pedestrian crossing time
  digitalWrite(greenPedestrianPin, LOW); // Stop pedestrian crossing
  delay(1500); // Delay before resetting lights
  digitalWrite(redPedestrianPin, HIGH); // Turn red for pedestrians
  digitalWrite(redCarPin, LOW); // Turn off car red light
  digitalWrite(greenCarPin, HIGH); // Allow cars to proceed
}
