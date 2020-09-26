//servo library
#include<Servo.h>
// create servo object to control a servo
Servo myservo; 
// define pins numbers
int servo = 9;
int trigPin = 5;
int echoPin = 6;
// define variables
long duration,dist;
long aver[3];//array for average distance
void setup() 
{
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object  
  myservo.write(0);//close the cap on power on
  delay(100);
  Serial.begin(9600); // Starts the serial communication
}
// function to measure distance
void measure() 
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    dist = duration*0.034/2;
} 
void loop ()
{  
  for(int i =0;i<=2;i++)//to obtain average distance
  {
    measure();
    aver[i]=dist;
    delay(10);// delay between measurements
  }
  dist=(aver[0]+aver[1]+aver[2])/3;
   // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(dist);
    if(dist<10)
    { 
       myservo.write(45); 
       delay(100);
       myservo.write(90);
       delay(100);
       myservo.write(135);
       delay(100);
       myservo.write(180); //Ajust how far you want the servo to go.
       delay(1000);
       myservo.detach();
    }                
}

