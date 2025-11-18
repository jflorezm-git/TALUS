
#include <WiFi.h>
const char* ssid     = "";  // <- Cambiar por el nombre de su Red WiFi                                                                                                                                                                                                              <
const char* password = "";  // <- Cambiar por la clave de su Red WiFi 

String pagina1 = "<!DOCTYPE.html>"
"<html>"
"<head>"
"<meta charset='utf-8' />"
"<title>Servidor Local ESP32</title>"
"</head>"
"<body>"
"<center>"
"<h1>Servidor Local</h1>"
"<p><a href='/R1\'><button style='height:100px;width:200px'><h1>RIGHT</h1></button></a></p>"
"<p><a href='/L1\'><button style='height:100px;width:200px'><h1>LEFT</h1></button></a></p>"
"</center>"
"</body>"
"</html>";

WiFiServer server(80);

#define x_paso 32    // Define el Pin de STEP para Motor de eje X
#define x_dire 33   // Define el Pin de DIR  para Motor de eje X
int dir= -1;
int retardo = 3000;   // Menor numero el giro es mas rapido

void setup()
{
    pinMode(x_paso, OUTPUT); pinMode(x_dire, OUTPUT);   
    Serial.begin(115200);
    delay(10);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    
    server.begin();

}

int value = 0;

void loop(){
 WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print(pagina1);
            //client.print("Click <a href=\"/H\">here</a> to turn the LED on pin 2 on.<br>");
            //client.print("Click <a href=\"/L\">here</a> to turn the LED on pin 2 off.<br>");

            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /R1")) {
          dir = 0;
        }
        if (currentLine.endsWith("GET /L1")) {
          dir = 1;
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
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