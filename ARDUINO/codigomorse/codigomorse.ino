#include <arduino.h>
int pinvermelho = 6;
int timeDot = 500;
int timeDash = 2 * timeDot;

void setup()
{
  Serial.begin(9600);
  pinMode(pinvermelho, OUTPUT);
}

void loop()
{
  if (Serial.available())
  {
    String input = Serial.readStringUntil('\n');
    translateAndBlink(input);
  }
}

void translateAndBlink(String input)
{
  for (int i = 0; i < 3; i++)
  {
    input.toLowerCase();
    for (int i = 0; i < input.length(); i++)
    {
      switch (input[i])
      {
      case 'a':
        blinkDot();
        blinkDash();
        break;
      case 'b':
        blinkDash();
        blinkDot();
        blinkDot();
        blinkDot();
        break;
      case 'c':
        blinkDash();
        blinkDot();
        blinkDash();
        blinkDot();
        break;
      case 'd':
        blinkDash();
        blinkDot();
        blinkDot();
        break;
      case 'e':
        blinkDot();
        break;
      case 'f':
        blinkDot();
        blinkDot();
        blinkDash();
        blinkDot();
        break;
      case 'g':
        blinkDash();
        blinkDash();
        blinkDot();
        break;
      case 'h':
        blinkDot();
        blinkDot();
        blinkDot();
        blinkDot();
        break;
      case 'i':
        blinkDot();
        blinkDot();
        break;
      case 'j':
        blinkDot();
        blinkDash();
        blinkDash();
        blinkDash();
        break;
      case 'k':
        blinkDash();
        blinkDot();
        blinkDash();
        break;
      case 'l':
        blinkDot();
        blinkDash();
        blinkDot();
        blinkDot();
        break;
      case 'm':
        blinkDash();
        blinkDash();
        break;
      case 'n':
        blinkDash();
        blinkDot();
        break;
      case 'o':
        blinkDash();
        blinkDash();
        blinkDash();
        break;
      case 'p':
        blinkDot();
        blinkDash();
        blinkDash();
        blinkDot();
        break;
      case 'q':
        blinkDash();
        blinkDash();
        blinkDot();
        blinkDash();
        break;
      case 'r':
        blinkDot();
        blinkDash();
        blinkDot();
        break;
      case 's':
        blinkDot();
        blinkDot();
        blinkDot();
        break;
      case 't':
        blinkDash();
        break;
      case 'u':
        blinkDot();
        blinkDot();
        blinkDash();
        break;
      case 'v':
        blinkDot();
        blinkDot();
        blinkDot();
        blinkDash();
        break;
      case 'w':
        blinkDot();
        blinkDash();
        blinkDash();
        break;
      case 'x':
        blinkDash();
        blinkDot();
        blinkDot();
        blinkDash();
        break;
      case 'y':
        blinkDash();
        blinkDot();
        blinkDash();
        blinkDash();
        break;
      case 'z':
        blinkDash();
        blinkDash();
        blinkDot();
        blinkDot();
        break;
      default:

        break;
      }
      delay(timeDot);
    }
  }
}

void blinkDot()
{
  digitalWrite(pinvermelho, HIGH);
  delay(timeDot);
  digitalWrite(pinvermelho, LOW);
  delay(timeDot);
}

void blinkDash()
{
  digitalWrite(pinvermelho, HIGH);
  delay(timeDash);
  digitalWrite(pinvermelho, LOW);
  delay(timeDot);
}