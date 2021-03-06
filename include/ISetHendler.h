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

/*[0,"dsfgdgs","234235","192.168.1.1","255.255.255.0",1,1,"0965622167",0,"#31#"]*/

#define DATA_SIZE 256

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
		const char *_getDataToParse() { return data; };

		char data[DATA_SIZE]; //global settings buffer

		void fromString(char* source); //parcing from string and place to EEPROM

		void init(); //settings initialization

		void _setDeff(); //seting defoult

		void _commit(JsonArray &data); //method for commiting

	};

	const size_t _dataSize = sizeof(MyDataBox) + 10;

    extern MyDataBox dataStruct;
#endif