import ddf.minim.*;
import ddf.minim.signals.*;
import ddf.minim.effects.*;

AudioOutput out;
SquareWave square;
LowPassSP lowpass;
Minim minim;

void setup()
{
    size(800, 800);
    // don't forget to instantiate the minim library
    minim = new Minim(this);
    // get a stereo line out with a sample buffer of 512 samples
    out = minim.getLineOut(Minim.STEREO, 512);
    // create a SquareWave with a frequency of 440 Hz,
    // an amplitude of 1, and the same sample rate as out
    square = new SquareWave(440, 1, 44100);
    // create a LowPassSP filter with a cutoff frequency of 200 Hz
    // that expects audio with the same sample rate as out
    lowpass = new LowPassSP(200, 44100);

    // now we can attach the square wave and the filter to our output
    out.addSignal(square);
    out.addEffect(lowpass);
}

void draw()
{
    try {
    	if(out.hasSignal(square)) {
        	out.removeEffect(lowpass);
	    }
	    // set the frequency of the lowpass filter that we're using
	    lowpass.setFreq(mouseY);
	    out.addEffect(lowpass);
    } catch(Exception e) {
	// nothing at the moment
    }
}

void stop()
{
    out.close();
    minim.stop();
    super.stop();
}