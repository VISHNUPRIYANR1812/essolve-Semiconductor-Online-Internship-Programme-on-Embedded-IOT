# Automation of egg hatchery systems with IoT

This is an egg incubator that uses an ESP8266 microcontroller and various sensors to maintain a controlled environment for hatching eggs.



## Required Hardware

- ESP8266 microcontroller
- DHT11 temperature and humidity sensor
- MQ-2 gas sensor
- Servo motor
- Light bulb
- Jumper wires
- Dot-boards
- Resistors

## Required Libraries

- BlynkSimpleEsp8266.h
- ESP8266WiFi.h
- DHT.h
- Servo.h

## Wiring

| Component  | Pin           |
|------------|---------------|
| DHT11      | Pin D7         |
| MQ-2         | Analog Pin A0 |
| Servo motor | Pin D2         |
| Tungsten bulb  | Pins D0 and D1  |

## Blynk App

<center>The Blynk app is used to control the egg incubator. The app has several widgets that allow the user to monitor the temperature, humidity, and gas level inside the incubator, as well as control the light bulb and servo motor. The Blynk app requires a Blynk auth token, which must be added to the code.</center>

## Usage

1. Install the required libraries.
2. Connect the components according to the wiring diagram.
3. Upload the code to the ESP8266 microcontroller.
4. Open the Blynk app and use it to control the egg incubator.

## License

This project is licensed under the MIT License - see the LICENSE.md file for details.
