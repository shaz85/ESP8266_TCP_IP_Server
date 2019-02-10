/*
    This sketch establishes a TCP connection to a "quote of the day" service.
    It sends a "hello" message, and then prints received data.
*/
#include "global.h"
#include <ESP8266WiFi.h>
#include <Ticker.h>
Ticker blinker;
char esp_ack_reply[200];
void (*resetFun)(void)=0;

devices dev1, dev2, dev3, dev4; 
WiFiClient client;

/*IPAddress ip(192, 168, 0, 200); //ESP static ip
IPAddress gateway(192, 168, 0, 1);   //IP Address of your WiFi Router (Gateway)
IPAddress subnet(255, 255, 255, 0);  //Subnet mask
IPAddress dns(8, 8, 8, 8);
*/
//IPAddress ip(192, 168, 0, 220);
char flag_led=0, cnt;
void soft_isr(){

  if(digitalRead(SERIAL_AP_CONFIG_PIN)==0)
    cnt_btn_pressed++; 

}

WiFiServer server(11000);
char recieved_str[50] ;

  /**
  * ***************************************************************************
  * ******************************** Setup ************************************
  * ***************************************************************************
  */
void setup() {
  
  initlization();

  Serial.print("Connecting to ");
  Serial.println(u_ssid);
  blinker.attach(0.05, soft_isr);
  //WiFi.disconnect();

  /* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
     would try to act as both a client and an access-point and could cause
     network-issues with your other WiFi-devices on your WiFi-network. */
  WiFi.mode(WIFI_STA);
 // WiFi.config(ip, subnet, gateway);//, dns);//, subnet, gateway, dns);
  WiFi.begin(u_ssid, u_password);
  int i=0;

  while (WiFi.status() != WL_CONNECTED && i < 40) {
    //WiFi.begin(u_ssid, u_password);
    delay(10000);
    Serial.print(".");
    i++;
    if(cnt_btn_pressed > 100)
      get_new_ssid();    
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
 // WiFi.config(ip);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
  
}

  /**
  * ***************************************************************************
  * ******************************** Main Function ****************************
  * ***************************************************************************
  */

void loop(){
  static int i=0;
  delay(1);  i++;
  //Serial.print(i);

  if(i>999){
    i=0;
    digitalWrite(BOARD_STATUS_LED_PIN, !digitalRead(BOARD_STATUS_LED_PIN));
  }
  
  WiFiClient client = server.available();

  if(cnt_btn_pressed > 20)
      get_new_ssid(); 

  if(Serial.available()){
    client.write(Serial.read());
  }
  if (client) {
    Serial.println("Server is available");
    digitalWrite(BOARD_STATUS_LED_PIN, HIGH);
    
    int cnt=0;
    while (client.connected()) {
  
      if(cnt_btn_pressed > 100)
        get_new_ssid(); 
      
      while (client.available() > 0) {
        char c = client.read();
        if(c == 10 || c==13 || cnt > 48){
          action_recieved_cmd();
          if(strlen(esp_ack_reply) >0)
            client.println(esp_ack_reply);
          recieved_str[cnt]=0;
          cnt=0;
        }
        else recieved_str[cnt++] =c;
        
        //client.write(c);
        //Serial.write(c);
      }
      if(Serial.available()){
        client.write(Serial.read());
      }       
    }  
  }
}
