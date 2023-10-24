# *Description*
This Arduino project focuses on creating an **obstacle avoidance robot** that employs ultrasonic sensors for distance measurement and `AFMotor` modules to control its motors.

The robot detects obstacles in its path and navigates around them.

# *Components*
- **Arduino board** (e.g., Arduino Uno)
- **Ultrasonic obstacle sensor** (e.g., HC-SR04)
- **Motor chassis** with four motors (two for driving and two for steering)
- **Motor driver** (AFMotor library)
- **Battery** or **power source**

# *Operation*
- The robot uses an ultrasonic sensor to measure distances to obstacles in front of it.
- If an obstacle is detected at a distance less than or equal to **distanceBack**, the robot will start moving backward and scanning for an escape route.
- The **servo motor** is used to sweep the obstacle sensor left and right to identify the safest direction for avoiding the obstacle.
- The robot will move in the chosen direction to circumvent the obstacle.
- If no obstacles are detected, the robot will continue moving forward.

# *License*
Distributed under the **MIT License**. See [LICENSE](https://github.com/lPauI/Arduino-obstacle-avoider/blob/main/LICENSE) for more information.

# *Contributions*
Contributions to this project are welcome. If you have suggestions, improvements, or bug fixes, please fork this repository, make the necessary changes, and submit a pull request.

# *Installation*
1. Clone this repository (`git clone https://github.com/lPauI/Arduino-obstacle-avoider.git`) to your computer or download the code files.
2. Upload the provided **Arduino sketch (robot.ino)** to your Arduino board using the Arduino IDE.
3. Assemble the hardware as described in the code or customize the pin connections as needed.
4. Power up the robot and observe its **obstacle avoidance behavior**.

**Modify the code to use your preferred pins:** If you wish to use different pins for your hardware components, you can modify the `robot.ino` code to reflect your connections. Be sure to update the pin configurations accordingly.
