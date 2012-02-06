import hypermedia.video.*;

// OpenCV instance
OpenCV opencv;
// blur value
int blurAmount = 17;

// image dimensions
int IMG_WIDTH  = 200;
int IMG_HEIGHT = 150;

int COLOR_SPACE = OpenCV.RGB;
//final int COLOR_SPACE = OpenCV.GRAY;

void setup() {

    size( IMG_WIDTH*2, IMG_HEIGHT*2 );

    opencv = new OpenCV(this);
    opencv.capture(IMG_WIDTH, IMG_HEIGHT);

}

void draw() {
    // grab image
    opencv.read();
    opencv.blur( OpenCV.GAUSSIAN, blurAmount );
    opencv.restore( COLOR_SPACE );
    opencv.flip(OpenCV.FLIP_VERTICAL);
    image( opencv.image(), 0, IMG_HEIGHT);

    opencv.restore( COLOR_SPACE );
    opencv.invert();
    image( opencv.image(), IMG_WIDTH, IMG_HEIGHT);
    image( opencv.image(OpenCV.SOURCE), 0, 0 );
}

void mouseDragged() {
    blurAmount = (int) map(mouseX,0,width,0,255);
}

public void stop() {
    opencv.stop();
    super.stop();
}