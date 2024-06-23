// Define the RGB LED pins
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

// Define the button pin
const int buttonPin = 2;

// Variable to hold the current color state
int colorState = 0;

// Variable to hold the button state
int buttonState = 0;
int lastButtonState = 0;

// Function to set the RGB LED color
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void setup() {
  // Initialize the RGB LED pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Initialize the button pin as input
  pinMode(buttonPin, INPUT);

  // Start with the LED off
  setColor(0, 0, 0);
}

void loop() {
  // Read the state of the button
  buttonState = digitalRead(buttonPin);

  // Check if the button was pressed
  if (buttonState == HIGH && lastButtonState == LOW) {
    // Update the color state
    colorState++;
    if (colorState > 7) {
      colorState = 0;
    }

    // Set the LED color based on the color state
    switch (colorState) {
      case 0:
        setColor(0, 0, 0);  // Off
        break;
      case 1:
        setColor(255, 0, 0);  // Red
        break;
      case 2:
        setColor(0, 255, 0);  // Green
        break;
      case 3:
        setColor(0, 0, 255);  // Blue
        break;
      case 4:
        setColor(255, 255, 0);  // Yellow
        break;
      case 5:
        setColor(0, 255, 255);  // Cyan
        break;
      case 6:
        setColor(255, 0, 255);  // Magenta
        break;
      case 7:
        setColor(255, 255, 255);  // White
        break;
    }
  }

  // Save the current button state as the last state
  lastButtonState = buttonState;

  // Small delay to debounce the button
  delay(50);
}
