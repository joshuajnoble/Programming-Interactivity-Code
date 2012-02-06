import processing.net.*;

Client fsClient;
ArrayList iiArr;

int millisSinceSent = 0;

void setup() {
  size(500, 500);
  fsClient = new Client(this, "127.0.0.1", 8180);
  iiArr = new ArrayList();
frameRate(10);
    for(int i = 3; i>-1; i--) {
        // check in the downloads for this class
        InteractiveImage ii = new InteractiveImage();
        ii.id = i;
        ii.colr = 30 + 40 * i;
        iiArr.add(ii);
    }
    background(0);
}

void draw() {
    fill(0, 2);
    rect(0, 0, 500, 500);
f(fsClient.available() > 0) {
        String msg = fsClient.readStringUntil('\0');
        readServer(msg);
    }
int sz = iiArr.size();
    InteractiveImage ii;
    for(int i = sz-1; i > −1; i-- ) {
        ii = (InteractiveImage)iiArr.get(i);
        fill(ii.colr);
        ellipse(ii.x, ii.y, 100, 100);
    }
}

void readServer(String di) {
    int timing = millis() - millisSinceSent;
    if(timing < 500) {
        print(" too recent "+timing);
        return;
    }
    print(" not too recent "+timing);

    if(di == null) {
        println(" di null ");
        return;
    }

    XMLElement changedXML;
    fsClient.clear();
try {
        changedXML = new XMLElement(di);
    } catch (Exception e) {
        println(" can't convert ");
        return;
    }
    println(changedXML);
    int inId;
    if(changedXML.getChildCount() > 0) {
        inId = changedXML.getChild(0).getIntAttribute("id");
    } else {
        return;
    }

    for(int i = 0; i<iiArr.size(); i++) {
        InteractiveImage fi = (InteractiveImage) iiArr.get(i);
                  if(fi.id == inId) {
                          int xv = changedXML.getChild(0).getIntAttribute("x");
                          int yv = changedXML.getChild(0).getIntAttribute("y");
                          fi.x = xv;
                          fi.y = yv;
                  }
            }
}

void mouseDragged() {

        for(int i = 0; i<iiArr.size(); i++) {
            InteractiveImage img = (InteractiveImage) iiArr.get(i);
            if(img.isClicked(mouseX, mouseY)) {
                img.x = mouseX;
                img.y = mouseY;
                try {
                    fsClient.write(createXMLFromII(img));
                } catch (Exception e) {
                    return;
                }
  millisSinceSent = millis();
                return;
            }
    }
}

String createXMLFromII(InteractiveImage i) {

    String s = "<img x=\""+i.x+"\" y=\""+i.y+"\" id=\""+i.id+"\" />";
    return s;
}