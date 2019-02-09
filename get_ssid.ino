void get_new_ssid(){
  //SSID mitto net 03226600046 PASSWORD shahzad786
  Serial.println("Enter new SSID and password in user defined format");
  while(1){
    if(Serial.available()){
      char ch = Serial.read();
      if(ch == 10 | ch == 13){
        save_setting();
        //resetFun();
        break;
      }
      data_array[arr_cnt++] = ch;
    }
  }
}