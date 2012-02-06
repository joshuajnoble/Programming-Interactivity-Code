import controlP5.*;

// Declare the ControlP5
ControlP5 control;
int bgColor = 0;
int sliderVal = 100;
// Declare the two controls that will be used
Knob k;
Slider s;

float sliderValue;
float knobValue;


void setup() {
    size(400,400);
    control = new ControlP5(this);
    s = control.addSlider("slider",0,255,128,100,160,10,100);
    s.setId(1);
    k = control.addKnob("knob", 0,255,128, 200, 160, 40);
    k.setId(2);
}

void draw() {
    background(0, 0, bgColor);
    k.setValue(knobValue);
    s.setValue(sliderValue);
}

void controlEvent(ControlEvent event) {
    int id = event.controller().id();
    if(id == 1) {
        knobValue = event.controller().value();
    } else {
        sliderValue = event.controller().value();
    }
    bgColor = int(event.controller().value());
}