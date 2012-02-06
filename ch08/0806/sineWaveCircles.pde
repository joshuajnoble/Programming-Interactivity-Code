float theta = 0.0f;       // Start angle at 0
float waveAmplitude = 75;  // how high you want the wave to be drawn
float dx;                 // Value for incrementing X, to be calculated
                             //as a function of period and xspacing
float[] yvalues;          // Using an array to store height values for
                             //the wave (not entirely necessary)

void setup() {
    size(300,300);
    smooth();
    stroke(255);
    yvalues = new float[500];
}

void draw() {
    fill(0, 50);
    rect(0, 0, 300, 300);
    noFill();
    // Increment theta (try different values for 'angular velocity' here
    theta += 0.05;

    // For every x value, calculate a y value with sine function
    float x = theta;
    int i;
    for (i = 0; i < yvalues.length; i++) {
        yvalues[i] = sin(x)*waveAmplitude;
        x+=0.5;
    }
    for (i = 0; i < yvalues.length; i++) {
        ellipse(i*mouseX/10, width/2+yvalues[i], 16, 16);
    }
}
