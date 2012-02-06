import ddf.minim.*;

AudioPlayer player;
AudioPlayer player2;
Minim minim;

boolean hasVolume;

void setup()
{
  size(512, 200);
  minim = new Minim(this);

  // load a file, give the AudioPlayer buffers that are 1024 samples long
  player = minim.loadFile("two.mp3", 1024);
  player2 = minim.loadFile("one.mp3", 1024);
  // play the file
  player.play();
  player.printControls();
  player2.play();
  hasVolume = player.hasControl(Controller.VOLUME);
}

void draw()
{
  background(0); // erase the background
  stroke(0, 255, 0);
  float gain1 = 0;
  float gain2 = 0;

  if(hasVolume) {
    player.setVolume(mouseX / width);
    gain1 = map(player.getVolume(), 0, 1, 0, 50);
  } else {
    player.setGain(map(mouseX, 0, width, -20, 1));
    gain1 = map(player.getGain(), -20, 1, 0, 50);
  }

for(int i = 0; i< player.left.size()-1; i++) {
    line(i, 50 + player.left.get(i)*gain1, i+1, 50 + player.left.get(i+1)*gain1);
    line(i, 150 + player.right.get(i)*gain1, i+1, 150 + player.right.get(i+1)*gain1);
  }
  stroke(255, 0, 0);
  if(hasVolume) {
    player2.setVolume(width - mouseX / width);
    gain2 = map(player2.getVolume(), 0.0, 1, 0, 50);
  } else {
    player2.setGain(map(width - mouseX, 0, width, -20, 1));
    gain2 = map(player2.getGain(), -20, 1, 0, 50);
  }
  for(int i = 0; i< player2.left.size()-1; i++) {
    line(i, 50 + player2.left.get(i)*gain2, i+1, 50 + player2.left.get(i+1)*gain2);
    line(i, 150 + player2.right.get(i)*gain2, i+1, 150 + player2.right.get(i+1)*gain2);
  }
}

void stop()
{
  // always close Minim audio classes when you are done with them
  player.close();
  player2.close();
  minim.stop();
  
  super.stop();
}