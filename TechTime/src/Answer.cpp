#include "Answer.h"

Answer::Answer(ofVec2f pos, std::string tex, ofTrueTypeFont& f, ofTexture& bg, bool cor)
{
    position = pos;
    text = tex;
    font = &f;
    backgro = &bg;
    resetCorners();
    colors.push_back(ofColor::black);
    colors.push_back(ofColor(0,0,205));
    colors.push_back(ofColor(16,52,166));
    colors.push_back(ofColor::red);
    colors.push_back(ofColor::green);
    correct = cor;
    colorPick = 0;
    selected = false;
}


void Answer::setPosition(ofVec2f p)
{
    position = p;
    resetCorners();
}

void Answer::setText(std::string tex)
{
    text = tex;
}



void Answer::setCorrect(bool b)
{
    correct = b;
}

int Answer::getAnswered()
{
    if (selected == true)
    {
        //std::cout << "here" << std::endl;
        if (correct == true)
        {

            return 2;
        }
        else
        {
           // std::cout << "incorrect" << std::endl;
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

int Answer::getClickedDataInt(ofVec2f& mousePos, bool& clicked, bool& pressed)
{
    if (mousePos.x < TLpos.x || mousePos.x > BRpos.x ||
        mousePos.y < TLpos.y || mousePos.y > BRpos.y)
    {
        return 0;
        // it's outside
    }
    else
    {
        if (clicked == true)
        {

            selected = true;
            return 3;
        }
        else if (pressed == true)
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
}

void Answer::resetCorners()
{
    TLpos = ofVec2f(position.x - backgro->getWidth()/2, position.y - backgro->getHeight()/2);
    BRpos = ofVec2f(position.x + backgro->getWidth()/2, position.y + backgro->getHeight()/2);

}

void Answer::reset()
{
    selected = false;
    correct = false;
    colorPick = 0;
}

void Answer::update(ofVec2f& mousepos, bool& clicked, bool& pressed)
{
    if (colorPick != 3 and colorPick != 4)
    {
        int state = getClickedDataInt(mousepos, clicked, pressed);
        colorPick = state;
        if (colorPick == 3 and correct == true)
        {
            colorPick = 4;
        }
    }
}

void Answer::draw()
{

    backgro->draw(TLpos);
    ofSetColor(colors[colorPick]);
    font->drawString(text, position.x - font->stringWidth(text)/2, position.y + font->stringHeight(text)/2);
    ofSetColor(ofColor::white);
}
