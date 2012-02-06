import processing.video.*;
Movie mov;

void setup() {
    size(320, 240);
    mov = new Movie(this, "sample.mov");
    mov.play();
}

void movieEvent(Movie m) {
    m.read();
}

void draw() {
    image(mov, 0, 0);
}