#include "ofApp.h"
//#define NUM 80;
static const int N = 80;
vector<ofVec2f> pVec;
ofVboMesh delauMesh;

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableSmoothing();
    ofBackground(0);
    
    pVec.clear();
    delauMesh.clear();
    for (int i = 0; i < N; i++) {
        pVec.push_back(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())));
    }
    
    
    for(int i = 0; i < N-2; i++) {
        ofVec2f v1 = pVec[i];
        for(int j = i+1; j < N-1; j++) {
            ofVec2f v2 = pVec[j];
            for(int k = j+1; k < N; k++) {
                ofVec2f v3 = pVec[k];
                
                float tmp = 2.0*((v2.x-v1.x)*(v3.y-v1.y)-(v2.y-v1.y)*(v3.x-v1.x));
                ofVec2f center = ofVec2f(
                                         ((v3.y-v1.y)*(v2.x*v2.x-v1.x*v1.x+v2.y*v2.y-v1.y*v1.y)+
                                          (v1.y-v2.y)*(v3.x*v3.x-v1.x*v1.x+v3.y*v3.y-v1.y*v1.y))/tmp,
                                         ((v1.x-v3.x)*(v2.x*v2.x-v1.x*v1.x+v2.y*v2.y-v1.y*v1.y)+
                                          (v2.x-v1.x)*(v3.x*v3.x-v1.x*v1.x+v3.y*v3.y-v1.y*v1.y))/tmp
                                         );
                float r = ofDist(center.x,center.y, v1.x,v1.y) - 0.01;
                
                Boolean flg = false;
                for (int l = 0; l < N; l++) {
                    if (ofDist(center.x,center.y, pVec[l].x,pVec[l].y) < r) {
                        flg = true;
                        break;
                    }
                }
                ofFloatColor c = ofFloatColor( ofRandom(0.0,1.0), ofRandom(0.0,1.0), ofRandom(0.0,1.0) );
                if (!flg) {
                    //ofDrawLine(v1.x, v1.y, v2.x, v2.y);
                    //ofDrawLine(v2.x, v2.y, v3.x, v3.y);
                    //ofDrawLine(v3.x, v3.y, v1.x, v1.y);
                    delauMesh.addVertex(v1);
                    delauMesh.addColor(c);
                    delauMesh.addVertex(v2);
                    delauMesh.addColor(c);
                    delauMesh.addVertex(v3);
                    delauMesh.addColor(c);
                }
            }
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    delauMesh.setMode(OF_PRIMITIVE_TRIANGLES);
    delauMesh.draw();
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
    
    pVec.clear();
    delauMesh.clear();
    for (int i = 0; i < N; i++) {
        pVec.push_back(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())));
    }
    
    
    for(int i = 0; i < N-2; i++) {
        ofVec2f v1 = pVec[i];
        for(int j = i+1; j < N-1; j++) {
            ofVec2f v2 = pVec[j];
            for(int k = j+1; k < N; k++) {
                ofVec2f v3 = pVec[k];
                
                float tmp = 2.0*((v2.x-v1.x)*(v3.y-v1.y)-(v2.y-v1.y)*(v3.x-v1.x));
                ofVec2f center = ofVec2f(
                                         ((v3.y-v1.y)*(v2.x*v2.x-v1.x*v1.x+v2.y*v2.y-v1.y*v1.y)+
                                          (v1.y-v2.y)*(v3.x*v3.x-v1.x*v1.x+v3.y*v3.y-v1.y*v1.y))/tmp,
                                         ((v1.x-v3.x)*(v2.x*v2.x-v1.x*v1.x+v2.y*v2.y-v1.y*v1.y)+
                                          (v2.x-v1.x)*(v3.x*v3.x-v1.x*v1.x+v3.y*v3.y-v1.y*v1.y))/tmp
                                         );
                float r = ofDist(center.x,center.y, v1.x,v1.y) - 0.01;
                
                Boolean flg = false;
                for (int l = 0; l < N; l++) {
                    if (ofDist(center.x,center.y, pVec[l].x,pVec[l].y) < r) {
                        flg = true;
                        break;
                    }
                }
                ofFloatColor c = ofFloatColor( ofRandom(0.0,1.0), ofRandom(0.0,1.0), ofRandom(0.0,1.0) );
                if (!flg) {
                    //ofDrawLine(v1.x, v1.y, v2.x, v2.y);
                    //ofDrawLine(v2.x, v2.y, v3.x, v3.y);
                    //ofDrawLine(v3.x, v3.y, v1.x, v1.y);
                    delauMesh.addVertex(v1);
                    delauMesh.addColor(c);
                    delauMesh.addVertex(v2);
                    delauMesh.addColor(c);
                    delauMesh.addVertex(v3);
                    delauMesh.addColor(c);
                }
            }
        }
    }

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
