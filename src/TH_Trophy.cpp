#include <Adafruit_NeoPixel.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid     = "901FPV_Fly_Fi";
const char* password = "901FPV_Fly_Fi";

ESP8266WebServer server(80);

#define PIN         12
#define NUMPIXELS   8
#define DELAYVAL    100

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void handleRoot() {
  server.send(200, "text/html", "<center><h1>Congratulations DreamZ!! <br> 901FPV Tiny Hawk Champiom!!</h1></center>");
}

void setup() {
  Serial.begin(9600);                           // Start serial port

  WiFi.softAP(ssid, password);                  // Set up ESP8266 to be WiFi access point

  Serial.print("AP IP address: ");              // Print web page IP address to serial port.  
  Serial.println(WiFi.softAPIP());              //  Default is: 192.168.4.1
  Serial.print("Server MAC address: ");
  Serial.println(WiFi.softAPmacAddress());

  server.on("/", handleRoot);
  server.begin();

  pixels.begin();                               // Begin coolio chick-magnet light display
}

void loop() {

  pixels.clear();

  for(int i=0; i<NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(random(255), random(255), random(255)));
    pixels.show();
    delay(DELAYVAL);
  }

  Serial.print("Congratulations Dream_Z!!!\n");
  Serial.print("Current 901FPV Tiny Hawk Champiom!!!\n");

  server.handleClient();                          // Web server

}
