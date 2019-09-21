#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(2);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {


}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 0.5);

	auto size = 50;
	for (int x = -100; x <= 100; x += size) {

		for (int y = -100; y <= 100; y += size) {

			for (int z = -100; z <= 100; z += size) {

				auto noise_value = ofNoise(x * 0.005, y * 0.005, z * 0.005, ofGetFrameNum() * 0.008);
				if (noise_value > 0.5) {

					ofPushMatrix();
					ofTranslate(x, y, z);

					ofNoFill();
					ofSetColor(39);
					ofDrawBox(size * 0.9);

					if (noise_value > 0.65) {

						ofFill();
						ofSetColor(239);
						ofDrawBox(size * 0.88);
					}

					ofPopMatrix();
				}
			}
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}