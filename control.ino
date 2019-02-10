
void action_recieved_cmd(){
	char ON = 1, OFF = 0;

	for(int i=0; i<200;i++){
		esp_ack_reply[i] = 0;
	}
	for(int i=0; i<strlen(recieved_str); i++){
		if((int) islower(recieved_str[i])){
			recieved_str[i] = toupper(recieved_str[i]);
		}
	}
	
	//Serial.println(recieved_str);

	if(strstr(recieved_str, "RELAY1 ON")!=0){
		Serial.println("Relay1 ON");
		dev1.relay_status = 1;
		digitalWrite(RELAY_1_PIN, HIGH);
		strcat_function(1, ON);
	}
	else if(strstr(recieved_str, "RELAY1 OFF")!=0){
		Serial.println("Relay1 OFF");
		dev1.relay_status = 0;
		digitalWrite(RELAY_1_PIN, LOW);	
		strcat_function(1, OFF);	
	}
	else if(strstr(recieved_str, "RELAY2 ON")!=0){
		Serial.println("Relay2 ON");
		dev2.relay_status = 1;
		digitalWrite(RELAY_2_PIN, HIGH);
		strcat_function(2, ON);		
	}
	else if(strstr(recieved_str, "RELAY2 OFF")!=0){
		Serial.println("Relay2 OFF");
		dev2.relay_status = 0;
		digitalWrite(RELAY_2_PIN, LOW);	
		strcat_function(2, OFF);	
	}
	else if(strstr(recieved_str, "RELAY3 ON")!=0){
		Serial.println("Relay3 ON");
		dev3.relay_status = 1;
		digitalWrite(RELAY_3_PIN, HIGH);
		strcat_function(3, ON);
	}
	else if(strstr(recieved_str, "RELAY3 OFF")!=0){
		Serial.println("Relay3 OFF");
		dev3.relay_status = 0;
		digitalWrite(RELAY_3_PIN, LOW);
		strcat_function(3, OFF);
	}
	else if(strstr(recieved_str, "RELAY4 ON")!=0){
		Serial.println("Relay4 ON");
		dev4.relay_status = 1;
		digitalWrite(RELAY_4_PIN, HIGH);
		strcat_function(4, ON);
	}
	else if(strstr(recieved_str, "RELAY4 OFF")!=0){
		Serial.println("Relay4 OFF");
		dev4.relay_status = 0;
		digitalWrite(RELAY_4_PIN, LOW);
		strcat_function(3, OFF);
	}

	else if(strstr(recieved_str, "STATUS")!=0){
		Serial.println("Send status to the device");
		strcat_function(255, 0);	
		
	}
	
	for(int i=0; i<sizeof(recieved_str); i++){		
		recieved_str[i] = 0;
		
	}


}


void strcat_function(char s_no, char format){
	char ON=1;
	if(s_no == 255){
		if(dev1.relay_status == ON ){
				strcat(esp_ack_reply, "device 1 is ON\r\n");		
			}
			else strcat(esp_ack_reply, "device 1 is OFF\r\n");

			if(dev2.relay_status == ON ){
				strcat(esp_ack_reply, "device 2 is ON\r\n");
			}
			else strcat(esp_ack_reply, "device 2 is OFF\r\n");

			if(dev3.relay_status == ON ){
				strcat(esp_ack_reply, "device 3 is ON\r\n");
			}
			else strcat(esp_ack_reply, "device 3 is OFF\r\n");

			if(dev4.relay_status == ON ){
				strcat(esp_ack_reply, "device 4 is ON\r\n");
			}
			else strcat(esp_ack_reply, "device 4 is OFF\r\n");
		
	}
	else if(s_no == 1){
		if(format == 1) strcat(esp_ack_reply, "device 1 is ON\r\n");
		else strcat(esp_ack_reply, "device 1 is OFF\r\n");

	}
	else if(s_no == 2){
		if(format == 1) strcat(esp_ack_reply, "device 2 is ON\r\n");
		else strcat(esp_ack_reply, "device 2 is OFF\r\n");
		
	}
	else if(s_no == 3){
		if(format == 1) strcat(esp_ack_reply, "device 3 is ON\r\n");
		else strcat(esp_ack_reply, "device 3 is OFF\r\n");
		
	}
	else if(s_no == 4){
		if(format == 1) strcat(esp_ack_reply, "device 4 is ON\r\n");
		else strcat(esp_ack_reply, "device 4 is OFF\r\n");
		
	}
	

}