const int boton = 4; // Pin del botón
const int leds[] = {8, 9, 10, 11}; // Pines de los LEDs
int ledActual = 0; // Almacena el LED actualmente encendido
bool estadoBotonAnterior = LOW; // Estado anterior del botón
unsigned long ultimoCambio = 0; // Almacena el tiempo de la última pulsación
const unsigned long debounceDelay = 50; // Tiempo de espera para el debounce (50ms)

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT); // Configura los pines de los LEDs como salida
    digitalWrite(leds[i], LOW); // Asegura que todos los LEDs estén apagados al inicio
  }
  pinMode(boton, INPUT); // Configura el pin del botón como entrada
}

void loop() {
  bool estadoBotonActual = digitalRead(boton); // Lee el estado del botón
  unsigned long tiempoActual = millis(); // Obtiene el tiempo actual en milisegundos

  // Si hay un cambio en el estado del botón y ha pasado el tiempo de debounce
  if (estadoBotonActual == HIGH && estadoBotonAnterior == LOW && (tiempoActual - ultimoCambio) > debounceDelay) {
    // Apaga el LED actual
    digitalWrite(leds[ledActual], LOW);

    // Avanza al siguiente LED (si es el último, vuelve al primero)
    ledActual = (ledActual + 1) % 4;

    // Enciende el nuevo LED
    digitalWrite(leds[ledActual], HIGH);

    // Guarda el tiempo actual como referencia para el debounce
    ultimoCambio = tiempoActual;
  }

  // Actualiza el estado del botón anterior para la siguiente lectura
  estadoBotonAnterior = estadoBotonActual;
}
