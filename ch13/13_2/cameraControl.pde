
import processing.opengl.*;

float eyeX, eyeY, eyeZ;
float centerX, centerY, centerZ;

boolean setCenter = false;

void setup() {
    size(500, 500, OPENGL);
    noFill();
    eyeX = 70;
    eyeY = 35;
    eyeZ = 120;
    centerX = 0;
    centerY = 0;
    centerZ = 0;
}

void draw() {
    lights();
    background(122);
    camera(eyeX, eyeY, eyeZ, centerX, centerY, centerZ,  0.0, 1.0, 0.0);
    //camera(70.0, 35.0, 120.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    fill(255);
    box(50);
}

void mouseMoved() {

   eyeX = width/2 - mouseX;
   eyeY = height/2 - mouseY;
}

void mouseDragged() {
    centerX += mouseX - pmouseX;
    centerY += mouseY - pmouseY;
}

void mouseReleased() {
    setCenter = false;
}

void mousePressed() {
    setCenter = true;
}

void keyPressed() {
if(keyCode == 10) { // enter button
        printCamera();
    }
    if(setCenter) {
        if(keyCode == 38) { eyeZ++; } // up arrow
        if(keyCode == 40) { eyeZ--; } // down arrow
    } else {
        if(keyCode == 38) { centerZ++; } // up arrow
        if(keyCode == 40) { centerZ--; } // down arrow
    }
}