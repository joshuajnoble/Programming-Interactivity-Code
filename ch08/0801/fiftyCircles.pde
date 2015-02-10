void setup() {
  size(800, 800);
}
void draw() {
  background(0, 0, 0);
  for(int i = 0; i < 50; i++)
  {
    // draw 50 circles in the center of the screen with the circles
    // progressively getting closer and closer to the mouse, increasing the size of the circles
    ellipse(400 - (i*10 - (0.02*i*mouseX)), 400 - (i*10 - (0.02*i*mouseY)), i*2, i*2);
    fill(255, 255, 255, 20);
  }
}
