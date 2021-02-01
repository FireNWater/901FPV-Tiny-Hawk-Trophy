#include <Adafruit_NeoPixel.h>
#include <WiFiClient.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <901FPV_Tiny_Hawk_HTML_is_in_here.h>          //Modify this file to update current and past Champioms!!

const char* ssid     = "901FPV_Fly_Fi";
const char* password = "901FPV_Fly_Fi";

ESP8266WebServer server(80);

#define PIN        12
#define NUMPIXELS 8

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500

void handleRoot() {
  String message = MAIN_page;
  server.send(200, "text/html", message);
}

void setup() {
  Serial.begin(9600);                           // Start serial port

  WiFi.mode(WIFI_AP);                           //Only Access point
  WiFi.softAP(ssid, password);                  // Set up ESP8266 to be WiFi access point

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.on("/", handleRoot);
  server.begin();

  pixels.begin();                               // Begin coolio chick-magnet light display
}

void loop() {

  pixels.clear();

  delay(DELAYVAL);

  for(int i=0; i<NUMPIXELS; i++) {

    pixels.setPixelColor(i, pixels.Color(255, 250, 255));
    pixels.show();
    delay(DELAYVAL);
  }

  Serial.print("Congratulations Dream_Z!!!\n");
  delay(1000);
  Serial.print("Current 901FPV Tiny Hawk Champiom!!!\n");

  server.handleClient();                        // Web server

}
