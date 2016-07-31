#pragma once

#include "ofMain.h"
#include "const.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofImage catImage;
    ofImage catColor;
    ofImage bgImage;
    int blendMode = 1;
    void applyBlendmode(int mode);
    ofFbo catColorMaskFbo;
    ofFbo catFbo;
    
    ofShader pixelateShader;
    ofShader colorShader;
    bool overlay = true;
    
    ofxPanel colorGui;
    ofParameter<int> hue;
    ofParameter<int> sat;
    ofParameter<int> b;
    ofParameter<float> extraRed;
    ofParameter<float> extraBlue;
    ofParameter<float> extraGreen;
    ofParameter<float> opacity;
    ofParameter<bool> bottomUp;
    ofParameter<float> dist;
    
    ofColor c;

		
};
