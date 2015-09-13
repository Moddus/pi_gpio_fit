#include <wiringPi.h>
#include <stdio.h>

#define PIN 29

int main() {

  if (wiringPiSetup() == -1)
    return 1;

  pinMode(PIN, OUTPUT);
  while(1) {
    digitalWrite(PIN, 1);
    delay(100);
    digitalWrite(PIN, 0);
    delay(100);
  }
}
