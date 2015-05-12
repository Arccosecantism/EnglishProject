#pragma once
#include "ofMain.h"

class Question
{
public:
    Question(ofVec2f pos, std::string qtex, ofTrueTypeFont& ffont, ofTexture& fbackgro, ofTexture& frightAns, ofTexture& fwrongAns);
    void setAnswered(int i);
    void setPosition(ofVec2f p);
    void setText(std::string newtext);
    void resetCorners();
    void update();
    void draw();
private:
    ofVec2f position;
    std::string text;
    ofTrueTypeFont* font;
    ofTexture* backgro;
    ofTexture* rightAns;
    ofTexture* wrongAns;
    ofVec2f TLpos;
    ofVec2f BRpos;

    int answered;


};
