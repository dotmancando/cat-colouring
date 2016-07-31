#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    catImage = ofImage("0001.png");
//    catColor = ofImage("/Volumes/KINGSTON/cat_image/dummy_red.png");
    bgImage = ofImage("image_RGB_0.png");
//    ofEnableBlendMode(OF_BLENDMODE_DISABLED);

    catColorMaskFbo.allocate(CAT_IMAGE_WIDTH, CAT_IMAGE_HEIGHT);
    catFbo.allocate(CAT_IMAGE_WIDTH, CAT_IMAGE_HEIGHT);
    
    pixelateShader.load("pixelation");
    colorShader.load("color");
    
//    ofxPanel colorGui;
//    ofParameter<float> extraRed;
//    ofParameter<float> opacity;

    
    colorGui.setup("color");
    colorGui.add(hue.set("H", 0, 0, 255 ));
    colorGui.add(sat.set("S", 255, 0, 255 ));
    colorGui.add(b.set("B", 255, 0, 255 ));
    colorGui.add(opacity.set("opacity", 0.5, 0.0, 1.0 ));
    colorGui.add(bottomUp.set("bottomUp",false ));


    
    colorGui.add(extraRed.set("red", 0.5, 0.0, 1.0 ));
    colorGui.add(extraBlue.set("green", 0.5, 0.0, 1.0 ));
    colorGui.add(extraGreen.set("blue", 0.5, 0.0, 1.0 ));
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    c.setHsb(hue, sat, b);
    extraRed = c.r / 255.0;
     extraGreen = c.g / 255.0;
     extraBlue = c.b / 255.0;
    
//    c = ofColor(255,0,0);
    
    catFbo.begin();
    ofClear(0,0,0,0);
    
    pixelateShader.begin();
    pixelateShader.setUniform1f("pixelSize", 4.0);
    pixelateShader.setUniform1f("extraRed", 0.0);
    pixelateShader.setUniform1f("extraBlue", 0.0);
    
    catImage.draw(0,0);
    pixelateShader.end();
    catFbo.end(); 
    
    
    
    
    catColorMaskFbo.begin();
    ofClear(0,0,0,0);
    
    colorShader.begin();
    colorShader.setUniform1f("pixelSize", 1.0);
    colorShader.setUniform1f("extraRed", extraRed);
    colorShader.setUniform1f("extraGreen", extraGreen);
    colorShader.setUniform1f("extraBlue", extraBlue);
    colorShader.setUniform1f("opacity", opacity);
    
    catFbo.draw(0,0);
    pixelateShader.end();
    catColorMaskFbo.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofBackground(0, 0, 0);
    ofSetColor(255);
    bgImage.draw(0,0,APP_WIDTH, APP_HEIGHT);
    applyBlendmode(1);
    catFbo.draw(200,200);
    if(overlay){
        applyBlendmode(blendMode);
        catColorMaskFbo.draw(200,200);
    }
    applyBlendmode(0);
    
    
    ofDrawBitmapStringHighlight("BLENDMODE: " + ofToString(  BLENDMODE_NAME[blendMode]), 10, APP_HEIGHT - 50);
    
    colorGui.draw();
    
    ofSetColor(c);
    ofDrawEllipse(100, 200, 50, 50);
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
        
        case 'o':
            overlay = !overlay;
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
