#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define TRIG_PIN 9
#define ECHO_PIN 10

#define GREEN_LED 2
#define RED_LED 3
#define BUZZER 4

#define SERVO_PIN 6

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myServo;

int pos = 0;
int direction = 1;

void setup() {

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  myServo.attach(SERVO_PIN);
  myServo.write(0);

  // Initialize LCD
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("  SONAR SYSTEM  ");

  lcd.setCursor(0, 1);
  lcd.print("   Starting...   ");

  delay(2000);
  lcd.clear();
}

long readDistance() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) {
    return 0;
  }

  long distance = duration * 0.034 / 2;

  return distance;
}

void loop() {

  long distance = readDistance();

  // Object NOT detected
  if (distance == 0 || distance > 20) {

    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);

    noTone(BUZZER);

    lcd.setCursor(0, 0);
    lcd.print("Area is Empty   ");

    lcd.setCursor(0, 1);
    lcd.print("Distance: ");

    if (distance == 0) {
      lcd.print("---");
    } else {
      lcd.print(distance);
      lcd.print("cm");
    }

    lcd.print("    ");

    // Move servo
    myServo.write(pos);

    delay(15);

    pos = pos + direction;

    if (pos >= 180) {
      pos = 180;
      direction = -1;
    }

    if (pos <= 0) {
      pos = 0;
      direction = 1;
    }
  }

  // Object detected
  else {

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);

    tone(BUZZER, 1000);

    lcd.setCursor(0, 0);
    lcd.print("!! WARNING !!   ");

    lcd.setCursor(0, 1);
    lcd.print("Object: ");
    lcd.print(distance);
    lcd.print("cm    ");

    // Stop servo at current position
    myServo.write(pos);

    delay(100);
  }
}


