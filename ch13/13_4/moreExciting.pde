import processing.opengl.*;


void setup()
{
  size(500, 500, OPENGL);
}

void draw()
{
  background(122);

  pushMatrix();
  translate(200, 200, 20);
  stroke(255);
  fill(0);
  
  rotateY(frameCount/50.0);
  rotateZ(frameCount/50.0);
  
  float transX = modelX(0, 0, 0);
  float transY = modelY(0, 0, 0);
  float transZ = modelZ(0, 0, 0);
  
  box(50);

  popMatrix();

  translate(transX, transY, transZ + sin(frameCount/50.0) * 100);
  stroke(0);
  fill(255, 122);
  box(100);
}

