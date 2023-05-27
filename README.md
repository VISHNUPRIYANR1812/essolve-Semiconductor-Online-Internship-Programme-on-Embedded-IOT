# Automation of egg hatchery systems with IoT

This is an egg incubator that uses an ESP8266 microcontroller and various sensors to maintain a controlled environment for hatching eggs.

https://github.com/VISHNUPRIYANR1812/essolve-Semiconductor-Online-Internship-Programme-on-Embedded-IOT/assets/134359531/de42c4b3-4fb6-4ca2-931d-6a518bb8bca1

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



![3f0fd989-3a99-4048-bbfa-daac725b7d2e](https://github.com/VISHNUPRIYANR1812/essolve-Semiconductor-Online-Internship-Programme-on-Embedded-IOT/assets/134359531/ff30995b-7dc1-41a0-8c57-b540426a5a1b)

![c5bcb7a2-97e4-4a0f-890e-aa013523e0a6](https://github.com/VISHNUPRIYANR1812/essolve-Semiconductor-Online-Internship-Programme-on-Embedded-IOT/assets/134359531/11a954e1-6d8c-4636-97bb-5a7c0458318e)


## Usage

1. Install the required libraries.
2. Connect the components according to the wiring diagram.
3. Upload the code to the ESP8266 microcontroller.
4. Open the Blynk app and use it to control the egg incubator.

## License

This project is licensed under the MIT License - see the LICENSE.md file for details.
