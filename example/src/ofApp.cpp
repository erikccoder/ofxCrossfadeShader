#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    imgA.loadImage("http://lorempixel.com/output/city-q-c-1024-768-6.jpg");
    imgB.loadImage("http://lorempixel.com/output/animals-q-c-1024-768-5.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
    float pct = sin(ofGetElapsedTimef());
    pct = ofMap(pct, -1, 1, 0, 1);
    
    ofxCrossfadeShader::beginShader(imgA.getTextureReference(), imgB.getTextureReference(), pct);
    imgA.draw(0, 0);
    ofxCrossfadeShader::endShader();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
