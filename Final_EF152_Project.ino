#include "pitches.h"

//creating a threshold for the maximum distance
int distanceThreshold = 0;
// creating a variable that holds the measurement in centimeters so that
// it's easier to work with
int cm = 0;

int PIN_1 = 8;
int PIN_2 = 9;
int PIN_3 = 11;
int PIN_4 = 12;
int BUZZER = 10;
// creating a function that sets the trigger and echo pin
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

// setting all the LEDs and the piezo buzzer as an output 
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PIN_1, OUTPUT);
  pinMode(PIN_2, OUTPUT);
  pinMode(PIN_3, OUTPUT);
  pinMode(PIN_4,OUTPUT);
  pinMode(BUZZER,OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  pinMode(PIN_1, LOW);
  pinMode(PIN_2, LOW);
  pinMode(PIN_3, LOW);
  pinMode(PIN_4,LOW);
  analogWrite(BUZZER, 0);
}

void loop()
{
  digitalWrite(PIN_1,HIGH);
  digitalWrite(PIN_2,HIGH);
  digitalWrite(PIN_3,HIGH);
  digitalWrite(PIN_4,HIGH);
  distanceThreshold = 350;
  cm = 0.01723 * readUltrasonicDistance(4, 5);
  int time = 2;
int melody[] = {NOTE_F4, NOTE_E4, NOTE_E4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_F4,
              NOTE_DS4, NOTE_C4, NOTE_G3, NOTE_G3, NOTE_DS4, NOTE_D4, NOTE_DS4, NOTE_F4, NOTE_A3, NOTE_C4, NOTE_A3, NOTE_DS4, NOTE_D4,
              NOTE_DS4, NOTE_C4, NOTE_G3, NOTE_C4,NOTE_DS4, NOTE_D4, NOTE_DS4, NOTE_F4,NOTE_A3,NOTE_C4,NOTE_F4,NOTE_DS4,NOTE_D4,
              NOTE_G4,NOTE_F4,NOTE_DS4,NOTE_F4,NOTE_C4,NOTE_C4,NOTE_DS4,NOTE_C4,NOTE_C4,NOTE_C4,NOTE_F4,NOTE_DS4,NOTE_D4,NOTE_DS4,NOTE_C4,NOTE_C4,NOTE_C4,
              NOTE_G4,NOTE_F4,NOTE_F4,NOTE_G4,NOTE_AS3,NOTE_AS3,NOTE_C4,NOTE_C4,NOTE_C4,NOTE_C4,NOTE_DS4,NOTE_D4};
  int durations[] = {250,750,250,750,250,750,250,750,250,750,250,750,250,750,250,750,
                      150,150,150,150,150,150,150,350,150,150,150,300,350,
                      150,150,150,150,150,150,150,350,150,150,150,300,350,
                      250,150,100,800,70,70,85,70,70,150,150,150,350,150,70,70,
                      150,140,140,350,80,80,80,80,250,150,250,400}; 
  if (cm <= distanceThreshold -250 && cm > distanceThreshold - 350) {
    int size = sizeof(durations) / sizeof(int);
    for (int note = 0; note < size; note++) {
         tone(BUZZER, melody[note], durations[note]);
         digitalWrite(PIN_1,HIGH);
         digitalWrite(PIN_2,HIGH);
         digitalWrite(PIN_3,HIGH);
         digitalWrite(PIN_4,HIGH);
         delay(durations[note]);
         digitalWrite(PIN_1,LOW);
         digitalWrite(PIN_2,LOW);
         digitalWrite(PIN_3,LOW);
         digitalWrite(PIN_4,LOW);
      	 delay(durations[note]);
    }
  }
  delay(1000); // Delay a little bit to improve simulation performance
}