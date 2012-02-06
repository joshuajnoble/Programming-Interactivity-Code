PImage pic;
int location = 0;
int fullSize;
float zoomFactor = 0.0;

void setup()
{
    pic = loadImage("hello.png");
    fullSize = pic.height * pic.width;
    size(pic.width, pic.height);
    
    noStroke();
}

void draw()
{
    background(255, 255, 255);
    image(pic, 0, 0);
    
    if( (int) zoomFactor < 1.0) return;
    
    for( int i = 0, k = mouseX; i < width; i+= (int) zoomFactor, k++) {
      for( int j = 0, l = mouseY; j < height; j+= (int) zoomFactor, l++) {
        
        int xx = (int) zoomFactor + (k - (k/2));
        int yy = (int) zoomFactor + (l - (l/2));
        
        fill(pic.get( xx, yy ));
        rect(i, j, zoomFactor, zoomFactor);
      }
    }    
}

void keyPressed() {
  if(key == '+') {
    zoomFactor += max(2.0, zoomFactor);
  } else if(key == '-') {
    zoomFactor -= max(2.0, zoomFactor/2.0);
  }
}
