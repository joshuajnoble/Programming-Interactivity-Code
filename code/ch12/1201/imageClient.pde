import processing.net.*;

Client fsClient;
XMLElement picList;
ArrayList picArray;

void setup() {
    size(800, 800);
    fsClient = new Client(this, "127.0.0.1", 8180);
    picArray = new ArrayList();

}

void draw() {
    background(0);
 if(fsClient.available() &gt; 0) {
        readServer();
    }
 int sz = picArray.size();
    IImage fi;
    for(int i = sz-1; i &gt;= 0; i-- ) {
        fi = (IImage)picArray.get(i);
        image(fi.img, fi.x, fi.y);
    }
}

void readServer() {
    if(picList == null) {
            picList = new XMLElement(fsClient.readString());
            int totalPics = picList.getChildCount();
void readServer() {
    if(picList == null) {
            picList = new XMLElement(fsClient.readString());
            int totalPics = picList.getChildCount();
picArray.add(fi);
            }
        }
}

class IImage{

    PImage img;
    public int x;
    public int y;

    public void setXMLData(XMLElement s)
    {
        x = s.getIntAttribute("x");
        y = s.getIntAttribute("y");
      }
}