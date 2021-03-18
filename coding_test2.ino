#define BLYNK_PRINT Serial


#include <BlynkSimpleStream.h>
#include <SoftwareSerial.h>


char auth[] = "YourAuthToken";

SoftwareSerial SwSerial(10, 11); // RX, TX

BlynkTimer timer;

void myTimerEvent()
{
  Blynk.virtualWrite(V5, millis() / 1000);
}

void setup()
{
  Serial.begin(9600);

  SwSerial.begin(9600);
  Blynk.begin(SwSerial, auth);

  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run();
}
