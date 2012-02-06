PShape s;
void setup() {
    s = loadShape("svgFile.svg");
    smooth();
    noLoop();
}

void draw() {
    // the shape method signature looks like this:
    // shape(PShape s, int x, int y, int width, int height)
    shape(s, 10, 10, 80, 80);
}