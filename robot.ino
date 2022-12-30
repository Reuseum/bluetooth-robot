/*
  HG7881_Motor_Driver_Example - Arduino sketch
''this is a demo code to show how to set up the robot to be contolled with bluetooth via serial data"
*/
#include <Servo.h>

 Servo myservo;
 int pos = 0; 
 
// wired connections
#define HG7881_B_IA 9  // D9 --> Motor B Input A --> MOTOR B +
#define HG7881_B_IB 10 // D10 --> Motor B Input B --> MOTOR B -
#define HG7881_A_IA 11 // D11 --> Motor B Input A --> MOTOR B +
#define HG7881_A_IB 12 // D12 --> Motor B Input B --> MOTOR B -

 
// functional connections
#define MOTOR_B_PWM HG7881_B_IA // Motor B PWM Speed
#define MOTOR_B_DIR HG7881_B_IB // Motor B Direction
#define MOTOR_A_PWM HG7881_A_IA // Motor B PWM Speed
#define MOTOR_A_DIR HG7881_A_IB // Motor B Direction
 
// the actual values for "fast" and "slow" depend on the motor
#define PWM_SLOW 180  // arbitrary slow speed PWM duty cycle
#define PWM_FAST 255 // arbitrary fast speed PWM duty cycle
#define DIR_DELAY 1000 // brief delay for abrupt motor changes
 
void setup() 
{
  Serial.begin( 9600 );
  myservo.attach(5); "attach servo to pin 5"
  pinMode( MOTOR_B_DIR, OUTPUT );
  pinMode( MOTOR_B_PWM, OUTPUT );
  pinMode( MOTOR_A_DIR, OUTPUT );
  pinMode( MOTOR_A_PWM, OUTPUT );
  digitalWrite( MOTOR_B_DIR, LOW );
  digitalWrite( MOTOR_B_PWM, LOW );
  digitalWrite( MOTOR_A_DIR, LOW );
  digitalWrite( MOTOR_A_PWM, LOW );
}
 
void loop()
{
  boolean isValidInput;
  // draw a menu on the serial port
  Serial.println( "-----------------------------" );
  Serial.println( "MENU:" );
  Serial.println( "w) Fast forward" );
  Serial.println( "d) Right" );
  Serial.println( "3) Soft stop (coast)" );
  Serial.println( "a) Left" );
  Serial.println( "s) Fast reverse" );
  Serial.println( "0) Hard stop (brake)" );
  Serial.println( "x) servo 0" );
  Serial.println( "o)servo 180" );
  Serial.println( "-----------------------------" );
  do
  {
    byte c;
    // get the next character from the serial port
    Serial.print( "?" );
    while( !Serial.available() )
      ; // LOOP...
    c = Serial.read();
    // execute the menu option based on the character recieved
    switch( c )
    {
      case 'w': // 1) Fast forward
        Serial.println( "Fast forward..." );
        digitalWrite( MOTOR_B_DIR, HIGH );
        digitalWrite( MOTOR_B_PWM, LOW );
        digitalWrite( MOTOR_A_DIR, HIGH );
        digitalWrite( MOTOR_A_PWM, LOW );
        isValidInput = true;
        break;      
         
      case 'd': // 2) Right      
        Serial.println( "Forward..." );
        digitalWrite( MOTOR_B_DIR, HIGH );
        digitalWrite( MOTOR_B_PWM, LOW );
        digitalWrite( MOTOR_A_DIR, LOW );
        digitalWrite( MOTOR_A_PWM, HIGH );
        isValidInput = true;
        break;      
         
      case '0': // 3) Soft stop (preferred)
        Serial.println( "Soft stop (coast)..." );
        digitalWrite( MOTOR_B_DIR, LOW );
        digitalWrite( MOTOR_B_PWM, LOW );
        digitalWrite( MOTOR_A_DIR, LOW );
        digitalWrite( MOTOR_A_PWM, LOW );
        isValidInput = true;
        break;      
 
      case 'a': // 4) Left
        Serial.println( "Fast forward..." );
        // always stop motors briefly before abrupt changes
        digitalWrite( MOTOR_B_DIR, LOW );
        digitalWrite( MOTOR_B_PWM, HIGH);
        digitalWrite( MOTOR_A_DIR, HIGH );
        digitalWrite( MOTOR_A_PWM, LOW );
        isValidInput = true;
        break;      
         
      case 's': // 5) Fast reverse
        Serial.println( "Fast forward..." );
        // always stop motors briefly before abrupt changes
        digitalWrite( MOTOR_B_DIR, LOW );
        digitalWrite( MOTOR_B_PWM, HIGH );
         digitalWrite( MOTOR_A_DIR, LOW );
        digitalWrite( MOTOR_A_PWM, HIGH );
     
        isValidInput = true;
        break;
         
      case '-': // 6) Hard stop (use with caution)
        Serial.println( "Hard stop (brake)..." );
        digitalWrite( MOTOR_B_DIR, HIGH );
        digitalWrite( MOTOR_B_PWM, HIGH );
        digitalWrite( MOTOR_A_DIR, HIGH );
        digitalWrite( MOTOR_A_PWM, HIGH );
        isValidInput = true;
        break;     
         
          case '[': // 7)servo 0
        Serial.println( "servo 0" );
    myservo.write(0);              // tell servo to go to position in variable 'pos'
    delay(15);  
        isValidInput = true;
        break;      

         case 'x': // 8)servo 45
        Serial.println( "servo 45" );
    myservo.write(45);              // tell servo to go to position in variable 'pos'
    delay(15);  
        isValidInput = true;
        break;      

         case 'o': // 8)servo 90
        Serial.println( "servo 90" );
    myservo.write(90);              // tell servo to go to position in variable 'pos'
    delay(15);  
        isValidInput = true;
        break;      

            case '5': // 9)horn
        Serial.println( "horn" );
 tone(6, 600, 200);
 delay(200);
  tone(6, 900, 200);
  delay(200);
        isValidInput = true;
        break;      
        
      default:
        // wrong character! display the menu again!
        isValidInput = false;
        break;
    }
  } while( isValidInput == true );
 
  // repeat the main loop and redraw the menu...
}
/*EOF*/
