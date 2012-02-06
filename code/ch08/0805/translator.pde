float rotateAmt = 0.0;

void setup() {
    size(700, 700);
}

void draw() {
    background(122);
 pushMatrix();
        translate(100, 100);
        ellipse(30, 30, 300, 300);
        rect(250, 250, 200, 200);
        pushMatrix();
fill(255, 100);
          translate(100, mouseX - 100);
          ellipse(0, 0, 300, 300);
          rect(100, 100, 200, 200);
          pushMatrix();
              fill(255, 100);translate(mouseY - 100, 100);
              ellipse(0, 0, 300, 300);
              rect(100, 100, 200, 200);
              pushMatrix();
rotate(PI*rotateAmt);
                translate(200, 200);
                rect(0, 0, 50, 50);
                rect(−200, −200, 50, 50);
                rect(−100, −100, 50, 50);
popMatrix();
          popMatrix();
        popMatrix();
    popMatrix();

// modify the rotate variable
    rotateAmt += 0.01;

}