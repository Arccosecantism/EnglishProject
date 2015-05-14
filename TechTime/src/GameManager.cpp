#include "GameManager.h"
#include <sstream>

GameManager::GameManager()
{
    if(ofLoadImage(GameBG, "GameBackground.png"))
    {

    }
    else
    {
        std::cout << "failed to load image GameBG" << std::endl;
    }
    if(ofLoadImage(GameFrame, "GameFrame.png"))
    {

    }
    else
    {
        std::cout << "failed to load image GameFR" << std::endl;
    }

    fillQATexts();

    setCounter = 0;
    setAllText(setCounter);
    delayCounter = -1;
    answered = 0;
    threeTimePause = 0;
}

void GameManager::fillQATexts()
{
    std::string questiontex = "";
    std::string answertex = "";
    std::string line;
    TriviaSet filler;
    int decad;
    int QA = 0;
    int counter = -1;
    bool firstline = true;
    std::ifstream QAtexts("../bin/data/QuestionAnswers.txt");

    if (QAtexts.is_open())
    {
        while(getline(QAtexts, line))
        {
   //         std::cout << line << std::endl << std::endl;
            if (line == "-n-")
            {
                QASetTexts.push_back(filler);
                counter ++;
            }
            if (QA == 1)
            {
                if (line == "-.-")
                {

                    QA = 0;
                    QASetTexts[counter].addQuestionText(narrowString(questiontex, 350, false));
                    questiontex = "";
                    firstline = true;
                }
                else if (line == "-&-")
                {
                    QASetTexts[counter].addQuestionText(questiontex);
                    questiontex = "";
                    firstline = true;
                }
                else
                {
                    if (firstline == true)
                    {
                        firstline = false;
                    }
                    else
                    {
                        questiontex += (" ");
                    }
                    questiontex += (line);
                }
            }

            else if (QA == 2)
            {
                if (line == "-.-")
                {
                    QA = 0;
                    QASetTexts[counter].addAnswerText(narrowString(answertex, 150, true));
                    answertex = "";
                    firstline = true;
                }
                else if (line == "-&-")
                {
                    QASetTexts[counter].addAnswerText(narrowString(answertex, 150, true));
                    answertex = "";
                    firstline = true;
                }
                else
                {
                    if (firstline == true)
                    {
                        firstline = false;
                    }
                    else
                    {
                        answertex += (" ");
                    }
                    answertex += (line);
                }
            }

            if (line[0] == 'Q' and line[1] == 'Q' and QA == 0)
            {
                QA = 1;
                decad = 1000*(line[2]-'0') + 100 * (line[3]-'0') + 10 * (line[4]-'0');
                QASetTexts[0].setDecade(decad);
            }

            else if (line[0] == 'A' and line[1] == 'A' and QA == 0)
            {
                QA = 2;
            }
            if (line == "-END")
            {
                break;
            }

        }
    }
//    for (int i = 0; i < QASetTexts.size(); i++)
//    {
//        for (int j = 0; j < QASetTexts[i].getQuestionVector().size(); j++)
//        {
//            std::cout << QASetTexts[i].getQuestionVector()[j] << std::endl;
//        }
//        std::cout << std::endl;
//        for (int j = 0; j < QASetTexts[i].getAnswerVector().size(); j++)
//        {
//            std::cout << QASetTexts[i].getAnswerVector()[j] << std::endl;
//        }
//        std::cout << std::endl << std::endl;
//    }




}

std::string GameManager::narrowString(std::string input, int width, bool QA)
{
    int index;
    int length;
    std::string returnThis = "";
    std::string line = "";
    std::string woord = "";
    for (int i = 0; i < input.size(); i++)
    {
        woord += input[i];
        if (input[i] == ' ')
        {
            index = i;
            line+=woord;
            woord = "";
        }


        if (QA == false)
        {
            length = questionMan.getFontPointer()->stringWidth(line + woord);
        }
        else
        {
            length = answerMan.getFontPointer()->stringWidth(line + woord);
        }
        if (length > width)
        {
            woord = "\n";
            line+=woord;
            returnThis+=line;
            line = "";
            woord = "";
            i = index;
        }
        if (i == input.size() - 1)
        {
            line+=woord;
            returnThis+=line;
            line = "";
            woord = "";
        }
    }
    return returnThis;
}


void GameManager::setAllText(int trivset)
{
    for (int i = 0; i < questionMan.getQuestionNum(); i++)
    {


        questionMan.setQuestionText(QASetTexts[trivset].getQuestionVector()[i], i);
        questionMan.setQuestionDecade(QASetTexts[trivset].getDecade(), i);

    }

    int ansListSize = QASetTexts[trivset].getAnswerVector().size();
    std::string corCheck = "";
    for (int i = 0; i < answerMan.getAnswerNum(); i++)
    {
        if (i < ansListSize)
        {
            corCheck = QASetTexts[trivset].getAnswerVector()[i];

            if (corCheck[0] == '*' and corCheck [1] == '*')
            {
               answerMan.setCorrect(true, i);
               std::string convert = "";
               for (int j = 2; j < corCheck.size(); j++)
               {
                   convert += corCheck[j];
               }
               corCheck = convert;
            }
            answerMan.setAnswerText(corCheck,i);
        }
        else
        {
            answerMan.setAnswerText("",i);
        }
    }
}

void GameManager::update(ofVec2f& mousePos, bool& clicked, bool& pressed)
{
    if (delayCounter < 0)
    {
        answered = answerMan.getAnswered();
       // std::cout << std::endl << answered << "\t" << threeTimePause << std::endl << std::endl;
        answerMan.update(mousePos, clicked, pressed);
        questionMan.update();
        questionMan.setAnswered(answered);
      //  std::cout << std::endl << questionMan.getAnswered() << std::endl << std::endl;
        if (threeTimePause > 2)
        {
            delayCounter = 100;
            ofSetBackgroundAuto(false);
        }
        if (answered != 0)
        {
            threeTimePause ++;

        }

    }
    else
    {
        delayCounter --;
    }
};

void GameManager::draw()
{
    if (delayCounter < 0)
    {
        GameBG.draw(ofVec2f(0,0), ofGetWindowWidth(), ofGetWindowHeight());
        GameFrame.draw(ofVec2f(0,0),  ofGetWindowWidth(), ofGetWindowHeight());
        answerMan.draw();
        questionMan.draw();
       // std::cout << "here" << questionMan.getAnswered() << std::endl;

    }
    else
    {
        if (delayCounter == 1 or delayCounter == 0)
        {
            ofSetBackgroundAuto(true);
            setCounter ++;
            answerMan.resetAnswers();
            questionMan.resetQuestions();
            setAllText(setCounter);
            delayCounter = -5;
            threeTimePause = 0;


        }
        delayCounter --;
       // std::cout << delayCounter << std::endl;
        //THE PROBLEM IS THE DELAY COUNTER IS LOOPING
    }

}
