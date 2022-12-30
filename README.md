# bluetooth-robot
Bluetooth controlled Arduino robot for reuseum educational

The #include <Servo.h> directive at the top of the file includes the Servo library, which provides functions for interacting with servo motors.

The Servo myservo; line declares a Servo object called myservo that can be used to control a servo motor.

The int pos = 0; line declares a variable called pos and initializes it to 0. This variable is not used in the code.

The constants HG7881_B_IA, HG7881_B_IB, HG7881_A_IA, and HG7881_A_IB define the wired connections between the Arduino and the motor driver. It appears that these constants represent the pins on the Arduino to which the motor driver's inputs are connected.

The constants MOTOR_B_PWM, MOTOR_B_DIR, MOTOR_A_PWM, and MOTOR_A_DIR define the functional connections between the Arduino and the motor driver. These constants are set to the values of the constants representing the wired connections, which means that the functional connections are mapped to the same pins as the wired connections.

The constants PWM_SLOW and PWM_FAST define the duty cycle values for slow and fast speeds, respectively. The duty cycle of a PWM signal determines the proportion of time that the signal is high (on) versus low (off) over a given period of time.

The setup() function is called once when the sketch starts. It initializes a serial connection at a baud rate of 9600, attaches the myservo object to pin 5, and sets the direction and speed of the motor driver's inputs to low.

The loop() function is called repeatedly after setup() has completed. It displays a menu of options on the serial port, waits for user input, and then executes a corresponding action based on the input character. The options include moving the robot forward or backward, turning right or left, stopping the robot, and rotating the servo to positions 0 or 180 degrees.

The digitalWrite() function is used to set the direction and speed of the motor driver's inputs. For example, the line digitalWrite( MOTOR_B_DIR, LOW ); sets the direction input for Motor B to low.

The myservo.write() function is used to rotate the servo to a specific position. For example, the line myservo.write(0); rotates the servo to position 0 degrees.

I hope this helps! Let me know if you have any questions.
