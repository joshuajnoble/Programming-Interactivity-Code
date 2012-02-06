#include <Ethernet.h>
bool connected = false;

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 192,168,0,51 }; // make sure this address is free on your
                                // network and is appropriate for your router
byte serverIp[] = {64, 233, 187, 99}; // this is googles address</programlisting>


Client client(serverIp, 80);

void setup() {
    //initialize the Ethernet library
    Ethernet.begin(mac, ip);
    Serial.start(9600);

}

void loop()
{
 if(!connected) {
       if (client.connect()) {
           connected = true;
           Serial.println("connected");

           // you could also change this line to anything else
           // "GET /search?q=programming+interactivity HTTP/1.1" for example
           client.println("GET /search?q=arduino HTTP/1.1");
           client.println("Host: www.google.com");
           // say who you are, just like in the Processing example
           client.println("User-Agent: AVR ethernet");
           client.println("Accept: text/html");
           // then insert an empty line
           client.println();
       } else {
           Serial.println(" can't connect ");
           delay(500);
       }

    } else {
   if (client.available()) {
        char c = client.read();
        Serial.print(c);
    }
}