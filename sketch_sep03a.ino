const int boton = 4; 
const int leds[] = {8, 9, 10,11}; 
int contador = 0; // Almacena el valor binario actual
bool estadoBotonAnterior = LOW;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(boton, INPUT);
}

void loop() {
  bool estadoBoton = digitalRead(boton);
  
  if (estadoBoton == HIGH && estadoBotonAnterior == LOW) {
    contador = (contador + 1) % 15; // Incrementa el contador y lo reinicia en 0 después de 15
    for (int i = 0; i < 4; i++) {
      digitalWrite(leds[i], bitRead(contador, i)); // Actualiza los LEDs con el valor binario del contador
    }
  }

  estadoBotonAnterior = estadoBoton;
}
