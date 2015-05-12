#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){



}

//--------------------------------------------------------------
void ofApp::update(){
    if (clicked == true)
    {
        std::cout << "here" << std::endl;
    }
    answerMan.update(mousePos, clicked, pressed);


    if(pressed != true)
    {
        clicked = false;
    }
    dragging = false;
}

//--------------------------------------------------------------
void ofApp::draw(){

    answerMan.draw();
    ofSetColor(ofColor::red);
    ofCircle(400,400,2);
    ofSetColor(ofColor::white);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    mousePos.x = x;
    mousePos.y = y;
    dragging = false;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    dragging = true;
    mousePos.x = x;
    mousePos.y = y;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    dragging = false;
    mousePos.x = x;
    mousePos.y = y;
    pressed = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if(pressed == true)
    {
        pressed = false;
        clicked = true;
    }
    dragging = false;
    mousePos.x = x;
    mousePos.y = y;
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
