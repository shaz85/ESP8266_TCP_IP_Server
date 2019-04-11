#include <EEPROM.h>
void initlization(){
  int i=0;
  Serial.begin(115200);
  EEPROM.begin(512);
  pinMode(SERIAL_AP_CONFIG_PIN, INPUT);
  pinMode(BOARD_STATUS_LED_PIN, OUTPUT);
  
  pinMode(RELAY_1_PIN, OUTPUT);
  pinMode(RELAY_2_PIN, OUTPUT);
  pinMode(RELAY_3_PIN, OUTPUT);
  pinMode(RELAY_4_PIN, OUTPUT);

  int len =0;
  int address = 0;
  Serial.println("EEPROM settins");
  len = EEPROM.read(address++);
  if(len>0){
    for( i=0; i<len;i++){
      char rec = EEPROM.read(address++);   
      u_ssid[i] = rec;   
    }u_ssid[i]=0;
    i=0;
    len = EEPROM.read(address++);
    if(len>0){
      for( i=0; i<len;i++){
        char rec = EEPROM.read(address++);       
        u_password[i]= rec;       
    }u_password[i]=0;
    Serial.println("Done");
  
  }}
  
}

void save_setting(){
  EEPROM.begin(512);
  Serial.println(data_array);
  char i;
  char *ptr;
  char *ptr2nd;
  
  
  if(strlen(data_array)>10){
    ptr = strstr(data_array, "SSID");
    ptr2nd =  strstr(data_array,"PASSWORD");
    ptr2nd -=1;
    if(ptr!=0 && ptr2nd !=0){
      ptr +=5;
      for( i=0; i<30; i++){
        if(ptr == ptr2nd){u_ssid[i]=0; break;}
        u_ssid[i] = *ptr; ptr++; 
      }
      i=0;
      
      ptr2nd +=10;
      while(*ptr2nd!=0 && i <30){
      u_password[i++] = *ptr2nd;
      ptr2nd++;
    }
    u_password[i++] =0;     
    
    Serial.print(u_password);
    Serial.print(u_ssid);
    int len =0;
  int address = 0;
    EEPROM.write(address++, strlen(u_ssid));
    for(int i=0; i<strlen(u_ssid); i++){
      EEPROM.write(address++, u_ssid[i]);
    }

    EEPROM.write(address++, strlen(u_password));
    for(int i=0; i<strlen(u_password); i++){
      EEPROM.write(address++, u_password[i]);
    }

    EEPROM.commit();
    }
    
  }
  
  
}
