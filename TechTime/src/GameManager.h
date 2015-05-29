#pragma once
#include "ofMain.h"
#include "AnswerManager.h"
#include "QuestionManager.h"
#include "TriviaSet.h"

class GameManager
{
public:
    GameManager();
    void update(ofVec2f& mousePos, bool& clicked, bool& pressed, int& mouseButton);
    void draw();
    void fillQATexts();
    std::string intToString(int i);
    int stringToInt(std::string str);
    int intPow(int i, int j);
    std::string narrowString(std::string input, int width, bool QA);
    void setAllText(int trivset);


private:
    void setScoreString();
    void getBookFromCode();

    AnswerManager answerMan;
    QuestionManager questionMan;
    ofTexture GameBG;
    ofTexture GameFrame;
    ofTexture WinScreen;
    ofTrueTypeFont defaultFont;
    std::vector<TriviaSet> QASetTexts;
    int delayCounter;
    int setCounter;
    int answered;
    int threeTimePause;
    int score;
    int posScore;
    bool setScoreAlready;
    std::string scorestr;
    std::string bookName;
    bool won;
};
