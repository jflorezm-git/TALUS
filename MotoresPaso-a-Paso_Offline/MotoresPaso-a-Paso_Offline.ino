#define x_paso 32  // Define el Pin de STEP para Motor de eje X
#define x_dire 33  // Define el Pin de DIR  para Motor de eje X

int retardo = 2000;  // Menor número, el giro es más rápido
int dir = -1; 

void setup() {
  pinMode(x_paso, OUTPUT);
  pinMode(x_dire, OUTPUT);
  Serial.begin(9600);
}

void loop() {
    if (Serial.available() > 0) {  // Verifica si hay datos disponibles para leer
    delay(10);
    int input = Serial.parseInt();  // Lee el valor del monitor serial
    if (input == 0 || input == 1) {  //Solo actualiza la dirección si el input es 0 o 1
      dir = input;
      Serial.println(input);
    }
     while (Serial.available() > 0) {  // Limpia el buffer serial
      Serial.read();
    }
  }
if (dir != -1) {  // Si la dirección no es -1, gira el motor
    giro(x_paso, x_dire, dir);
  }
}

void giro(int paso_, int dire_, int dir) {
  if (dir == 0) {
    digitalWrite(dire_, LOW);  // dirección de giro 0
  } else if (dir == 1) {
    digitalWrite(dire_, HIGH);  // dirección de giro 1
  }

  digitalWrite(paso_, HIGH);
  delayMicroseconds(retardo);
  digitalWrite(paso_, LOW);
  delayMicroseconds(retardo);
}