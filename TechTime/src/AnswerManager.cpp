#include "AnswerManager.h"

AnswerManager::AnswerManager()
{
    answerNum = 8;
    int wbw = 50;
    int hbw = 35;

    if(ofLoadImage(answerBackground, "AnswerBackground.png"))
    {

    }
    else
    {
        std::cout << "failed to load image :: AnswerBG " << std::endl;
    }

    if(ofLoadImage(strikeThruBG, "StrikeThroughBackGround.png"))
    {

    }
    else
    {
        std::cout << "failed to load image :: StrikeThruBG" << std::endl;
    }

    if(ofLoadImage(strikeThruS, "StrikeThrough.png"))
    {

    }
    else
    {
        std::cout << "failed to load image :: StrikeThruStrike" << std::endl;
    }


    defaultFont.loadFont("AlexandriaFLF.ttf", 18);

    Answer temp(ofVec2f(400,400), "TEST", defaultFont, answerBackground, strikeThruBG, strikeThruS, false);
    int cardsPerLine = 4;
    int cardRows = answerNum / cardsPerLine;

    double barlength = 15;

    double borderx = ofGetWindowWidth() - 2 * barlength * ofGetWindowWidth() / 1600.0;

    double bordery = (500 - 2 * barlength) * ofGetWindowHeight() / 1200.0;

    double xdim = (borderx - (cardsPerLine + 1) * wbw) / cardsPerLine;
    std::cout << borderx << "\t" << xdim << "\t"  << (borderx - (cardsPerLine + 1) * wbw) << std::endl;
    double ydim = (bordery - (cardRows + 1) * hbw) / cardRows;

    for (int i = 0; i < answerNum; i++)
    {
        answerVector.push_back(temp);
        answerVector[i].setPosition(ofVec2f(barlength + ((i % cardsPerLine) + 1) * wbw + (i % cardsPerLine) * xdim + xdim / 2,
                                    barlength + 700 * ofGetWindowHeight() / 1200.0 + (i / cardsPerLine + 1) * hbw + (i / cardsPerLine) * ydim + ydim / 2)
                                    );
        answerVector[i].setDimensions(ofVec2f(xdim,ydim));
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

void AnswerManager::setShowCorrect(bool b)
{
    if (getAnswered() == 1)
    {
        for (int i = 0; i < answerVector.size(); i++)
        {
            if (answerVector[i].getCorrect() == true)
            {
                answerVector[i].setShowCorrect(true);
            }
        }
    }
}

ofTrueTypeFont* AnswerManager::getFontPointer()
{
    ofTrueTypeFont* rfont = &defaultFont;
    return rfont;
}

ofVec2f AnswerManager::getDimensions(int i)
{
    return answerVector[i].getDimensions();
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
void AnswerManager::update(ofVec2f& mousePos, bool& clicked, bool& pressed, int& mouseButton)
{
    for (int i = 0; i < answerVector.size(); i++)
    {
        answerVector[i].update(mousePos, clicked, pressed, mouseButton);
    }
}

void AnswerManager::draw()
{
     for (int i = 0; i < answerVector.size(); i++)
    {
        answerVector[i].draw();
    }
}
