#include <TimerOne.h>

// Message Format:
// 1st byte: Traffic light number (1-3, 4-6, 7-8, 9-10)
// 2nd byte: 0 == off, 1 == on

#define RED_1 53
#define YELLOW_1 43
#define GREEN_1 39

#define RED_2 45
#define YELLOW_2 47
#define GREEN_2 35

#define RED_3 51
#define GREEN_3 49

#define RED_4 37
#define GREEN_4 41

#define ARDUNIO_IS_READY 2

#define BUTTON_CLICKED 33

void setup()
{
  pinMode(RED_1, OUTPUT);
  pinMode(YELLOW_1, OUTPUT);
  pinMode(GREEN_1, OUTPUT);
  pinMode(RED_2, OUTPUT);
  pinMode(YELLOW_2, OUTPUT);
  pinMode(GREEN_2, OUTPUT);
  pinMode(RED_3, OUTPUT);
  pinMode(GREEN_3, OUTPUT);
  pinMode(RED_4, OUTPUT);
  pinMode(GREEN_4, OUTPUT);
  pinMode(BUTTON_CLICKED, INPUT_PULLUP);

  Timer1.initialize(0.1 * 100000); //Mikrosekunden (0.1 = Sekunden)
  Timer1.attachInterrupt(timerTick);

  Serial.begin(115200);

  Serial.write(ARDUNIO_IS_READY);
}

void loop()
{
  if (Serial.available() > 1)
  {
    SetLight(Serial.read(), Serial.read());
  }
}

void SetLight(byte trafficLightState, byte trafficLightNumber)
{
  // Was used for debugging
  // Serial.write(trafficLightNumber);
  // Serial.write(trafficLightState);

  digitalWrite(trafficLightNumber, trafficLightState);
}

void timerTick()
{
  int buttonClicked = digitalRead(BUTTON_CLICKED);
  
  if (buttonClicked == LOW)
  {
     Serial.write(BUTTON_CLICKED);
  }
}

