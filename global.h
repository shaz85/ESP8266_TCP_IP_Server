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

#define RELAY_1_PIN 16
#define RELAY_2_PIN 5
#define RELAY_3_PIN 4
#define RELAY_4_PIN 0

#define SERIAL_AP_CONFIG_PIN 2
#define BOARD_STATUS_LED_PIN 14

char u_ssid[30],u_password[30];

char data_array[200],arr_cnt;
int cnt_btn_pressed = 0;

  //Ticker Library