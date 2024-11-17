# Obstacle Avoidance and Line Following Robot 🤖🚗

This Arduino-based project implements an **Obstacle Avoidance Robot** with **Line Following** capabilities. The robot uses infrared (IR) sensors for line detection and an ultrasonic sensor for obstacle avoidance, navigating autonomously based on sensor inputs.

## Features:
- **Obstacle Avoidance**: Stops the robot if an obstacle is detected within 20 cm using the **HC-SR04 ultrasonic sensor**.
- **Line Following**: The robot adjusts its movement based on input from two **infrared (IR) sensors** to follow a line.
- **Motor Control**: DC motors are controlled via the **AFMotor library**, allowing the robot to move forward, stop, or turn.

## Components:
- **Arduino** (Uno, Nano, or similar)
- **HC-SR04 Ultrasonic Sensor** (for obstacle detection)
- **Infrared (IR) Sensors** (for line following)
- **DC Motors** (controlled via AFMotor library)

## How It Works:
1. The robot continuously reads the values from the **IR sensors** to detect and follow a line.
2. If the robot detects an obstacle within 20 cm using the **ultrasonic sensor**, it will stop.
3. The robot's motors are controlled based on sensor inputs to either move forward, turn, or stop.

## Libraries Used:
- **AFMotor**: For motor control.
- **Arduino Standard Libraries**: For basic functions like `pulseIn()` and `analogRead()`.

## Code Explanation:
- **measureDistance()**: Measures the distance to obstacles using the ultrasonic sensor.
- **IR Sensors**: Monitor the surface under the robot and adjust the motor's direction based on the detection of a line.
- The **AFMotor library** is used to control the DC motors and adjust the robot's movement based on sensor readings.

## How to Use:
1. **Connect the components** to an Arduino board following the pin assignments in the code (`A1`, `A2` for IR sensors, `A4`, `A5` for ultrasonic sensor).
2. **Upload the code** to the Arduino using the Arduino IDE.
3. **Open the Serial Monitor** to view real-time sensor data.
4. Watch the robot navigate, following the line and avoiding obstacles!

## Future Improvements:
- Implement **PID control** for smoother line-following and more accurate turns.
- Add more sensors for better **obstacle detection** and **navigation**.
- Integrate a **wireless control system** using Bluetooth or Wi-Fi.

