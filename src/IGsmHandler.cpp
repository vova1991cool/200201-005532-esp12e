// 
// 
// 

#include "IGsmHandler.h"

GsmHendlerClass::GsmHendlerClass(uint8_t rxpin, uint8_t txpin,const char *phone, uint8_t _recordID, const char* _ussd):SoftwareSerial(txpin, rxpin){
	//strcpy(phoneNum, phone);
	char tempStr[256];
	size_t index = 0;
	strcpy(tempStr, phone);
	char *pch = strtok(tempStr, " ,;");
	while (pch != NULL)
	{
		strcpy(phoneNum[index++], pch);
		pch = strtok(NULL, " ,;");
	}
	phoneCount = --index;
	Serial.printf("Count of phones: %d\n", phoneCount);
	Serial.println(phoneNum[0]);
	Serial.println(phoneNum[phoneCount]);
	strcpy(ussd, _ussd);
	Serial.printf("Current number is: %s\n", phoneNum[0]);
	recordID = _recordID;
	this->begin(9600);
	_myDelay(7000);
	//_sendATCommand("ATE0"); //Need to be configure and save settings in GSM
	char _status[50];
	while (!strstr(_status, "+CPAS: 0"))
	{
		_myDelay(2000);
		_sendATCommand("AT+CPAS", _status);
		Serial.printf("CPAS: %s\n", _status);
	}
//	_sendATCommand("AT+COLP=1"); //Need to be configure and save settings in GSM
	_index = 0;
	_myDelay(1000);
//	_sendATCommand("AT&W"); //Need send to save configured settings
	_startCall();
}

void GsmHendlerClass::runAndCall(){
	
	while (this->available())
	{
		char _currCh = this->read();
		_buffer[_index++] = _currCh;
		if (_currCh == '\n')
		{
			_buffer[_index - 1] = '\0';
			if (_index > 2) _commandsHendler(_buffer);
			_index = 0;
		}
	}
}

void GsmHendlerClass::_commandsHendler(char* _data){
	Serial.println(_data);
	if(strstr(_data, "+COLP: ")){
	//	Serial.printf("AT+CREC=4,\"C:\\User\\%d.amr\",0,90\n", recordID);
		this->printf("AT+CREC=4,\"C:\\User\\%d.amr\",0,90\n", recordID);
	}else if(strstr(_data, "+CREC: 0")){
		 this->println("ATH");
		 _startCall();
	}else if(strstr(_data, "NO CARRIER")) _startCall();
	else if(strstr(_data, "BUSY")) _startCall();
}

void GsmHendlerClass::_startCall(){
	if(_currentNum > phoneCount) _currentNum = 0;
	_myDelay(1500);
	this->printf("ATD%s+38%s;\n", ussd, phoneNum[_currentNum++]);
}

void GsmHendlerClass::_sendATCommand(const char* command, char* Dest){
	Serial.println(command);
	this->println(command);

	_waitCommandsExec(3000);

	uint8_t index = 0;
	if(this->available()){
		while (this->available())
		{
			Dest[index++] = this->read();
		}
		Dest[index] = '\0';
	}else strcpy(Dest, "Timeout");
}

void GsmHendlerClass::_waitCommandsExec(uint32 _time){
	unsigned long _timeout = millis() + _time;
	while (!this->available() && millis() < _timeout){}
}

void GsmHendlerClass::_myDelay(uint32 _delay){
	unsigned long _timeout = millis() + _delay;
	while (millis() < _timeout){ delay(15); }
}
