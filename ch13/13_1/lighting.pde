import processing.opengl.*;

void setup() {
    size(400, 400, OPENGL); // set up the 3D renderer
}
void draw() {
    noStroke(); // commenting this line out will show the lines in the sphere
    lights(); // uncommenting this will show the model with lights
    fill(255);
    translate(100, 100, 0);
    sphere(40);
}