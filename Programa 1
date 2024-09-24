const int boton = 4; // Pin del botón
const int leds[] = {8, 9, 10, 11}; // Pines de los LEDs
bool estadoBotonAnterior = LOW; // Estado previo del botón
bool estadoLed = LOW; // Estado de los LEDs (apagado al inicio)

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT); // Configura los pines de los LEDs como salida
    digitalWrite(leds[i], LOW); // Asegúrate de que todos los LEDs estén apagados al inicio
  }
  pinMode(boton, INPUT); // Configura el pin del botón como entrada
}

void loop() {
  bool estadoBotonActual = digitalRead(boton); // Lee el estado actual del botón

  // Detecta si el botón ha sido presionado (cambio de LOW a HIGH)
  if (estadoBotonActual == HIGH && estadoBotonAnterior == LOW) {
    // Cambia el estado de los LEDs (si estaban encendidos, apaga; si estaban apagados, enciende)
    estadoLed = !estadoLed;

    // Enciende o apaga todos los LEDs según el nuevo estado
    for (int i = 0; i < 4; i++) {
      digitalWrite(leds[i], estadoLed ? HIGH : LOW); // Enciende si estadoLed es HIGH, apaga si es LOW
    }
  }

  // Actualiza el estado del botón anterior para la siguiente lectura
  estadoBotonAnterior = estadoBotonActual;
}
