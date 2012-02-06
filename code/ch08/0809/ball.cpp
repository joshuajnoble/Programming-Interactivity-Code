
#include "ball.h"

Ball::Ball() {
	mass = ofRandom(3.0) + 1.0;
	bounce = 0.9;
	location.x = ofRandom(ofGetWidth());
	location.y = 0;
}

void Ball::updateBall() {
	
    velocity += acceleration;
    location += velocity;
    acceleration.set(0.0f,0.0f,0.0f);
    // this assumes that the height of the window is 800px and the width is 1000
    // you can also use the getWindowSize() method to determine how large the window is
    if (location.y > 750) {
        velocity.y *= -bounce;
        location.y = 750;
    }
    if(location.y < 0) {
        velocity.y *= -bounce;
        location.y = 0;
    }
    if (location.x > 1000) {
        velocity.x *= -bounce;
        location.x = 1000;
    }
    if (location.x < 0) {
        velocity.x *= -bounce;
        location.x = 0;
    }
	
}

// Method to display
void Ball::drawFrame() {
    ofSetColor(color);
    ofCircle(location.x, location.y, 50);
}

void Ball::collision(Ball& b1)
{
	/*cout << b1->mass << " " << b1->location.x << " " << b1->location.y << endl;
    // we'll just declare all these things we'll need at once
    float newMass, diff, angle, newX, newY, newVelocityX, newVelocityY, fy21, sign;
	
    newMass = b1->mass/mass;
    newX = b1->location.x - location.x;
    newY = b1->location.y - location.y;
    newVelocityX = b1->velocity.x - velocity.x;
    newVelocityY = b1->velocity.y - velocity.y;
	
    //  If the balls aren't heading at one another, we don't want to alter them 
    //  because they could be heading away from each other.
    if ( (newVelocityX*newX + newVelocityY*newY) >= 0) return;
	
    fy21=fabs(newY);
    if ( fabs(newX)<fy21 ) {
        if (newX<0) { sign=-1; } else { sign=1;}
        newX=fy21*sign;
    }
	
    // Now that we've figured out which direction things are heading,
    // set their velocities.
    angle=newY/newX;
    diff = -2 * (newVelocityX + angle * newVelocityY)/((1 + angle * angle) * (1 + newMass));
    b1->velocity.x = b1->velocity.x + diff;
    b1->velocity.y = b1->velocity.y + angle * diff;
	velocity.x = velocity.x - newMass * diff;
	
    velocity.y = velocity.y - angle * newMass * diff;*/
	
	cout << b1.mass << " " << b1.location.x << " " << b1.location.y << endl;
    // we'll just declare all these things we'll need at once
    float newMass, diff, angle, newX, newY, newVelocityX, newVelocityY, fy21, sign;
	
    newMass = b1.mass/mass;
    newX = b1.location.x - location.x;
    newY = b1.location.y - location.y;
    newVelocityX = b1.velocity.x - velocity.x;
    newVelocityY = b1.velocity.y - velocity.y;
	
    //  If the balls aren't heading at one another, we don't want to alter them 
    //  because they could be heading away from each other.
    if ( (newVelocityX*newX + newVelocityY*newY) >= 0) return;
	
    fy21=fabs(newY);
    if ( fabs(newX)<fy21 ) {
        if (newX<0) { sign=-1; } else { sign=1;}
        newX=fy21*sign;
    }
	
    // Now that we've figured out which direction things are heading,
    // set their velocities.
    angle=newY/newX;
    diff = -2 * (newVelocityX + angle * newVelocityY)/((1 + angle * angle) * (1 + newMass));
    b1.velocity.x = b1.velocity.x + diff;
    b1.velocity.y = b1.velocity.y + angle * diff;
	velocity.x = velocity.x - newMass * diff;
	
    velocity.y = velocity.y - angle * newMass * diff;
	
}

void Ball::addForce( ofVec2f force ) {
	
	force /= mass; // make sure the force is modified by the mass
	acceleration += force; // the acceleration is affected by the force
}