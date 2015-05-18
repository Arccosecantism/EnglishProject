#pragma once
#include "ofMain.h"

class Answer
{
public:

    Answer(ofVec2f pos, std::string tex, ofTrueTypeFont& f, ofTexture& bg, ofTexture& stbg, ofTexture& sts, bool cor);
    void setPosition(ofVec2f p);
    int getClickedDataInt(ofVec2f& mousepos, bool& clicked, bool& pressed, int& mouseButton);
    void resetCorners();
    void setText(std::string tex);
    void setCorrect(bool b);
    void setShowCorrect(bool b);
    void setDimensions(ofVec2f dim);
    bool getCorrect();
    ofVec2f getDimensions();
    ofVec2f getTextDrawSpots();
    int getAnswered();

    void reset();
    void update(ofVec2f& mousepos, bool& clicked, bool& pressed, int& mouseButton);
    void draw();

private:
    std::string text;
    vector<ofColor> colors;
    int colorPick;
    bool correct;
    bool selected;
    bool showCorrect;
    bool strikeThrough;
    ofVec2f position;
    ofTrueTypeFont* font;
    ofTexture* backgro;
    ofTexture* strikeThroughBG;
    ofTexture* strikeThroughS;

    ofVec2f TLpos;
    ofVec2f BRpos;
    ofVec2f windowMultiplier;
    ofVec2f dimensions;
};
