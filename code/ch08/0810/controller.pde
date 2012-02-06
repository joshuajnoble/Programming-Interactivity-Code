import controlP5.*;
ControlP5 controller; // declare the controller

void setup() {
    // tell the controller what application will be running it
    controller = new ControlP5(this);
}

ControlP5 controlP5;
int buttonValue = 0;

void setup() {
    size(400,400);
    controlP5 = new ControlP5(this);
    controlP5.addButton("white",255,100,160,80,20);
    controlP5.addButton("black",0,100,190,80,20);
}

void draw() {
    background(buttonValue);
}

void controlEvent(ControlEvent event) {
    buttonValue = int(event.controller().value());
}