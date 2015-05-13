#include "AnswerManager.h"

AnswerManager::AnswerManager()
{
    answerNum = 8;
    int bw = 20;

    if(ofLoadImage(answerBackground, "AnswerBackground.png"))
    {

    }
    else
    {
        std::cout << "failed to load image :: " << std::endl;
    }

    defaultFont.loadFont("Obelisk-MMXV.ttf", 14);
    Answer temp(ofVec2f(400,400), "TEST", defaultFont, answerBackground, false);
    for (int i = 0; i < answerNum; i++)
    {
        answerVector.push_back(temp);
        answerVector[i].setPosition(ofVec2f(((i % 4) + 1) * bw + (i % 4) * answerBackground.getWidth() + answerBackground.getWidth()/2,
                                    ofGetWindowHeight() - ((2 - (i / 4)) * bw + (1 - (i / 4)) * answerBackground.getHeight() + answerBackground.getHeight()/2))
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
