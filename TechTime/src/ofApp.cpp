#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);

}

//--------------------------------------------------------------
void ofApp::update(){
    gameMan.update(mousePos, clicked, pressed, mouseclicked);


    if(pressed == false)
    {
        clicked = false;
    }
    mouseclicked = 0;
    dragging = false;
}

//--------------------------------------------------------------
void ofApp::draw(){

    gameMan.draw();

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
   // mousePos.x = x;
  //  mousePos.y = y;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    dragging = false;
   // mousePos.x = x;
   // mousePos.y = y;
    pressed = true;

    //std::cout << mouseclicked << std::endl;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if(pressed == true)
    {
        pressed = false;
        clicked = true;

    }
    dragging = false;
    mouseclicked = 1 + button;

   // mousePos.x = x;
   // mousePos.y = y;
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
