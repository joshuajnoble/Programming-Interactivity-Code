void setup(){
    size(400, 400);
}

void draw(){
    background(255);
    fill(0);
    int xVal = mouseX*3-100;
    int yVal = mouseY*3-100;
    curve(xVal, yVal, 100, 100, 100, 300, xVal, yVal);
    curve(xVal, yVal, 100, 300, 300, 300, xVal, yVal);
    curve(xVal, yVal, 300, 300, 300, 100, xVal, yVal);
    curve(xVal, yVal, 300, 100, 100, 100, xVal, yVal);
}