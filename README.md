# Flood Alert System

IoT-based flood monitoring and alert system using NodeMCU ESP8266 and a water level sensor.

## About
This project monitors the water level in real time. When the water crosses the danger level, a buzzer rings and an LED turns on. The live water level and status can also be viewed on a phone or laptop through Wi-Fi.

## Components Used
- NodeMCU ESP8266
- Water level sensor
- Buzzer
- LED with 220Ω resistor
- Jumper wires and USB cable

## Circuit Connections
| Component | Pin | NodeMCU Pin |
|---|---|---|
| Water sensor | VCC | 3V3 |
| Water sensor | GND | GND |
| Water sensor | Signal (S) | A0 |
| Buzzer | + | D5 |
| Buzzer | - | GND |
| LED | + (via 220Ω resistor) | D6 |
| LED | - | GND |

## How It Works
1. The water level sensor measures the water level.
2. The NodeMCU reads the sensor value.
3. If the value is above the threshold, the buzzer rings and the LED turns on.
4. The NodeMCU hosts a small web page that shows the live water level and status.

## How to Run
1. Open `flood_alert.ino` in the Arduino IDE.
2. Install the ESP8266 board package and select NodeMCU 1.0.
3. Replace `YOUR_WIFI_NAME` and `YOUR_WIFI_PASSWORD` with your Wi-Fi details.
4. Upload the code and open the Serial Monitor (115200 baud) to see the IP address.
5. Open that IP address in a browser to see the live status.

## What I Learned
- Programming the ESP8266 using Arduino IDE
- Reading analog sensor data
- IoT communication over Wi-Fi
- Building a real-time alert system 
