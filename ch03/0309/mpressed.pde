int alphaValue = 0;

void setup() {
    size(350, 300);
    background(0xFFFFFFFF);
}

void draw() {
    background(0xFFFFFFFF);
    fill(255, 0, 0, alphaValue);
    rect(100, 100, 100, 100);
}

void mousePressed() {
    print(mouseX + "\n");
    alphaValue = mouseX;
}