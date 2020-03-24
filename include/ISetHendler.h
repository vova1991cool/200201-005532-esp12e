// ISetHendler.h

#ifndef _ISETHENDLER_h
#define _ISETHENDLER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <EEPROM.h>
#include "ArduinoJson.h"

#define DATA_SIZE 384
/*SETTINGS ENUM*/
enum dataIndexEnum{
	MODE,
	SSID,
	PASS,
	HOST,
	GATEWAY,
	GSM_RX,
	GSM_TX,
	PHONE,
	REC_ID,
	USSD
};

struct MyDataBox
	{
		char data[DATA_SIZE]; //global settings buffer

		void fromString(char* source); //parcing from string and place to EEPROM

		void init(); //settings initialization

		void _setDeff(); //seting defoult

		void _commit(JsonArray &data); //method for commiting

	};

	const size_t _dataSize = sizeof(MyDataBox) + 10;

    extern MyDataBox dataStruct;
#endif