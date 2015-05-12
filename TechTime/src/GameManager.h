#pragma once
#include "ofMain.h"
#include "AnswerManager.h"
#include "QuestionManager.h"

class GameManager
{
public:
    GameManager();
    void update(ofVec2f& mousePos, bool& clicked, bool& pressed);
    void draw();
    void fillQATexts(std::string filename);


private:
    AnswerManager answerMan;
    QuestionManager questionMan;
    ofTexture GameBG;
    std::vector<std::vector<std:string>> QASetTexts
};
