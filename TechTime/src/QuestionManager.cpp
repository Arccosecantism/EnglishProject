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

    Question temp(ofVec2f(450,250), "TEST", defaultFont, questionBackground,
                  CMark, XMark);
    for (int i = 0; i < questionNum; i++)
    {
        questionVector.push_back(temp);
    }

    defaultFont.loadFont("Obelisk-MMXV.ttf", 20);
}

void QuestionManager::setQuestionText(std::string newtext, int i)
{
    questionVector[i].setText(newtext);
}

void QuestionManager::setQuestionAnswered(int ans, int i)
{
    questionVector[i].setAnswered(ans);
}

void QuestionManager::update()
{
    for (int i = 0; i < questionVector.size(); i++)
    {
        questionVector[i].update();
    }
}

void QuestionManager:: draw()
{
    for (int i = 0; i < questionVector.size(); i++)
    {
        questionVector[i].draw();
    }
}
