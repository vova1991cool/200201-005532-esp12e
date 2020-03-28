// 
// 
// 

#include "IServerProcess.h"

void IServerProcessClass::init(JsonArray &_data)
{
	int indexMode = _data[MODE];
	WiFi.mode(indexMode ? WIFI_STA:WIFI_AP);

	
	IPAddress _ip;
	_ip.fromString(_data.get<char*>(HOST));
	IPAddress _gateway;
	_gateway.fromString(_data.get<char*>(GATEWAY));

	if (indexMode) {
		WiFi.config(_ip, _gateway, IPAddress(255,255,255,0));
		WiFi.begin(_data.get<char*>(SSID), _data.get<char*>(PASS));
		Serial.print(F("Try to connect."));
		while (WiFi.status() != WL_CONNECTED)
		{
			Serial.print(".");
			delay(500);
		}
		Serial.print("Connected! IP: ");
		Serial.println(WiFi.localIP());
	}
	else {
		WiFi.softAPConfig(_ip, _gateway, IPAddress(255,255,255,0));
	    WiFi.softAP(_data.get<char*>(SSID), _data.get<char*>(PASS));
	}

	Serial.println(MDNS.begin("mygsmdevice.com", _ip) ? F("mDNS responder started") : F("Error setting up MDNS responder!"));

	begin(80);
	
	on("/", HTTP_GET, []() {
		//Serial.println(HTML_PAGE);
		IServerProcess.send(200, "text/html", HTML_PAGE);
	});

	on(F("/getData"), HTTP_GET, []() {
		Serial.print(F("Sending data to client: "));
		Serial.println(dataStruct._getDataToParse());
		IServerProcess.send(200, "application/json", dataStruct._getDataToParse());
	});

	on("/saveData", HTTP_POST, []() {
		Serial.println("Recive SaveData");
		Serial.println(IServerProcess.arg(0));
		IServerProcess.send(200, "application/text", "ok");
		char buffer[_dataSize];
	    IServerProcess.arg(0).toCharArray(buffer, _dataSize);
		dataStruct.fromString(buffer);
	});

	onNotFound([]() {
		IServerProcess.send(404, "text/plain", F("404: Not Found"));
	});

}

IServerProcessClass IServerProcess;
