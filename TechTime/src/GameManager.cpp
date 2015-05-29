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
    if(ofLoadImage(WinScreen, "WinScreen.png"))
    {

    }
    else
    {
        std::cout << "failed to load image WinScreen" << std::endl;
    }

    defaultFont.loadFont("AlexandriaFLF.ttf", 40);

    fillQATexts();

    setCounter = 0;
    setAllText(setCounter);
    delayCounter = -1;
    answered = 0;
    threeTimePause = 0;
    won = false;
    score = 0;
    posScore = 0;
    setScoreAlready = false;
    setScoreString();
    getBookFromCode();
}

void GameManager::fillQATexts()
{
    int aborder = 30;
    int qborder = 25;
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
                    QASetTexts[counter].addQuestionText(narrowString(questiontex, questionMan.getDimensions(0).x - 2 * qborder, false));
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
                    QASetTexts[counter].addAnswerText(narrowString(answertex, answerMan.getDimensions(0).x - 2 * aborder, true));
                    answertex = "";
                    firstline = true;
                }
                else if (line == "-&-")
                {
                    QASetTexts[counter].addAnswerText(narrowString(answertex, answerMan.getDimensions(0).x - 2 * aborder, true));
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
                decad = line[2];
                QASetTexts[counter].setDecade(decad);
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

std::string GameManager::intToString(int i)
{
    stringstream convert;
    convert << i;
    std::string returnme = convert.str();
    return returnme;
}

int GameManager::stringToInt(std::string str)
{
    int sum = 0;
    for (int i = 0; i < str.length(); i++)
    {
        sum += str[i]*intPow(10, (str.length() - i - 1));
    }
    return sum;
}

int GameManager::intPow(int i, int j)
{
    int product = 1;
    for (int k = 0; k < j; k++)
    {
        product *= i;
    }
    return product;
}

void GameManager::setAllText(int trivset)
{
    ofSeedRandom();
    std::vector<std::string> scrambled;
    std::vector<int> RandomNonRepeat;
    std::vector<int> listofNums;
    int ran;
    int Asize = QASetTexts[trivset].getAnswerVector().size();
    for (int i = 0; i < Asize; i++)
    {
        listofNums.push_back(i);
    }
    for (int i = 0; i < Asize; i++)
    {
        ran = ofRandom(0, listofNums.size());
        RandomNonRepeat.push_back(listofNums[ran]);

        listofNums.erase(listofNums.begin()+ran);
    }
    for (int i = 0; i < Asize; i++)
    {
        scrambled.push_back(QASetTexts[trivset].getAnswerVector()[RandomNonRepeat[i]]);
    }

    for (int i = 0; i < questionMan.getQuestionNum(); i++)
    {


        questionMan.setQuestionText(QASetTexts[trivset].getQuestionVector()[i], i);
        questionMan.setQuestionDecade(QASetTexts[trivset].getDecade(), i);

    }

    int ansListSize = scrambled.size();
    std::string corCheck = "";
    for (int i = 0; i < answerMan.getAnswerNum(); i++)
    {
        if (i < ansListSize)
        {
            corCheck = scrambled[i];

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

void GameManager::update(ofVec2f& mousePos, bool& clicked, bool& pressed, int& mouseButton)
{
    if (delayCounter < 0)
    {
        answered = answerMan.getAnswered();
        answerMan.update(mousePos, clicked, pressed, mouseButton);
        questionMan.update();
        questionMan.setAnswered(answered);
        if (threeTimePause > 2)
        {
            delayCounter = 150;
            ofSetBackgroundAuto(false);
        }
        if (answered != 0)
        {
            threeTimePause ++;
            answerMan.setShowCorrect(true);
            if (setScoreAlready == false)
            {
                setScoreAlready = true;
                if (answered == 2)
                {
                    score ++;
                }
                posScore ++;
                setScoreString();
            }
        }

    }
    else
    {
        if (clicked == true and delayCounter > 3)
        {
            delayCounter = 3;
        }
        delayCounter --;
    }

};

void GameManager::draw()
{
    if (delayCounter < 0)
    {
        if (won == false)
        {
            GameBG.draw(ofVec2f(0,0), ofGetWindowWidth(), ofGetWindowHeight());
            GameFrame.draw(ofVec2f(0,0),  ofGetWindowWidth(), ofGetWindowHeight());
            answerMan.draw();
            questionMan.draw();
            ofSetColor(ofColor::black);
            defaultFont.drawString("Book: " + intToString(QASetTexts[setCounter].getDecade()), ofGetWindowWidth()*.025, ofGetWindowHeight()*.063);
            defaultFont.drawString(scorestr, ofGetWindowWidth()*.8, ofGetWindowHeight()*.063);
            ofSetColor(ofColor::white);
        }
        else
        {
            WinScreen.draw(ofVec2f(0,0), ofGetWindowWidth(), ofGetWindowHeight());
        }
    }
    else
    {
        if (delayCounter == 1 or delayCounter == 0)
        {
            setScoreAlready = false;
            ofSetBackgroundAuto(true);
            delayCounter = -5;
            threeTimePause = 0;
            if (won == false)
            {
                if (setCounter == QASetTexts.size() - 1)
                {
                    won = true;
                }
                else
                {
                   setCounter ++;
                }
                answerMan.resetAnswers();
                questionMan.resetQuestions();
                setAllText(setCounter);

            }
        }
        delayCounter --;
    }

}

void GameManager::getBookFromCode()
{
    int deci = QASetTexts[setCounter].getDecade();
    char

}

void GameManager::setScoreString()
{
    stringstream ca;
    stringstream cb;
    ca << score;
    cb << posScore;
    scorestr = "Score: " + ca.str() + "/" + cb.str();
}
