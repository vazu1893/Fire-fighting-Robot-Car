#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

// =========================
// Motor Pins (L298N)
// =========================
#define ENA 27
#define IN1 25
#define IN2 26

#define ENB 13
#define IN3 14
#define IN4 23

// =========================
// Buzzer
// =========================
#define BUZZER_PIN 33

void stopMotors();
void moveForward();
void moveBackward();
void turnLeft();
void turnRight();

void setup() {

  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.println("Starting ESP32...");

  // Start Bluetooth
  if (SerialBT.begin("ESP32_CAR")) {
    Serial.println("Bluetooth Started Successfully");
    Serial.println("Device Name: ESP32_CAR");
  } else {
    Serial.println("Bluetooth Failed To Start");
  }

  Serial.printf("Free Heap: %u bytes\n", ESP.getFreeHeap());

  // Motor Pins
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Buzzer
  pinMode(BUZZER_PIN, OUTPUT);

  // Enable Motor Drivers
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  stopMotors();

  Serial.println("Bluetooth Car Ready");
}

void loop() {

  if (SerialBT.available()) {

    char cmd = SerialBT.read();

    Serial.print("Received Command: ");
    Serial.println(cmd);

    switch (cmd) {

      case 'F':
      case 'f':
        moveForward();
        break;

      case 'B':
      case 'b':
        moveBackward();
        break;

      case 'L':
      case 'l':
        turnLeft();
        break;

      case 'R':
      case 'r':
        turnRight();
        break;

      case 'S':
      case 's':
        stopMotors();
        break;

      case 'Y':
      case 'y':
        digitalWrite(BUZZER_PIN, HIGH);
        delay(200);
        digitalWrite(BUZZER_PIN, LOW);
        break;

      default:
        Serial.println("Unknown Command");
        break;
    }
  }
}

// =========================
// Motor Functions
// =========================

void moveForward() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  Serial.println("Moving Forward");
}

void moveBackward() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  Serial.println("Moving Backward");
}

void turnLeft() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  Serial.println("Turning Left");
}

void turnRight() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  Serial.println("Turning Right");
}

void stopMotors() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  Serial.println("Stopped");
}