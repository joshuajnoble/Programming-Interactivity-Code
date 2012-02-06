PFont arial;

void setup() {
    // make the size of our window
    size(300, 300);
    // load the font from the system
    arial = createFont("Arial", 32);
    // set up font so our application is using the font whenever
    // we call the text method to write things into the window
    textFont(arial, 15);
}

void draw() {
    // this makes the background black, overwriting anything there
    // we're doing this because we want to make sure we don't end up
    // with every set of numbers on the screen at the same time.
    background(0);
    // here's where we really do the work, putting the mouse position
    // in the window at the location where the mouse is currently
    text(" position is "+mouseX+" "+mouseY, mouseX, mouseY);
}