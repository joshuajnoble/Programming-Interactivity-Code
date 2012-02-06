#pragma mark once

#include "ofMain.h"

class MouseResponseColor : public ofBaseApp{

public:

    void setup();
    void draw();

    float getDistance(int startX, int startY, int endX, int endY);

    float max_distance;
};
