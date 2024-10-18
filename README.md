# GreenHouse Monitoring System

## Introduction

The **GreenHouse Monitoring System** is an automated solution designed to maintain optimal growing conditions for plants in a greenhouse. By integrating Arduino technology with various sensors, this system monitors environmental parameters such as temperature, humidity, and light intensity. It adjusts the greenhouse conditions accordingly to ensure optimal plant health and productivity.

## Components Used

1. **Arduino**: The central processing unit that reads sensor data and controls the output devices.
2. **DHT11 Sensor**: Measures temperature and humidity levels inside the greenhouse.
3. **Light Sensor**: Measures the intensity of light within the greenhouse.
4. **L293D Motor Driver**: Controls the operation of the cooling fan.
5. **Cooling Fan**: Regulates the temperature inside the greenhouse.
6. **Artificial Light**: Supplements natural light when necessary.
7. **LCD 16x2 Display**: Provides a visual interface for real-time data.
8. **Bluetooth Module**: Facilitates wireless communication for remote monitoring and control.

## Features

- **Automated Climate Control**: Automatically adjusts cooling fan and artificial light based on real-time sensor data.
- **Real-Time Feedback**: Displays current temperature, humidity, and light levels on the LCD screen.
- **Remote Access**: Allows for remote monitoring and control via Bluetooth connectivity.
- **Data-Driven Adjustments**: Improves resource efficiency and plant health through automated adjustments.

## Working Principle

1. **Data Collection**: The Arduino continuously reads the temperature and humidity from the DHT11 sensor and light levels from the light sensor.
2. **Temperature Management**: If the temperature exceeds a set threshold, the cooling fan is activated to cool the greenhouse. If the temperature is below the threshold, the fan is turned off.
3. **Light Intensity Management**: If the light intensity falls below a defined threshold, the artificial light is turned on to ensure adequate illumination for the plants.
4. **User Interface and Monitoring**: The LCD displays real-time data, and the Bluetooth module allows remote access for monitoring and control.

## Code Explanation

The code for the GreenHouse Monitoring System includes the following key functions:

- **Setup**: Initializes the components and displays an initial message on the LCD.
- **Loop**: Continuously reads data from sensors, controls the fan and lights based on the readings, and updates the LCD display and Bluetooth communication.

## How to Use

1. **Wiring**: Connect all components according to the wiring diagram provided in the project documentation.
2. **Upload Code**: Upload the provided Arduino code to your Arduino board using the Arduino IDE.
3. **Power On**: Power the Arduino and monitor the LCD display for real-time updates.
4. **Remote Control**: Use a Bluetooth-enabled device to connect and monitor/control the system from a distance.

## Expected Outcomes

- **Stable Growing Conditions**: Maintains consistent temperature and light levels for optimal plant growth.
- **Efficient Resource Use**: Reduces manual intervention and optimizes energy consumption.
- **Convenient Management**: Easy access to greenhouse conditions and control options through the LCD and Bluetooth.

## Conclusion

The GreenHouse Monitoring System offers a simple yet effective way to automate the care of plants in a greenhouse. By using technology to monitor and adjust environmental conditions, this system ensures that plants thrive, even when their caretakers are not present.

## License

This project is licensed under the [MIT License](LICENSE).
