int lastX = 0;
int lastY = 0;

void setup() {
     size(400, 400);
}

void draw() {
    lastX = mouseX;
    lastY = mouseY;
}

void mouseDragged() {
    line(lastX, lastY, mouseX, mouseY);
}