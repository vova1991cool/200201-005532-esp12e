#include "ISetHendler.h"

void MyDataBox::init()
{
	EEPROM.begin(DATA_SIZE + 10);
	Serial.print(F("Reading 0 bit: ")); 
	Serial.println(EEPROM.read(0));
	if(EEPROM.read(0) != 1) {
		_setDeff();
	}else EEPROM.get(5, data);
	Serial.println(data);
	EEPROM.end();
}

void MyDataBox::fromString(char* source){
	Serial.println(source);
	StaticJsonBuffer<DATA_SIZE * 2> _buffer;
	_commit(_buffer.parseArray(source));
}

void MyDataBox::_setDeff() {
	StaticJsonBuffer<DATA_SIZE * 2> _buff;
	_commit(_buff.parseArray("[0,\"ESP8266Default\",\"\",\"192.168.1.1\",\"192.168.1.1\",12,14,\"\",0,\"\"]"));
}

static void(*resetFunc) (void) = 0;

void MyDataBox::_commit(JsonArray& data) {
	Serial.println(F("Commit is started:"));
	data.printTo(Serial);
	char buffer[DATA_SIZE];
	data.printTo(buffer, sizeof(buffer));
	EEPROM.begin(DATA_SIZE + 10);
	EEPROM.write(0, 1);
	EEPROM.put(5, buffer); 
	EEPROM.commit();
	delay(200); 
	EEPROM.end();
	resetFunc();
};

MyDataBox dataStruct;