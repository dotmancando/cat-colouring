#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    catImage = ofImage("/Volumes/KINGSTON/cat_image/6_STANDING/stand_idle/hat0/cam2/0001.png");
    catColor = ofImage("/Volumes/KINGSTON/cat_image/dummy_red.png");
    bgImage = ofImage("/Volumes/KINGSTON/kinect_image/finalSetup14/image_RGB_0.png");
    ofEnableBlendMode(OF_BLENDMODE_DISABLED);
    ///     OF_BLENDMODE_DISABLED
    ///     OF_BLENDMODE_ALPHA
    ///     OF_BLENDMODE_ADD
    ///     OF_BLENDMODE_SUBTRACT
    ///     OF_BLENDMODE_MULTIPLY
    ///     OF_BLENDMODE_SCREEN
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofBackground(0, 0, 0);
    bgImage.draw(0,0,APP_WIDTH, APP_HEIGHT);
    ofColor(255);
    applyBlendmode(1);
    catImage.draw(200,200);
    applyBlendmode(blendMode);
    catColor.draw(200,200);
    applyBlendmode(0);
    
    
    ofDrawBitmapStringHighlight("BLENDMODE: " + ofToString(  BLENDMODE_NAME[blendMode]), 10, APP_HEIGHT - 50);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key){
            
        case '1':
            blendMode = 1;
//            ofEnableBlendMode(OF_BLENDMODE_ADD);
            ofLog() << "changing blend mode to OF_BLENDMODE_ALPHA";
            break;
            
        case '2':
            blendMode = 2;
//            ofEnableBlendMode(OF_BLENDMODE_ALPHA);
            ofLog() << "changing blend mode to OF_BLENDMODE_ADD";
            break;
            
        case '3':
            blendMode = 3;
//            ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
            ofLog() << "changing blend mode to OF_BLENDMODE_SUBTRACT";

            break;
            
        case '4':
            blendMode = 4;
//            ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
            ofLog() << "changing blend mode to OF_BLENDMODE_MULTIPLY";

            break;
            
        case '5':
            blendMode = 5;
//            ofEnableBlendMode(OF_BLENDMODE_SCREEN);
            ofLog() << "changing blend mode to OF_BLENDMODE_SCREEN";

            break;
            
        case '0':
            blendMode = 0;
//            ofEnableBlendMode(OF_BLENDMODE_DISABLED);
            ofLog() << "changing blend mode to OF_BLENDMODE_DISABLED";

            break;
        
    }

}

void ofApp::applyBlendmode(int mode){
    switch (mode){
            
        case 0:
            ofEnableBlendMode(OF_BLENDMODE_DISABLED);
            break;
            
        case 1:
            ofEnableBlendMode(OF_BLENDMODE_ALPHA);
            break;
            
        case 2:
            ofEnableBlendMode(OF_BLENDMODE_ADD);
            break;
            
        case 3:
            ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
            break;
            
        case 4:
            ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
            break;
            
        case 5:
            ofEnableBlendMode(OF_BLENDMODE_SCREEN);
            break;
            
            
            
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
