#pragma once
#include "ofMain.h"

class Answer
{
public:

    Answer(ofVec2f pos, std::string tex, ofTrueTypeFont& f, ofTexture& bg, bool cor);
    void setPosition(ofVec2f p);
    int getClickedDataInt(ofVec2f& mousepos, bool& clicked, bool& pressed);
    void resetCorners();
    void setText(std::string tex);
    void setCorrect(bool b);

    void update(ofVec2f& mousepos, bool& clicked, bool& pressed);
    void draw();

private:
    std::string text;
    vector<ofColor> colors;
    int colorPick;
    bool correct;
    //int fsize;
    ofVec2f position;
    ofTrueTypeFont* font;
    ofTexture* backgro;

    ofVec2f TLpos;
    ofVec2f BRpos;
};
