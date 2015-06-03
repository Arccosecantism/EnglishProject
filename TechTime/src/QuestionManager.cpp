#include "QuestionManager.h"

QuestionManager::QuestionManager()
{
    questionNum = 1;
    if(ofLoadImage(questionBackground, "QuestionBackground.png"))
    {

    }
    else
    {
        std::cout << "failed to load image QB" << std::endl;
    }

    if(ofLoadImage(CMark, "Checkmark.png"))
    {

    }
    else
    {
        std::cout << "failed to load image Checkmark" << std::endl;
    }

    if(ofLoadImage(XMark, "Xmark.png"))
    {

    }
    else
    {
        std::cout << "failed to load image Xmark" << std::endl;
    }

    Question temp(ofVec2f(ofGetWindowWidth()/2, .32 * ofGetWindowHeight()), "TEST", defaultFont, questionBackground,
                  CMark, XMark);
    for (int i = 0; i < questionNum; i++)
    {
        questionVector.push_back(temp);
        questionVector[i].setDimensions(ofVec2f(500,500));
    }

    defaultFont.loadFont("AlexandriaFLF.ttf", 24);
    answered = 0;
}

void QuestionManager::setQuestionText(std::string newtext, int i)
{
    questionVector[i].setText(newtext);
}

void QuestionManager::setQuestionDecade(int dec, int i)
{
    questionVector[i].setDecade(dec);
}

void QuestionManager::setQuestionAnswered(int ans, int i)
{
    questionVector[i].setAnswered(ans);
}

void QuestionManager::setAnswered(int i)
{
    answered = i;
}

void QuestionManager::resetQuestions()
{
    for (int i = 0 ; i < questionVector.size(); i++)
    {
        questionVector[i].reset();
    }
}

int QuestionManager::getQuestionNum()
{
    return questionNum;
}

int QuestionManager::getAnswered()
{
    return answered;
}

ofTrueTypeFont* QuestionManager::getFontPointer()
{
    ofTrueTypeFont* rfont = &defaultFont;
    return rfont;
}

ofVec2f QuestionManager::getDimensions(int i)
{
    return questionVector[i].getDimensions();
}

void QuestionManager::update()
{
    for (int i = 0; i < questionVector.size(); i++)
    {
        questionVector[i].update();
        questionVector[i].setAnswered(answered);
    }
}

void QuestionManager:: draw()
{
    for (int i = 0; i < questionVector.size(); i++)
    {
        questionVector[i].draw();
    }
}
