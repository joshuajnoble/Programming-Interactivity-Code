PImage img;

void setup() {
    size(400, 400);
    img = loadImage("sample.jpg");
    image(img, 0, 0);
}

void draw() {
	image(img, 0, 0);
}