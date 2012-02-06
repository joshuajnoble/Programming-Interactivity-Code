void setup() {
    size(400, 400);
}

void draw(){
    background(255);
    fill(0);
    beginShape();
    vertex(0, 0);
    vertex(400, 400);
    vertex(mouseX, mouseY);
    endShape();
}