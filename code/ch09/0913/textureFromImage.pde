PImage textureImg;
void setup() {

    size(300, 300);
    // dummy image colorMode(RGB,1);
    textureImg = loadImage("test.png");

    color col;
    int squareWidth = 20;
    boolean isBlack = true;
   for( int i = 0; i < textureImg.height; i++) {
        for ( int j = 0; j < textureImg.width; j++) {
            if(j % squareWidth == 0) {
                isBlack = !isBlack;
            }
            if(isBlack) {
        textureImg.pixels[ i * textureImg.width + j] = color(255);
            } else {
                textureImg.pixels[ i * textureImg.width + j] = color(0);
              }
        }
        if(i % squareWidth != 0 && i != 0) {
               isBlack = !isBlack;
        }
    }
}

void draw() {
  image(textureImg, 0, 0);
}