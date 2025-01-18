#include <arduino.h>
int pinVermelho = 10, pinAmarelo = 9, pinVerde = 8, pinBotao = 7;
int pinVermelhoPedest = 6, pinVerdePedest = 5;
int fasesemaforo;
int estadobotao, estadoAnteriorBotao;
int estadoPisca, tempoPisca;

void setup()
{
  pinMode(pinVermelho, OUTPUT);
  pinMode(pinAmarelo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinBotao, INPUT);
  pinMode(pinVermelhoPedest, OUTPUT);
  pinMode(pinVerdePedest, OUTPUT);

  fasesemaforo = 1;
  tempoPisca = 0;
  estadoPisca = HIGH;
  estadoAnteriorBotao = digitalRead(pinBotao);
}

void loop()
{
  estadobotao = digitalRead(pinBotao);

  if ((estadobotao == LOW) && (estadoAnteriorBotao == HIGH))
  {
    if (fasesemaforo < 4)
    {
      fasesemaforo += 1;
    }
    else
    {
      fasesemaforo = 1;
    }
  }
  estadoAnteriorBotao = estadobotao;

  if (fasesemaforo == 1)
  {
    digitalWrite(pinVerde, HIGH);
    digitalWrite(pinAmarelo, LOW);
    digitalWrite(pinVermelho, LOW);
    digitalWrite(pinVermelhoPedest, HIGH);
    digitalWrite(pinVerdePedest, LOW);
  }

  if (fasesemaforo == 2)
  {
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAmarelo, HIGH);
    digitalWrite(pinVermelho, LOW);
    digitalWrite(pinVermelhoPedest, HIGH);
    digitalWrite(pinVerdePedest, LOW);
  }

  if (fasesemaforo == 3)
  {
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAmarelo, LOW);
    digitalWrite(pinVermelho, HIGH);
    digitalWrite(pinVermelhoPedest, LOW);
    digitalWrite(pinVerdePedest, HIGH);
  }
  if (fasesemaforo == 4)
  {
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAmarelo, LOW);
    digitalWrite(pinVermelho, HIGH);
    tempoPisca += 1;
    if (tempoPisca == 400)
    {
      estadoPisca = !estadoPisca;
      tempoPisca = 0;
    }
    digitalWrite(pinVermelhoPedest, estadoPisca);
    digitalWrite(pinVerdePedest, LOW);
  }
  delay(1);
}
