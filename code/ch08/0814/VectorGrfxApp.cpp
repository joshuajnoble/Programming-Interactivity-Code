#include "VectorGrfxApp.h"
#include "stdio.h"

void VectorGrfxApp::setup(){
    capture = false;
    output.enableDraw();
    ofSetCircleResolution(50);
    phaseoffset = 0;
    steps = 30;
    for(int i = 0; i < 30; i+=2) {
        angles[i] = 2 * PI / steps * i + phaseoffset;
    }
}

void VectorGrfxApp::update(){
    ofBackground(255, 255, 255);
}

void VectorGrfxApp::draw(){</programlisting>
          </example>

          <para>You don’t want to capture every frame, only capture one frame
          when the user has pressed the space bar, which sets the capture
          <literal moreinfo="none">property</literal> to <literal moreinfo="none">true</literal>:</para>

          <programlisting format="linespecific" id="I_programlisting3_d1e18337">    if(capture){
        output.beginEPS("test.ps");
    }
    // draw all the shapes in red
    output.setColor(0xff0000);
    output.fill();</programlisting>

          <para>The <literal moreinfo="none">ofxVectorGraphics</literal> class
          defines a few methods for drawing simple shapes. It is used here to
          create a circle, rectangle, and triangle:<indexterm id="I_indexterm3_d1e18345" significance="normal">
              <primary>ofxVectorGraphics object</primary>

              <secondary>methods for drawing simple shapes</secondary>
            </indexterm></para>

          <programlisting format="linespecific" id="I_programlisting3_d1e18350">    output.circle(100, 100, 80);
    output.rect(200, 20, 160, 160);
    output.triangle( 460, 20, 380, 180, 560, 180);
    // set the color we'll be using
    output.setColor(0x999999);
    output.noFill();
    output.setLineWidth(1.0);
    float ang;
    // use all the angle values set in the mouseMoved method to draw some circles
    for(int i = 0; i < 30; i++){
        ang = angles[i] * 180 / PI;
        output.ellipse(ang + 20, ang + 250, mouseX * 0.1 * cos(angles[i]) +
            ang, mouseY * 0.25 * sin(angles[i]) + ang);
    }</programlisting>

          <para>Now, the application draws to the screen using all the points
          set in the <literal moreinfo="none" role="keep-together">mouseDragged()</literal> method:<indexterm id="I_indexterm3_d1e18357" significance="normal">
              <primary>ofxVectorGraphics object</primary>

              <secondary>drawing to screen using points set in mouseDragged(
              )</secondary>
            </indexterm></para>

          <programlisting format="linespecific" id="I_programlisting3_d1e18362">    if( pts.size() > 0 ){

        int numPts = pts.size();
        output.setColor(0x0000ff);
        output.beginShape(); // begin the shape
        int rescaleRes = 6;  //create nice smooth curves between points

        for(int i = 0; i < numPts; i++){
            //we need to draw the first and last point
            //twice for a catmull curve
            if(i == 0 || i == numPts −1){
                output.curveVertex(pts[i].x, pts[i].y);
            }
            if(i % rescaleRes == 0) {
                output.curveVertex(pts[i].x, pts[i].y);
            }
        }
        output.endShape(); // end the shape
    }
    // this will write the PS file to the data folder
    if(capture){
        output.endEPS();
        capture =false;
    }
}</programlisting>

          <para>If the user presses the space bar, set the capture variable to
          <literal moreinfo="none">true</literal> so that the <literal moreinfo="none">draw()</literal> method will write to the <filename moreinfo="none">.ps</filename> file:<indexterm id="I_indexterm3_d1e18375" significance="normal">
              <primary>ofxVectorGraphics object</primary>

              <secondary>writing to .ps file</secondary>
            </indexterm></para>

          <programlisting format="linespecific" id="I_programlisting3_d1e18380">void VectorGrfxApp::keyPressed(int key){
    if(key == ' '){
        capture = true;
    }
}

void VectorGrfxApp::mouseMoved(int x, int y ){
        // make some values that will be used in the draw() method
           //to draw circles
        for(int i = 0; i < 30; i++) {
            angles[i] = 2 * PI / steps * i + phaseoffset;
        }
        phaseoffset += PI / 180 * 1;
}

void VectorGrfxApp::mouseDragged(int x, int y, int button){

    //we add a new point to our line
    pts.push_back(ofPoint());
    int last = pts.size()-1;

    pts[last].x = x;
    pts[last].y = y;

}
// start storing the line
void VectorGrfxApp::mousePressed(int x, int y, int button){
    pts.clear();
    //store the first point of the line
    pts.push_back(ofPoint());
    pts[0].x = x;
    pts[0].y = y;

}