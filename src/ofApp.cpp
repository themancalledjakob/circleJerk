#include "ofApp.h"
float timer = 0;
unsigned long lastHop = 0;
int interval = 15000;
float tspeed = 0.05;
int videoIndex = 0;

//--------------------------------------------------------------
void ofApp::setup(){
	state = 0;
/*	loadVideo("movies/booboo.mp4",0.5f);
	loadVideo("movies/bambi.mp4",0.75f);
	loadVideo("movies/brucelee.mp4",2.0f);
	loadVideo("movies/fingers.mov",0.5f);
	loadVideo("movies/grizzly.mp4",1.1f);
	loadVideo("movies/heidi.mp4",1.0f);
	for (int i = 0; i < fs.size(); i++) {
		fs[i].play();
	}*/
}

void ofApp::loadVideo(string path, float fspeed) {
	ofVideoPlayer f;
	f.loadMovie(path);
	f.setLoopState(OF_LOOP_NORMAL);
	f.setSpeed(fspeed);
	fs.push_back(f);
}

//--------------------------------------------------------------
void ofApp::update(){
//	for (int i = 0; i < fs.size(); i++) {
//		fs[i].update();
//	}

	unsigned long now = ofGetElapsedTimeMillis();
	if( now > lastHop + interval ) {
		lastHop = now;
		state=5;
		ofSetCircleResolution((int)(ofRandom(16)+3));
		tspeed = ofRandom(0.05) + 0.01;
/*
		if (state %8 == 0) {
		} else if (state%3 == 0) {
		} else if (state%5 == 0) {
			videoIndex++;
			videoIndex = videoIndex%fs.size();
		}*/
	}
}
void ofApp::randomCircle(float diameter, float min, float max, float rd, float rx, float ry, float rz) {
	float r = min + ofRandom(max-min);
	float g = min + ofRandom(max-min);
	float b = min + ofRandom(max-min);
	if(state%3==0) {
		ofSetColor(r,g,b);
	} else {
		ofSetColor(r);
	}
	ofRotate(rd, rx, ry, rz);
	ofCircle(0,0,diameter);
}

//--------------------------------------------------------------
void ofApp::draw(){
ofBackground(ofRandom(75.0)); // maybe me revoked when lines is true
ofPushMatrix();

bool video = false;

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
//} else if (state%5 == 0) {
//	fs[videoIndex].draw(0,0,ofGetWidth(),ofGetHeight());
//	video = true;
} else {
	ofPushStyle();
	lines = true;
	ofNoFill();
	ofSetLineWidth(1);
	ofBackground(0);
}
ofHideCursor();
if (!video) {
	ofTranslate(ofGetWidth()/2,ofGetHeight()/2,0.0);
	for (int i =0; i < 10; i++) {
		float maxD = ((10-i) * 20 + 100);
		float speed = 1.0 - (i * 0.05);
		float d = 10 + maxD * (sin(timer * speed) * 0.5 + 0.5);
		float max = i == 8 ? 205.0f : 75.0f;
		float min = 0.0;
		randomCircle( d, min, max, rd, rx, ry, rz);
	}
}
if( lines ) {
	ofPopStyle();
}
ofPopMatrix();
string msg = ofToString(state) + " v: " + ofToString(video);
ofDrawBitmapString(msg,120,120);
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
