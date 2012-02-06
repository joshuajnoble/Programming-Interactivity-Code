#include "fragmenter.h"

void fragmenter::setup(){
	
    cubeLengths=12;
    vidWidth = 320;
    vidHeight = 240; 
    
	fragmentator.setGeometryInputType(GL_POINTS); // type: GL_POINTS, GL_LINES, GL_LINES_ADJACENCY_EXT, GL_TRIANGLES, GL_TRIANGLES_ADJACENCY_EXT
	fragmentator.setGeometryOutputType(GL_TRIANGLE_STRIP); // type: GL_POINTS, GL_LINE_STRIP or GL_TRIANGLE_STRIP
	fragmentator.setGeometryOutputCount(3);	// set number of output vertices
	
	fragmentator.load("fragmentator.vs", "fragmentator.fs", "fragmentator.gs");

	int i = 0;
	int j = 0;
	int k = 0;
	float imgWR, imgHR;
	imgWR = vidWidth/cubeLengths;
	imgHR = vidHeight/cubeLengths;
	while(i < cubeLengths){
		while(j < cubeLengths) {
			while(k < cubeLengths) {
				coord c;
				c.pos = new ofVec3f(sin(i) * vidWidth * 0.7, cos(j) * vidHeight * 0.7, k * 20);
				c.tx = new ofVec2f(i * imgWR, j * imgHR);
				coords.push_back(c);
				k++;
			}
			k = 0;
			j++;
		}
		j = 0;
		i++;
	}

	grab.initGrabber(vidWidth, vidHeight);
	
	mouseIsDown = false;	
}

void fragmenter::update(){
	if(rot > 360.f) rot = 0;
	grab.grabFrame();

	if(!mouseIsDown)
		rot+=0.01;
	
}

void fragmenter::draw(){
	
	ofBackground(255, 255, 255, 255);
	
	glPushMatrix();
	glTranslatef(ofGetWidth()/2, ofGetHeight()/2, 0);
	glRotatef(rot, 0, 1, 1);
	
	grab.getTextureReference().bind();
	
	fragmentator.begin();
	fragmentator.setUniform1f("rot", rot);
	fragmentator.setUniform1f("imgWidth", (float) vidWidth);
	fragmentator.setUniform1f("imgHeight", (float) vidHeight);

	glBegin(GL_POINTS);
	
	vector<coord>::iterator it = coords.begin();
	while(it != coords.end()) {
		glVertex3f( it->pos->x, it->pos->y, it->pos->z);
		glTexCoord2f(it->tx->x, it->tx->y);
		++it;
	}
	
	glEnd();
	grab.getTextureReference().unbind();
	fragmentator.end();
	
	glPopMatrix();
}

void fragmenter::mouseDragged(int x, int y, int button){
	rot = (float) x / 200.0;
}

void fragmenter::mousePressed(int x, int y, int button){
	mouseIsDown = true;
}

void fragmenter::mouseReleased(int x, int y, int button){
	mouseIsDown = false;
}
