Point[] pts = new Point[6];

int count = 0;
void setup(){
    size(500, 500);
}

void draw(){
    background(255);
    fill(0);
    beginShape();
    for(int i = 0; i < pts.length; i++){
	vertex(pts[i].x, pts[i].y);
        }
    }

void mousePressed(){
    if(count > 5){
        count = 0;
    }
    Point newPoint = new Point(mouseX, mouseY);
    pts[count] = newPoint;
    count++;
}

class Point{
    float x;
    float y;
    Point(float _x, float _y){
        x = _x;
        y = _y;
    }
}