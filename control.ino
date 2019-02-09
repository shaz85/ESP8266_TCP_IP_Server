
void action_recieved_cmd(){
	
	Serial.println(recieved_str);
	if(strstr(recieved_str, "Relay1 ON")!=0){
		Serial.println("RECV Rela1 ON");

	}
	else if(strstr(recieved_str, "Relay1 OFF")!=0){
		Serial.println("RECV Rela1 OFF");
		
	}
	else if(strstr(recieved_str, "Relay2 ON")!=0){
		Serial.println("RECV Rela2 OFF");
		
	}
	else if(strstr(recieved_str, "Relay2 OFF")!=0){
		Serial.println("RECV Rela12OFF");
		
	}
	else if(strstr(recieved_str, "Relay3 ON")!=0){
		Serial.println("RECV Rela3 OFF");
		
	}
	else if(strstr(recieved_str, "Relay3 OFF")!=0){
		Serial.println("RECV Rela13 OFF");
		
	}
	else if(strstr(recieved_str, "Relay4 ON")!=0){
		Serial.println("RECV Rela4 OFF");
		
	}
	else if(strstr(recieved_str, "Relay4 OFF")!=0){
		Serial.println("RECV Rela14 OFF");
		
	}
	


}