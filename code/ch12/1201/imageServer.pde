import processing.net.*;

Server fsSrv;
XMLElement flickrXML;
XMLElement picList;
PFont myFont;
String lastmsg = "";

void setup() {

    size(600, 300);
    fsSrv = new Server(this, 8180);
    flickrXML = new XMLElement(this,
    "http://api.flickr.com/services/rest/?method=flickr.photosets.getPhotos&amp;api_key=
        0367b4b7b7ab07af3c04d8d6d839467d&amp;photoset_id=72157594290642861");

    XMLElement pics = flickrXML.getChild(0);
    picList = new XMLElement("<pictures></pictures>");
    // you could use them all, or only use 4
    int totalPics = 4;//pics.getChildCount();
    int xp = −400;
    int yp = 0;

    for(int i = 0; i<totalPics; i++) {
	String url = "http://farm"+pics.getChild(i).getAttribute("farm")+
            ".static.flickr.com/" +pics.getChild(i).getAttribute("server")+
            "/"+pics.getChild(i).getAttribute("id")+"_"+
            pics.getChild(i).getAttribute("secret")+".jpg";
        if(xp > 399 ) {
           xp = 0;
           yp += 400;
      } else {
        xp += 400;
      }
	 picList.addChild(new XMLElement("<pic id=\""+i+"\" url=\""+url+"\" x=\""+xp+"\" y=\""+yp+"\" />"));
    }
    myFont = createFont("Arial", 16);
    textFont(myFont);
}

void draw() {
    background(0);
    text("ok", 10, 20);
    Client client = fsSrv.available();

         
	if(client != null) {
        	lastmsg = client.readString();
        	if(lastmsg != null) {
	            fsSrv.write("<msg>"+lastmsg+"</msg>");
	        }
    	}
    text(lastmsg, 30, 20);
}
void serverEvent(Server srv, Client clt) {
    fsSrv.write(picList.toString());
}