#include <TimerOne.h>

// Message Format:
// 1st byte: Traffic light number
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

#define RESET 1

void setup()
{
  // put your setup code here, to run once:
  pinMode(53, OUTPUT);
  pinMode(51, OUTPUT);
  pinMode(49, OUTPUT);
  pinMode(47, OUTPUT);
  pinMode(45, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(41, OUTPUT);
  pinMode(39, OUTPUT);
  pinMode(37, OUTPUT);
  pinMode(35, OUTPUT);
  pinMode(33, INPUT);
  
  Timer1.initialize(100000); 
  Timer1.attachInterrupt(timerTick);

  Serial.begin(115200);
}

void loop()
{
  byte lastPeek;
  
  // put your main code here, to run repeatedly:
  if(Serial.available() > 1)
  {
    lastPeek = Serial.peek();
    
    // Reset command
    if(lastPeek == 100)
    {
      while(Serial.available() > 0)
      {
        Serial.read();
      }
    }
    else
    {
      SetLight(Serial.read(), Serial.read());
    }
  }
}

void ResetLights()
{
  digitalWrite(RED_1, LOW);
  digitalWrite(YELLOW_1, LOW);
  digitalWrite(GREEN_1, HIGH);
  
  digitalWrite(RED_2, LOW);
  digitalWrite(YELLOW_2, LOW);
  digitalWrite(GREEN_2, HIGH);
  
  digitalWrite(RED_3, LOW);
  digitalWrite(GREEN_3, HIGH);
  
  digitalWrite(RED_4, LOW);
  digitalWrite(GREEN_4, HIGH);
}

void SetLight(byte trafficLightNumber, byte trafficLightState)
{
  digitalWrite(35 + ((trafficLightNumber - 1) * 2), trafficLightState);
}

void timerTick()
{
  if (digitalRead(33) == 1)
  {
    Serial.write(RESET);
  }
}

