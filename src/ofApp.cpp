#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    catImage = ofImage("/Volumes/cat_image/cat_image/6_STANDING/stand_idle/hat0/cam2/0001.png");
    catColor = ofImage("/Volumes/cat_image/cat_image/dummy_red2.png");
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
    ofBackground(0, 0, 0);
    
    ofColor(255);
    catImage.draw(0,0);
    catColor.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key){
            
        case '1':
            ofEnableBlendMode(OF_BLENDMODE_ADD);
            ofLog() << "changing blend mode to OF_BLENDMODE_ADD";
            break;
            
        case '2':
            ofEnableBlendMode(OF_BLENDMODE_ALPHA);
            ofLog() << "changing blend mode to OF_BLENDMODE_ALPHA";
            break;
            
        case '3':
            ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
            ofLog() << "changing blend mode to OF_BLENDMODE_SUBTRACT";

            break;
            
        case '4':
            ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
            ofLog() << "changing blend mode to OF_BLENDMODE_MULTIPLY";

            break;
            
        case '5':
            ofEnableBlendMode(OF_BLENDMODE_SCREEN);
            ofLog() << "changing blend mode to OF_BLENDMODE_SCREEN";

            break;
            
        case '0':
            ofEnableBlendMode(OF_BLENDMODE_DISABLED);
            ofLog() << "changing blend mode to OF_BLENDMODE_DISABLED";

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
