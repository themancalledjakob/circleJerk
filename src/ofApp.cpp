#include "ofApp.h"
float timer = 0;
//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
timer += 0.05;
ofBackground(ofRandom(75.0));
ofSetColor(ofRandom(205.0));
ofCircle(ofGetWidth()/2,ofGetHeight()/2,20 + 200 * (sin(timer) * 0.5 + 0.5));
ofSetColor(ofRandom(75.0));
ofCircle(ofGetWidth()/2,ofGetHeight()/2,10 + 180 * (sin(timer*0.9) * 0.5 + 0.5));
ofSetColor(ofRandom(75.0));
ofCircle(ofGetWidth()/2,ofGetHeight()/2,10 + 170 * (sin(timer*0.85) * 0.5 + 0.5));
ofSetColor(ofRandom(75.0));
ofCircle(ofGetWidth()/2,ofGetHeight()/2,10 + 160 * (sin(timer*0.8) * 0.5 + 0.5));
ofSetColor(ofRandom(75.0));
ofCircle(ofGetWidth()/2,ofGetHeight()/2,10 + 150 * (sin(timer*0.75) * 0.5 + 0.5));
ofSetColor(ofRandom(75.0));
ofCircle(ofGetWidth()/2,ofGetHeight()/2,10 + 140 * (sin(timer*0.7) * 0.5 + 0.5));

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
