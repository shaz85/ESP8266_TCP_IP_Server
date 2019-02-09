/*
    This sketch establishes a TCP connection to a "quote of the day" service.
    It sends a "hello" message, and then prints received data.
*/
#include "global.h"
#define RELAY_1_PIN 16
#define RELAY_2_PIN 5
#define RELAY_3_PIN 4
#define RELAY_4_PIN 0

#define SERIAL_AP_CONFIG_PIN 2
#define BOARD_STATUS_LED_PIN 14

#define 
#include <ESP8266WiFi.h>
#include <Ticker.h>  //Ticker Library

void changeState()
{
  digitalWrite(LED, !(digitalRead(LED)));  //Invert Current State of LED  
}

#ifndef STASSID
#define STASSID "mitto net 03226600046"
#define STAPSK  "shahzad786"
#endif
WiFiServer server(11000);

const char* ssid     = STASSID;
const char* password = STAPSK;
char u_ssid[30],u_password[30];

char data_array[200],arr_cnt;

  /**
  * ***************************************************************************
  * ******************************** Setup ************************************
  * ***************************************************************************
  */
void setup() {
  Serial.begin(115200);
  initlization();

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(u_ssid);

  /* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
     would try to act as both a client and an access-point and could cause
     network-issues with your other WiFi-devices on your WiFi-network. */
  WiFi.mode(WIFI_STA);
  WiFi.begin(u_ssid, u_password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
  while(1){
    if(Serial.available()){
      char ch = Serial.read();
      if(ch == 10 | ch == 13){
        save_setting();
        break;
      }
      data_array[arr_cnt++] = ch;
    }
  }
}

  /**
  * ***************************************************************************
  * ******************************** Main Function ****************************
  * ***************************************************************************
  */

void loop(){
  int i=0;
  
  WiFiClient client = server.available();
  if(Serial.available()){
    client.write(Serial.read());
  }
  if (client) {
    Serial.println("Server is available");
    while (client.connected()) {
    i++;
    if(i>2000){
      i=0;
      Serial.print("client is connected");
    }
      while (client.available()>0) {
        char c = client.read();
        Serial.write(c);
      }
      if(Serial.available()){
        client.write(Serial.read());
      }
 
      delay(1);
    }    

  }
}
