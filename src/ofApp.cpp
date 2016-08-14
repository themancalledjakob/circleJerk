#include "ofApp.h"
float timer = 0;
unsigned long lastHop = 0;
int interval = 15000;
float tspeed = 0.05;
//--------------------------------------------------------------
void ofApp::setup(){
	state = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	unsigned long now = ofGetElapsedTimeMillis();
	if( now > lastHop + interval ) {
		lastHop = now;
		state++;
		ofSetCircleResolution((int)(ofRandom(16)+3));
		tspeed = ofRandom(0.05) + 0.01;
	}
}
void ofApp::randomCircle(float diameter, float min, float max, float rd, float rx, float ry, float rz) {
	ofSetColor(min + ofRandom(max-min));
	ofRotate(rd, rx, ry, rz);
	ofCircle(0,0,diameter);
}

//--------------------------------------------------------------
void ofApp::draw(){
ofBackground(ofRandom(75.0)); // maybe me revoked when lines is true

timer += tspeed;
float rd = 0.0f;
float rx = 0.0f;
float ry = 0.0f;
float rz = 0.0f;
bool lines = false;
if (state %8 == 0) {
	rd = timer;
	rx = 1.0;
	ofEnableDepthTest();
} else if (state%3 == 0) {
	rd = timer;
	rz = 1.0;
} else {
	ofPushStyle();
	lines = true;
	ofNoFill();
	ofSetLineWidth(1);
	ofBackground(0);
}
ofHideCursor();
ofTranslate(ofGetWidth()/2,ofGetHeight()/2,0.0);
for (int i =0; i < 10; i++) {
	float maxD = ((10-i) * 20 + 100);
	float speed = 1.0 - (i * 0.05);
	float d = 10 + maxD * (sin(timer * speed) * 0.5 + 0.5);
	float max = i == 8 ? 205.0f : 75.0f;
	float min = 0.0;
	randomCircle( d, min, max, rd, rx, ry, rz);
}
if( lines ) {
	ofPopStyle();
}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
