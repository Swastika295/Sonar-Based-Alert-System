# Sonar-Based Alert System

An Arduino-based ultrasonic object detection and alert system that measures the distance of nearby objects and provides visual and audio warnings using an LCD, servo motor, LEDs, and buzzer.

## Features

* Real-time distance measurement using the HC-SR04 ultrasonic sensor
* Servo motor scanning from 0° to 180°
* 16×2 I2C LCD for displaying system status and distance
* Green LED indication when no nearby object is detected
* Red LED and buzzer alerts when an object is detected within 20 cm
* Simple and beginner-friendly embedded systems project

## Components Required

* Arduino UNO
* HC-SR04 ultrasonic sensor
* 16×2 LCD with I2C module
* SG90 servo motor or equivalent
* Green LED
* Red LED
* 2-pin buzzer
* 220Ω resistors for LEDs
* Breadboard
* Jumper wires
* USB cable

## Hardware Connections

| Component           | Arduino Connection                  |
| ------------------- | ----------------------------------- |
| HC-SR04 VCC         | 5V                                  |
| HC-SR04 GND         | GND                                 |
| HC-SR04 TRIG        | Digital pin 9                       |
| HC-SR04 ECHO        | Digital pin 10                      |
| Green LED anode     | Digital pin 2 through 220Ω resistor |
| Green LED cathode   | GND                                 |
| Red LED anode       | Digital pin 3 through 220Ω resistor |
| Red LED cathode     | GND                                 |
| Buzzer positive (+) | Digital pin 4                       |
| Buzzer negative (-) | GND                                 |
| Servo signal        | Digital pin 6                       |
| Servo VCC           | Suitable 5V supply                  |
| Servo GND           | GND                                 |
| LCD VCC             | 5V                                  |
| LCD GND             | GND                                 |
| LCD SDA             | A4                                  |
| LCD SCL             | A5                                  |

**Important:** Connect all circuit grounds together. If the servo causes the Arduino to reset or behave unpredictably, use a suitable separate 5V supply for the servo, with a common ground.

## Working Principle

1. The HC-SR04 sensor sends ultrasonic waves and measures the time taken for the echo to return.
2. The Arduino calculates the distance to the detected object.
3. When the area is clear and the measured distance is greater than 20 cm, the green LED turns ON, the red LED and buzzer remain OFF, and the servo scans between 0° and 180°.
4. When an object is detected within 20 cm, the green LED turns OFF, the red LED turns ON, and the buzzer sounds.
5. The LCD displays the warning message and measured distance.

The detection threshold is set to 20 cm in the Arduino code and can be modified as needed.

## Software Requirements

* [Arduino IDE](https://www.arduino.cc/en/software)
* `Servo` library
* `Wire` library
* `LiquidCrystal_I2C` library

The `Wire` library is included with the Arduino environment. Install `LiquidCrystal_I2C` through **Arduino IDE → Library Manager** if required.

## Getting Started

### 1. Clone the Repository

Clone the project to your local computer:

```bash
git clone https://github.com/Swastika295/Sonar-Based-Alert-System.git
```

### 2. Navigate to the Project Directory

```bash
cd Sonar-Based-Alert-System
```

### 3. Open the Arduino Sketch

Open the following file in the Arduino IDE:

```text
sonar_alert_system/sonar_alert_system.ino
```

### 4. Connect and Upload

1. Connect the Arduino UNO to your computer using a USB cable.
2. Select **Arduino UNO** under Tools → Board.
3. Select the correct port under Tools → Port.
4. Install any missing libraries.
5. Compile and upload the sketch.

## Project Structure

```text
Sonar-Based-Alert-System/
├── README.md
└── sonar_alert_system/
    └── sonar_alert_system.ino
```

## Applications

* Basic obstacle detection
* Robotics and embedded systems experiments
* Ultrasonic sensor demonstrations
* Arduino learning projects

## Future Improvements

* Add radar-style visualization on a computer.
* Record detected distances and events.
* Make the detection threshold configurable.
* Improve scanning and alert response.

## Author

**Swastika Singh**

GitHub: [Swastika295](https://github.com/Swastika295)

## License

This project is intended for educational and personal learning purposes.
