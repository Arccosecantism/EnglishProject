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
    void setCorrect(bool b, int i);
    void setShowCorrect(bool b);
    ofTrueTypeFont* getFontPointer();
    ofVec2f getDimensions(int i);
    int getAnswered();
    int getAnswerNum();
    std::string getSelectedText();

    void resetAnswers();
    void update(ofVec2f& mousePos, bool& clicked, bool& pressed, int& mouseButton);
    void draw();

private:
    ofTexture answerBackground;
    ofTexture strikeThruBG;
    ofTexture strikeThruS;
    ofTrueTypeFont defaultFont;
    std::vector<Answer> answerVector;
    int answerNum;
};
