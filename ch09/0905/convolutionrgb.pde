PImage img;
float[][] kernel = { { .111, .111, .111 }, { .111, 8, .111 },
      { .111, .111, .111 }};

void setup() {
    img  = loadImage("streetrgb.jpg"); // Load the original image
    size(img.width, img.height); // size our Processing app to the image
}

void draw() {
img.loadPixels(); // make sure the pixels of the image are available
// create a new empty image that we'll draw into
PImage copyImg = createImage(width, height, RGB);
// loop through each pixel
for (int y = 1; y < height-1; y++) { // Skip top and bottom edges
    for (int x = 1; x < width-1; x++) { // Skip left and right edges
        int rsum = 0; // red  sum for this pixel
        int gsum = 0; // green  sum for this pixel
        int bsum = 0; // blue sum for this pixel
        for (int ky = -1; ky <= 1; ky++) {
            for (int kx = -1; kx <= 1; kx++) {
                // Calculate the adjacent pixel for this kernel point
                int pos = (y + ky)*width + (x + kx);
                int val = img.pixels[pos];
                rsum += kernel[ky+1][kx+1] * ((val >> 16) & 0xFF);
                gsum += kernel[ky+1][kx+1] * ((val >> 8) & 0xFF);
                bsum += kernel[ky+1][kx+1] * (val & 0xFF);
            }
        }
        copyImg.pixels[y* width + x] = color(rsum, gsum, bsum);
    }
}
// State that there are changes to edgeImg.pixels[]
copyImg.updatePixels();
image(copyImg, 0, 0); // Draw the new image

}
