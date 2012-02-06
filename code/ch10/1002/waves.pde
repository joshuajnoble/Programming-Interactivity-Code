import ddf.minim.*;
import ddf.minim.signals.*;

AudioOutput out;
SquareWave square;
SawWave saw;
Minim minim;

void setup()
{
    size(800, 800);
    //don't forget, you always need to start Minim first
    minim = new Minim(this);

    //get system access to the line out
    out = minim.getLineOut(Minim.STEREO, 512);

    // create a SquareWave with a frequency of 440 Hz,
    // an amplitude of 1 with 44100 samples per second
    square = new SquareWave(440, 1, 44100);
    // create a SawWave with a frequency of 600Hz and
    // an amplitude of 1
    saw = new SawWave(600, 1, 44100);

    // now you can attach the square wave and the filter to the output
    out.addSignal(square);
    out.addSignal(saw);
}

void draw() {
    saw.setFreq(mouseX);
    square.setFreq(mouseY);
}

void stop() {
  minim.stop();
  super.stop();
}