#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);

//    sound section
    soundStream.setup(this, 0, 1, 44100, 512, 4);
    
    FFTanalyzer.linearEQIntercept = 0.8f; // reduced gain at lowest frequency
    FFTanalyzer.linearEQSlope = 0.09f; // increasing gain at higher frequencies
    FFTanalyzer.setup(44100, 512, 3); // increase number of bins for more inputs
    
    
    
//---------------pixel sort section ---------------
    
    img.loadImage(ofToDataPath("003_4A.jpg"));
    img.resize(360, 360);
    
    ofSetWindowShape(img.getWidth(), img.getHeight());
    
    saved = false;
    
    
}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    myfft.powerSpectrum(0,bufferSize/2, input, bufferSize, &magnitude[0], &phase[0], &power[0], &avg_power);
    
    
}



//--------------------------------------------------------------
void ofApp::update(){
    FFTanalyzer.calculate(magnitude);
    
    FFTanalyzer.nAverages;
    
    //    aps.setup(img);
    //    y value : -13000000
    //    black, bright, white
    

    aps.setup(img, 0, 1 + ofGetElapsedTimef(), -16000000 + 10000* -FFTanalyzer.averages[10] * 5, 60, -13000000 );

    //    for (int i = 0; i < 30; i++) {
    //        aps.row = mouseY + i;
    //        aps.sortRow();
    //    }
    
    while(!aps.isSortDone()) {
        aps.update();
    }
    if( aps.isSortDone() && !saved ) {
        aps.getImage().saveImage(ofToDataPath("sorted.jpg"));
        saved = true;
    }
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
//    cout << FFTanalyzer.nAverages << endl; // 26 channels
    
    for (int i = 0; i < FFTanalyzer.nAverages; i++){
        ofDrawRectangle(i*20, 400, 20,  -FFTanalyzer.averages[i] * 5);

        cout << -FFTanalyzer.averages[i] << endl;
    }
    
    
    
    aps.draw();
    
    ///// HOW CAN I GET -FFTanalyzer.averages[i] to map to PIXEL VALUES
    
//    / DETROIT !
//     character from 0 - 255, usually for colors
    // * is a pointer, a position in memory, alias links to where unsigned char is
        unsigned char * data = img.getPixels().getData();
    
        for(int i =0; i < img.getWidth(); i+=10){
            for(int j =0; j < img.getHeight(); j+=10){
    
                // y*w + x
                int index = j * img.getWidth() + i;
                /// since data is store linearly so eachline is appended to the array
                int brightness = data[index];
                ofDrawCircle(i, j, ofMap(brightness,0,255,0,5));
                // data[0]
                // data[10]
            }
    
        }
    
    
    img.draw(0,0);
    
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
