# Sonar-Based Alert System

An Arduino-based sonar alert system that detects nearby objects using an HC-SR04 ultrasonic sensor. The system provides visual and audio alerts using a 16x2 I2C LCD, red/green LEDs, and a buzzer. A servo motor scans the surroundings and stops when an object is detected within the warning distance.

## Project Overview

The system continuously measures the distance between the ultrasonic sensor and nearby objects.

- When the area is clear, the green LED turns ON and the servo scans from 0° to 180°.
- When an object is detected within 20 cm, the red LED turns ON, the buzzer sounds, the LCD displays a warning, and the servo holds its current position.
- The LCD displays the system status and measured distance.

## Wiring Diagram

![Sonar-Based Alert System Wiring Diagram](wiring_diagram.png)

## Components Required

- Arduino UNO
- HC-SR04 Ultrasonic Sensor
- 16x2 LCD with I2C Module
- Servo Motor
- Red LED
- Green LED
- 2-Pin Buzzer
- 220Ω Resistors
- Breadboard
- Jumper Wires
- USB cable / suitable Arduino power supply

## Pin Configuration

### HC-SR04 Ultrasonic Sensor

| HC-SR04 Pin | Arduino UNO |
|---|---|
| VCC | 5V |
| GND | GND |
| TRIG | D9 |
| ECHO | D10 |

### 16x2 I2C LCD

| I2C LCD Pin | Arduino UNO |
|---|---|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

The program uses the I2C address `0x27`.

If the LCD backlight turns on but no text appears, the module may use `0x3F` instead.

### Servo Motor

| Servo Wire/Pin | Arduino UNO |
|---|---|
| Signal | D6 |
| VCC | 5V |
| GND | GND |

### LEDs

**Green LED**
```text
Arduino D2 → 220Ω resistor → LED anode (+)
LED cathode (-) → GND
```

**Red LED**
```text
Arduino D3 → 220Ω resistor → LED anode (+)
LED cathode (-) → GND
```

### 2-Pin Buzzer

```text
Buzzer + → Arduino D4
Buzzer - → GND
```

The program uses `tone()` to generate the buzzer alert.

## Complete Pin Summary

| Component | Pin | Arduino UNO |
|---|---|---|
| HC-SR04 | TRIG | D9 |
| HC-SR04 | ECHO | D10 |
| Green LED | Anode through 220Ω | D2 |
| Red LED | Anode through 220Ω | D3 |
| Buzzer | + | D4 |
| Servo | Signal | D6 |
| I2C LCD | SDA | A4 |
| I2C LCD | SCL | A5 |

## Working Principle

1. The HC-SR04 sends an ultrasonic pulse.
2. The pulse reflects from a nearby object.
3. Arduino measures the echo time.
4. Arduino calculates the distance.
5. The servo scans the surroundings from 0° to 180°.
6. If the measured distance is greater than 20 cm, the system considers the area clear.
7. If the measured distance is 20 cm or less, the system enters warning mode.

## System Behavior

### Area Clear — Distance > 20 cm

- Green LED: ON
- Red LED: OFF
- Buzzer: OFF
- LCD: Displays `Area is Empty`
- Servo: Continues scanning

### Object Detected — Distance ≤ 20 cm

- Green LED: OFF
- Red LED: ON
- Buzzer: ON
- LCD: Displays `WARNING!`
- Servo: Holds its current position

## Software Requirements

- Arduino IDE
- Arduino `Wire` library
- `LiquidCrystal_I2C` library
- `Servo` library

Install the **LiquidCrystal_I2C** library from:

`Arduino IDE → Sketch → Include Library → Manage Libraries`

## Arduino Code

The main program is located at:

```text
sonar_alert_system/sonar_alert_system.ino
```

## Important Notes

- Connect all component grounds to a common GND.
- The I2C LCD must have its I2C backpack connected.
- If the LCD does not display text, check the I2C address and adjust the contrast potentiometer on the I2C module.
- The 20 cm detection threshold can be changed in the Arduino code.
- If the servo causes the Arduino to reset, use a suitable external 5V supply for the servo and connect its GND to Arduino GND.

## Features

- Real-time ultrasonic distance measurement
- Servo-based scanning
- 16x2 I2C LCD status display
- Object detection
- Audible warning using a buzzer
- Red/green visual status indication
- Automatic scanning

## Future Improvements

- Radar-style graphical visualization
- Larger detection range
- Multiple ultrasonic sensors
- Bluetooth or Wi-Fi monitoring
- Mobile notifications
- Data logging
- Object tracking

## Project Structure

```text
Sonar-Based-Alert-System/
│
├── sonar_alert_system/
│   └── sonar_alert_system.ino
│
├── wiring_diagram.png
│
└── README.md
```

## License

This project is intended for educational and learning purposes.