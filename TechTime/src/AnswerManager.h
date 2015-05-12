#pragma once
#include "ofMain.h"
#include "Answer.h"

class AnswerManager
{
public:
    AnswerManager();
//    AnswerManager(std::string bgnam, std::string fnam);
//    void setBGTextureByString(std::string bgnam);
//    void setFontByString(std::string bgnam);
    void setAnswerText(std::string newtext, int i);
    void update(ofVec2f& mousePos, bool& clicked, bool& pressed);
    void draw();

private:
    ofTexture answerBackground;
    ofTrueTypeFont defaultFont;
    std::vector<Answer> answerVector;
    int answerNum;
};
