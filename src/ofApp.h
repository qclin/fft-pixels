#pragma once

#include "ofMain.h"
#include "fft.h"
#include "fftOctaveAnalyzer.h"
#include "ofxAsdfPixelSort.h"


#define BUFFER_SIZE_FFT 512

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    
    ofSoundPlayer beat;
    float * fftSmooth;
    int bands;
    
    
//    fft stuff
    void audioIn(float * input, int bufferSize, int nChannels);
    
    ofSoundStream soundStream;
    
    FFTOctaveAnalyzer FFTanalyzer;
    fft        myfft;
    float magnitude    [BUFFER_SIZE_FFT];
    float phase        [BUFFER_SIZE_FFT];
    float power        [BUFFER_SIZE_FFT];
    float freq        [BUFFER_SIZE_FFT];
    float avg_power = 0.0f;
    
    
    
    // ---------- pixel sort -----
    
    
    ofxAsdfPixelSort aps;
    bool saved;
    ofImage img;
};
