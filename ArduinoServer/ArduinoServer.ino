#include <TimerOne.h>

// Message Format:
// 1st byte: Traffic light number (1-3, 4-6, 7-8, 9-10)
// 2nd byte: 0 == off, 1 == on

#define RED_1 53
#define YELLOW_1 51
#define GREEN_1 49

#define RED_2 47
#define YELLOW_2 45
#define GREEN_2 43

#define RED_3 41
#define GREEN_3 39

#define RED_4 37
#define GREEN_4 35

#define ARDUNIO_IS_READY 2

#define BUTTON_CLICKED 33

bool isReady = false;

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
  pinMode(BUTTON_CLICKED, INPUT);

  Timer1.initialize(100000);
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

// TODO @David Richtige Logik verwenden
void SetLight(byte trafficLightState, byte trafficLightNumber)
{
  Serial.write(trafficLightNumber);
  Serial.write(trafficLightState);
  
  // digitalWrite(trafficLightNumber, trafficLightState);
}

void timerTick()
{
  if (digitalRead(BUTTON_CLICKED) == 1)
  {
    Serial.write(BUTTON_CLICKED);
  }
}

