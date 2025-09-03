# Car-Parking-Assistance-System
Car parking sensor system using ATmega32. Measures distance via ultrasonic sensor, displays on LCD, and alerts with LEDs and buzzer. Features layered drivers: GPIO, ICU, LCD, and ultrasonic. Helps drivers avoid collisions while parking.

## Features

- **Ultrasonic Distance Measurement**: HC-SR04 sensor measures proximity to obstacles.
- **Real-Time LCD Display**: Shows distance in cm; displays "STOP" for critical distances (<5cm).
- **Visual & Audible Alerts**: Multi-color LEDs and a buzzer provide warnings based on proximity.
- **Layered Driver Architecture**: Implemented using modular, reusable drivers for GPIO, ICU, LCD, and Ultrasonic sensor.

## Hardware Components

- **Microcontroller**: ATmega32
- **Sensors**: HC-SR04 Ultrasonic
- **Display**: 16x2 LCD
- **Indicators**: Red, Green, Blue LEDs & Buzzer
- <img width="933" height="650" alt="Screenshot 2025-09-03 175607" src="https://github.com/user-attachments/assets/abd8c493-1d07-4312-822e-0a4f7bfd8a33" />

## System Operation

The system calculates distance by measuring ultrasonic echo time. Feedback is provided through:
- **LCD**: Live distance readout.
- **LEDs**: Light up progressively as the object gets closer (Blue -> Green -> Red).
- **Buzzer**: Activates for critical distances (≤5 cm).

## Project Structure

The code follows a layered architecture model:
- **Application Layer**: Main application logic.
- **HAL**: Drivers for LCD, Ultrasonic Sensor, Buzzer.
- **MCAL**: Drivers for GPIO, ICU.

---

## Getting Started

### Prerequisites
- Simulator: Proteus
- IDE: Atmel Studio

### Installation
1. Clone the repository.
2. Open the project in Atmel Studio.
3. Build and program the ATmega32 microcontroller.
4. Run the simulation in Proteus to test functionality.

## License

This project is part of the Embedded Systems Diploma from Edges For Training.
