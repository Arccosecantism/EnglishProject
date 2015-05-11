#pragma once

class Answer
{
public:
    Answer(ofVec2f pos, std::string tex, ofTrueTypeFont& f)
    void setPosition(ofVec2f p);
    int getClickedDataInt(ofVec2f& mousepos, bool& clicked, bool& pressed);
    void resetCorners();

    void update();
    void draw();

private:
    std::string text;
    vector<ofColor> colors;
    int fsize;
    ofVec2f position;
    ofTrueTypeFont* font;

    ofVec2f TLpos;
    ofVec2f BRpos;
};
