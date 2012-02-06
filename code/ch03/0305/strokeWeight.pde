void setup()
{
}

void draw(){
    stroke(0xFFCCFF00); // here we set the color to yellow
    strokeWeight(5); // set the stroke weight to 5
    // draw the lines
    line(0, 100, 600, 400);
    line(600, 400, 300, 0);
    line(300, 0, 0, 100);
}