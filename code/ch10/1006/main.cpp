#include "sineJoiner.h"

int main( ){

    // can be oF_WINDOW or oF_FULLSCREEN
    // pass in width and height too:
    ofSetupOpenGL(1200,768, OF_WINDOW);// <-------- setup the GL context
    // this kicks off the running of my app
    ofRunApp(new sineJoiner());

}