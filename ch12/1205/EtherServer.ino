#include <Ethernet.h>

// network configuration.  gateway and subnet are optional.
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// byte gateway[] = { 10, 0, 0, 1 };
//byte subnet[] = { 255, 255, 0, 0 };

// HTTP uses port 80 by default
Server server = Server(80);

void setup()
{
    // initialize the ethernet device
    //Ethernet.begin(mac, ip, gateway, subnet); // with subnet, ie through router
    Ethernet.begin(mac, ip); // without subnet, ie directly to modemå
    // start listening for clients
    server.begin();
}

void loop()
{
Client client = server.available();
    if (client) {
        server.println("HTTP/1.1 200 OK");
        server.println("Content-Type: text/html");
        server.println();
        server.println("Hello World!");
    }
}