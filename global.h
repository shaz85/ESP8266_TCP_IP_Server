/**
  ******************************************************************************
  * @file    global.h
  * @author  Muhammad Shahzad   itzshahzad@gmail.com
  * @version V1.0
  * @date    09-Feb-2018
  * @brief   Main Header File
  ******************************************************************************
  The file include Golbal variables and pins
  ******************************************************************************
  */

int RELAY_1_PIN = 16;
int RELAY_2_PIN = 5;
int RELAY_3_PIN = 4;
int RELAY_4_PIN = 0;

int SERIAL_AP_CONFIG_PIN = 2;
int BOARD_STATUS_LED_PIN = 14;

char u_ssid[30],u_password[30];

char data_array[200],arr_cnt;
int cnt_btn_pressed = 0;

class devices{
  public:
    char relay_status=0;

};

  //Ticker Library