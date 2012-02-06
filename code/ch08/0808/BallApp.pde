Ball ball;
Ball ball2;

PVector wind;

void setup() {
    size(400,400);
    smooth();
    background(0);
    ball = new Ball();
    ball2 = new Ball(new PVector(1.1, 0), new PVector(1, 1), new PVector(1, 0));
    
    wind = new PVector(0.01, 0.0);
}

void draw() {
    fill(0, 10);
    rect(0, 0, 400, 400);

    // Add gravity to thing
    // This isn't "real" gravity, just a made up force vector
    PVector grav = new PVector (0,0.05);
    ball.addForce(grav);
    ball2.addForce(grav);

    float newWind = ( (float) mouseY/ (float) height) - 0.5;
    wind.x = newWind + wind.x;
    
    println( wind.x );
    
    ball.addForce(wind);
    ball2.addForce(wind);
    
    ball.drawFrame();
    ball2.drawFrame();
}
