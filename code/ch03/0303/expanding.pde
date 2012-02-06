int x = 0;

void setup() {
    size(300, 300);
}

void draw() {
    // make x a little bit bigger
    x += 2;
    // draw a circle using x as the height and width of the circle
    ellipse(150, 150, x, x);
    // if x is too big, we can't see it in our window, so put it back
    // to 0 and start over
    if(x > 300) {
        x = 0;
    }
}