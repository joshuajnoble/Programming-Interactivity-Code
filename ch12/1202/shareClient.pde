import processing.net.*;

Server fsSrv;
PFont myFont;
String lastmsg = "";

void setup() {
    size(600, 300);
    fsSrv = new Server(this, 8180);
    myFont = createFont("Arial", 13);
    textFont(myFont);
}

void draw() {
    background(0);
    text("ok", 10, 20);
    Client client = fsSrv.available();
    if(client != null) {        lastmsg = client.readString();        if(lastmsg != null) {            fsSrv.write("<msg>"+lastmsg+"</msg>");        }    }    text(lastmsg, 30, 20);}
void serverEvent(Server srv, Client clt) {    fsSrv.write(picList.toString());}