

void setup(){
    size(640, 360, P3D);
}

void draw(){
    background(50, 50, 50);
    translate(width/2, height/2);
	
    //beginShape(POINTS);
    //beginShape(LINES);
    //beginShape(TRIANGLES);
    //beginShape(TRIANGLE_FAN);
    //beginShape(TRIANGLE_STRIP);
    //beginShape(QUAD_STRIP);
    //beginShape(QUADS);
    beginShape();		
    	vertex(0, 0);
        vertex(0, 75);
        vertex(50, 75);
        vertex(50, 0);
        vertex(100, 0);
        vertex(100, 125);
        vertex(125, 125);
        vertex(125, 0);
    endShape();
}