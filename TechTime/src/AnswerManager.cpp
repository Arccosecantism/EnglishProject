#include "AnswerManager.h"

AnswerManager::AnswerManager()
{
    answerNum = 8;
    int wbw = 80;
    int hbw = 35;

    if(ofLoadImage(answerBackground, "AnswerBackground.png"))
    {

    }
    else
    {
        std::cout << "failed to load image :: " << std::endl;
    }
    std::cout << ofGetScreenWidth();
    defaultFont.loadFont("AlexandriaFLF.ttf", 18);
    Answer temp(ofVec2f(400,400), "TEST", defaultFont, answerBackground, false);
    int cardsPerLine = ofGetWindowWidth() / (wbw + answerBackground.getWidth());
    wbw = (ofGetWindowWidth() - (cardsPerLine * answerBackground.getWidth())) / (1 + cardsPerLine);
    //std::cout << bw << std::endl;
    for (int i = 0; i < answerNum; i++)
    {
        answerVector.push_back(temp);
        answerVector[i].setPosition(ofVec2f(((i % cardsPerLine) + 1) * wbw + (i % cardsPerLine) * answerBackground.getWidth() + answerBackground.getWidth()/2,
                                    ofGetWindowHeight() * .71 + (i / cardsPerLine) * (hbw + answerBackground.getHeight()))
                                    );
    }
}
//    void setBGTextureByString(std::string bgnam);
//    void setFontByString(std::string bgnam);
void AnswerManager::setAnswerText(std::string newtext, int i)
{
    answerVector[i].setText(newtext);
}

void AnswerManager::setCorrect(bool b, int i)
{
    answerVector[i].setCorrect(b);
}

ofTrueTypeFont* AnswerManager::getFontPointer()
{
    ofTrueTypeFont* rfont = &defaultFont;
    return rfont;
}
int AnswerManager::getAnswered()
{
    int answered = 0;
    bool correct = false;
    int temp;
    for (int i = 0; i < answerVector.size(); i++)
    {
        temp = answerVector[i].getAnswered();
        if (temp != 0)
        {
            if (temp == 2)
            {
                correct = true;
            }
            answered++;
        }
        if (answered == 2 or correct == true)
        {
            break;
        }
    }
    if (correct == true)
    {
        return 2;
    }
    else if (answered > 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int AnswerManager::getAnswerNum()
{
    return answerNum;
}

void AnswerManager::resetAnswers()
{
    for (int i = 0; i < answerVector.size(); i++)
    {
        answerVector[i].reset();
    }
}
void AnswerManager::update(ofVec2f& mousePos, bool& clicked, bool& pressed)
{
    for (int i = 0; i < answerVector.size(); i++)
    {
        answerVector[i].update(mousePos, clicked, pressed);
    }
}

void AnswerManager::draw()
{
     for (int i = 0; i < answerVector.size(); i++)
    {
        answerVector[i].draw();
    }
}
