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
}

void GameManager::fillQATexts(std::string filename)
{
    std::vector<std::string> questions;
    std::vector<std::string> answers;
    std::string line;
    bool QA = false;
   // bool newQuestion = false;
    std::ifstream QAtexts("../bin/data/QuestionAnswers.txt");
    
    if (QAtexts.is_open())
    {
        while(getline(QAtexts, line))
        {
            
            if (line = "-----")
            {
                //newQuestion = true;
            }
            else if (line[0] == 'Q' and line[1] == 'Q')
            {
                QA = false;
                
            }
        }
        }
        
        
        
    }
}

void GameManager::update(ofVec2f& mousePos, bool& clicked, bool& pressed)
{
    answerMan.update(mousePos, clicked, pressed);
    questionMan.update();
};

void GameManager::draw()
{
    GameBG.draw(ofVec2f(0,0));
    answerMan.draw();
    questionMan.draw();
}
