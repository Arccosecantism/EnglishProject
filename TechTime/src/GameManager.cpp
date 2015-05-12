#include "GameManager.h"

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
