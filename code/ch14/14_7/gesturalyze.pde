import net.silentlycrashing.gestures.*;

GestureAnalyzer brain;
PostGestureListener boxListener;


void setup() {
    // initialize the gesture listeners
    size(500, 500);

    brain = new MouseGestureAnalyzer(this);
    brain.setVerbose(true);
    boxListener = new PostGestureListener(this, brain, "^(RDLU)$");
    boxListener.registerOnAction("drawBox", this);
}

void draw() {
    line(pmouseX, pmouseY, mouseX, mouseY);
}

void drawBox() {
    rect(mouseX, mouseY, 200, 200);
}