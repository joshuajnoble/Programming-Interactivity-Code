PImage a;

void setup() {
    size(400,400,P3D);
    a = loadImage("test2.png");
}

void draw() {
    background(255);
    textureMode(NORMALIZED);
    beginShape(QUADS);
    texture(a);
        vertex(0, 0, 0, 0, 0);
        vertex(200, 0, 0, 0, 100);
        vertex(200, 200, 0, 100, 100);
        vertex(0, 200, 0, 100, 100);
    endShape();
    beginShape();
        texture(a);
        vertex(100, 0, 0, 0, 0);
        vertex(mouseX, 0, 0, 100, 0);
        vertex(mouseX, 200, 0, 100, 100);
        vertex(100, 200, 0, 0, 100);
    endShape();
}