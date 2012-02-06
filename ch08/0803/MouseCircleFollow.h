#ifndef _MOUSE_C_FOLLOW
#define _MOUSE_C_FOLLOW

#include "ofMain.h"

#define numOfCircles 20

class MouseCircleFollow : public ofBaseApp{

    public:

        void setup();
        void draw();
        void update();

        float xPos[numOfCircles];
        float yPos[numOfCircles];

        float dist(int startX, int startY, int endX, int endY);
        float createRandomizedNewPos(float in, float mouse);
        float max_distance;
};

#endif