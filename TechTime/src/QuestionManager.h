#pragma once
#include "ofMain.h"
#include "Question.h"

class QuestionManager
{
public:
    QuestionManager();
    void setQuestionText(std::string newtext, int i);
    void setQuestionAnswered(int ans, int i);
    void update();
    void draw();

private:
    ofTrueTypeFont defaultFont;
    ofTexture questionBackground;
    ofTexture CMark;
    ofTexture XMark;

    vector<Question> questionVector;
    int questionNum;
};
