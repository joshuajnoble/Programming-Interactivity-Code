import hypermedia.video.*;
import java.awt.Rectangle;

import processing.serial.*;


OpenCV opencv;

// contrast/brightness values
int contrast_value    = 0;
int brightness_value  = 0;

Serial arduinoPort;

void setup() {

    size( 320, 240 );

    opencv = new OpenCV( this );
    opencv.capture( width, height );                   // open video stream
    opencv.cascade( OpenCV.CASCADE_FRONTALFACE_ALT );  // load detection description, here-> front face detection : "haarcascade_frontalface_alt.xml"
    arduinoPort = new Serial(this, Serial.list()[0], 9600); 

}


public void stop() {
    opencv.stop();
    super.stop();
}


void draw() {

    // grab a new frame
    // and convert to gray
    opencv.read();
    opencv.convert( GRAY );
    opencv.contrast( contrast_value );
    opencv.brightness( brightness_value );

    // proceed detection
    Rectangle[] faces = opencv.detect( 1.2, 2, OpenCV.HAAR_DO_CANNY_PRUNING, 40, 40 );

    // display the image
    image( opencv.image(), 0, 0 );
    
    boolean foundFace = true;

    Rectangle bestFace = new Rectangle();
    if(faces.length > 1) {
      
      for(int i = 0; i < faces.length; i++) {
        if( (faces[i].height * faces[i].width)  > (bestFace.height * bestFace.width)) {
          bestFace = faces[i];
        }
      }
    } else if(faces.length > 0) {
      bestFace = faces[0];
    } else {
      foundFace = false;
    }
   
    // draw face area(s)
    if(foundFace)
    {
      noFill();
      stroke(255,0,0);
      for( int i=0; i<faces.length; i++ ) {
          rect( bestFace.x, bestFace.y, bestFace.width, bestFace.height ); 
      }
      
      arduinoPort.write( bestFace.x + (bestFace.width/2) / width * 255 );
      arduinoPort.write( bestFace.y + (bestFace.width/2) / height * 255);
   }
    
}

void mouseDragged() {
    contrast_value   = (int) map( mouseX, 0, width, -128, 128 );
    brightness_value = (int) map( mouseY, 0, width, -128, 128 );
}


