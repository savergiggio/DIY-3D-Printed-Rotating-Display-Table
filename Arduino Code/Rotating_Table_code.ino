// Define stepper motor control pins
#define IN1 9
#define IN2 10
#define IN3 11
#define IN4 12

// Define the steps in the sequence
int stepSequence[8][4] = {
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

// Variables for direction and speed
bool direction = true; // false for anti-clockwise, true for clockwise
int speed = 5; // Speed control (1 to 10), higher value means slower speed

void setup() {
  // Set control pins as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  // Iterate through the step sequence based on direction
  if (direction) {
    for (int i = 0; i < 8; i++) {
      setStep(stepSequence[i][0], stepSequence[i][1], stepSequence[i][2], stepSequence[i][3]);
      delay(speed); // Control speed
    }
  } else {
    for (int i = 7; i >= 0; i--) {
      setStep(stepSequence[i][0], stepSequence[i][1], stepSequence[i][2], stepSequence[i][3]);
      delay(speed); // Control speed
    }
  }
}

void setStep(int a, int b, int c, int d) {
  digitalWrite(IN1, a);
  digitalWrite(IN2, b);
  digitalWrite(IN3, c);
  digitalWrite(IN4, d);
}
