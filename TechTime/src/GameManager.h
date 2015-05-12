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


private:
    AnswerManager answerMan;
    QuestionManager questionMan;
    ofTexture GameBG;
};
