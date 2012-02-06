#include "WiFly.h"
#include "Credentials.h"

// we ultimately want something that looks like this:
// http://api.pachube.com/v2/feeds/1977/datastreams/1
Client client("pachube.com", 80);

TinyXML txml;
uint8_t buffer[150];
uint16_t buflen = 150;
const char API_KEY = "PUT YOUR API KEY HERE";

bool tryToConnect;

void setup() {
  
  tryToConnect = true;
  Serial.begin(9600);

  txml.init((uint8_t*)&buffer,buflen,&XML_callback);
  WiFly.begin();
  
  if (!WiFly.join(ssid, passphrase)) {
    Serial.println("Association failed.");
    while (1) {
      // Hang on failure.
    }
  }  

  Serial.println("connecting...");

  if (client.connect()) {
    Serial.println("connected");
    client.print("X-PachubeApiKey:");
    client.println(API_KEY);
    client.println("GET /v2/feeds/1977/datastreams/1");
    client.println();
  } else {
    Serial.println("connection failed");
  }
  
}

void loop() {
if( tryToConnect) {

  if (client.available()) {
    char c = client.read();
    xml.processChar(c);
  }
  
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    tryToConnect = false;
  }
}
}

void XML_callback( uint8_t statusflags, char* tagName,  uint16_t tagNameLen,  char* data,  uint16_t dataLen ) {
  if (statusflags & STATUS_TAG_TEXT)
  {
    if(strcmp(tagName, "current_value")  == 0)
    {
      Serial.println("data is ");
      Serial.println(data);
    }

  }
}
