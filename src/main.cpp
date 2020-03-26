/*
 Name:		Collector.ino
 Created:	11.12.2019 14:28:15
 Author:	vova1
*/

// the setup function runs once when you press reset or power the board
#include <EEPROM.h>
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.hpp>
#include <ArduinoJson.h>
#include "IServerProcess.h"
#include "IGsmHandler.h"

#define RESET_PIN 4

bool handle_gsm;
GsmHendlerClass *gsm;

void setup() {
	Serial.begin(115200);
	Serial.println("Start!");

	pinMode(RESET_PIN, INPUT);
	
	//dataStruct._setDeff();
	dataStruct.init();

	DynamicJsonBuffer _buff;
	char _dataBuff[DATA_SIZE];
	strcpy(_dataBuff, dataStruct.data);
	JsonArray &_data = _buff.parseArray(_dataBuff);

	IServerProcess.init(_data);

	handle_gsm = _data[PHONE].measureLength() > 9;

	if(handle_gsm) gsm = new GsmHendlerClass(_data[GSM_TX],_data[GSM_RX], _data[PHONE], _data[REC_ID], _data[USSD]);
}

// the loop function runs over and over again until power down or reset
void loop() {
	//Server clients hendler
	IServerProcess.clientsHendler();
	//Reset to def. pin hendler
	if(!digitalRead(RESET_PIN)) dataStruct._setDeff();
	//GSM calling hendler
	if(handle_gsm) gsm->runAndCall();
}