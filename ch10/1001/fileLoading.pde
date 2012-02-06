import ddf.minim.*;
AudioPlayer song;
Minim minim;
void setup()
{
    size(800, 800);
    // don't forget to instantiate the minim library
    minim = new Minim(this);
    // this loads song.mp3 from the data folder
    song = minim.loadFile("song.mp3");

}

void draw()
{
    fill(0x000000, 30);
    rect(0, 0, width, height);
    //background(0);
    stroke(255);
    noFill();
    for(int i = 0; i< song.bufferSize() - 1; i++)
    {
        ellipse(i * 4, 100 + song.left.get(i)*100, 5, 5);
        ellipse(i * 4, 250 + song.right.get(i)*100, 5, 5);
    }
}

boolean isPlaying = false;
void mousePressed()
{
    if(isPlaying) {
        song.pause();
        isPlaying = false;
    } else {
        song.play();
        isPlaying = true;
    }
}

void stop()
{
  minim.stop();
  super.stop();
}