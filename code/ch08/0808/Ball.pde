class Ball {
    PVector location = new PVector(0, 0);
    PVector velocity = new PVector(0, 0);
    PVector acceleration = new PVector(0, 0);
    float mass = 20; // how heavy are we?
    float maximum_velocity = 20; // we'll use this to make sure things don't get too fast
    // How bouncy are we? 1 means we don't lose any speed in bouncing,
    // higher means we gain speed, lower means we lose it
    float bounce = 1.0;
        
Ball(PVector initialAcceleration, PVector initialVelocity, PVector initialLocation) {
    acceleration = initialAcceleration;
    velocity.set(initialVelocity);
    location.set(initialLocation);
}

Ball() {
    acceleration = new PVector (0.0, 0.0);
    location = new PVector (0.0, 0.0);
    velocity = new PVector (1.0, 0.0);
}

void update() {
    velocity.add(acceleration); // add the accleration to the velocity
    velocity.limit(maximum_velocity);
    location.add(velocity);
    // the acceleration all comes from the forces on the Ball which are reset
    // each frame so we need to reset the acceleration to keep things within
    // bounds correctly
    acceleration.set(0.0f,0.0f,0.0f);

    // bounce off the walls by reversing the velocity
    if (location.y > height) {
        velocity.y *= -bounce;
        location.y = height;
    }
    if (location.y < 1) {
        velocity.y *= -bounce;
        location.y = 1;
    }
    if ((location.x > width) || (location.x < 0)) {
      velocity.x *= -bounce;
    }
    
}

void addForce(PVector force) 
{
    force.div(mass); // make sure the force is modified by the mass
    acceleration.add(force); // the acceleration is affected by the force
}

void drawFrame() {
    update();
    ellipseMode(CENTER);
    noStroke();
    fill(255);
    ellipse(location.x, location.y, 20, 20);
 }
}
