// IGsmHandler.h

#ifndef _IGSMHANDLER_h
#define _IGSMHANDLER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <SoftwareSerial.h>

#define PHONESIZE 12
#define PHONES_DATA_SIZE 128

class GsmHendlerClass:public SoftwareSerial
{
private:
	char phoneNum[10][PHONESIZE]; //Phone number field
	size_t phoneCount;
	uint8_t _currentNum;
	uint8_t recordID; //id of playing record field
	char _buffer[150]; //buffer for recived commands
	uint8_t _index; //index for placed command in buffer
	char ussd[10];

	void _waitCommandsExec(uint32 _time); //commands result waiting method
	void _myDelay(uint32 _delay); //delay with millis(dont stop controller)

	void _sendATCommand(const char* command, char* _respDest); //method for sending commands and waiting result(can be deleted)
	void _commandsHendler(char* _data); //method for parsing events

	void _startCall(); //begin call current number
	void _parseNumbersArr(const char *_data);

public:
	GsmHendlerClass(uint8_t rxpin, uint8_t txpin,const char *phone, uint8_t _recordID, const char* _ussd); //constructor
	void runAndCall(); //loop method for exec

};

#endif