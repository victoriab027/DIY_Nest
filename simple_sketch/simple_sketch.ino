#include <TimeLib.h> //include the time library
#include <WiFiNINA.h> // wifi library

char ssid[] = "noskv";             //  your network SSID (name) 
char pass[] = "ilovegnomes";      // your network password between the " "

WiFiServer server(80);    //server socket
WiFiClient client = server.available();

const int UP = 8;
const int DOWN = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(UP,OUTPUT);
  pinMode(DOWN,OUTPUT);

  while (!Serial);
  enable_WiFi();
  connect_WiFi();
  server.begin();
  printWifiStatus();

  // for testing 
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(UP,HIGH);
  Serial.println(hour());

  client = server.available();
  if (client) {
    printWEB();
  }

}

