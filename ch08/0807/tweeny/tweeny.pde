import megamu.shapetween.*;

Tween colorTween;
Tween positionTween;

color[] colorArr = new color[3];

int coli = 0;
int colj = 1;

int posi = 0;
int posj = 1;

PVector[] positions = new PVector[4];

void setup() {

  size( 400, 400 );
  colorMode( RGB );
  smooth();
  colorTween = new Tween(this, 5.0, Tween.SECONDS, Shaper.COSINE);
  colorTween.start();

  positionTween = new Tween( this, 1.0, Tween.SECONDS, Shaper.COSINE);

  colorArr[0] = color(  255, 0, 0 );
  colorArr[1] = color( 0, 0, 255 );
  colorArr[2] = color( 0, 255, 0 );

  positions[0] = new PVector(0, 0);
  positions[1] = new PVector(width, 0);
  positions[2] = new PVector(width, height);
  positions[3] = new PVector(0, height);
}

void draw() {

  float x, y;

  if (!positionTween.isTweening()) {
    posi++;
    posj++;

    if (posi > 3) { 
      posi = 0;
    }
    if (posj > 3) { 
      posj = 0;
    }

    positionTween.start();
  }

  x = lerp(positions[posi].x, positions[posj].x, positionTween.position());
  y = lerp(positions[posi].y, positions[posj].y, positionTween.position());

  if (!colorTween.isTweening()) {

    coli++;
    colj++;

    if (coli > 2) { 
      coli = 0;
    }
    if (colj > 2) { 
      colj = 0;
    }

    colorTween.start();
  }
  // tween the colors
  color c = lerpColor( colorArr[coli], colorArr[colj], 
  colorTween.position() );

  noStroke();
  fill( c ); // set the color to our new tweened color
  ellipse( x, y, 140, 140 ); // draw a circle using that new color
}

