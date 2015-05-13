#include "Question.h"

Question::Question(ofVec2f pos, std::string qtex, ofTrueTypeFont& ffont, ofTexture& fbackgro, ofTexture& frightAns, ofTexture& fwrongAns)
{
    answered = 0;
    position = pos;
    text = qtex;
    font = &ffont;
    backgro = &fbackgro;
    rightAns = &frightAns;
    wrongAns = &fwrongAns;
    decade = 600;

    resetCorners();
}

void Question::setAnswered(int i)
{
    if (i == 0 or i == 1 or i == 2)
    {
        answered = i;
    }
}

void Question::setPosition(ofVec2f p)
{
    position = p;
    resetCorners();
}

void Question::resetCorners()
{
    TLpos = ofVec2f(position.x - backgro->getWidth()/2, position.y - backgro->getHeight()/2);
    BRpos = ofVec2f(position.x + backgro->getWidth()/2, position.y + backgro->getHeight()/2);
}

void Question::setText(std::string newtext)
{
    text = newtext;
}

void Question::setDecade(int dec)
{
    decade = dec;
}

void Question::reset()
{
    answered = 0;
}

void Question::update()
{

}

void Question::draw()
{
    backgro->draw(TLpos);
    ofSetColor(ofColor::black);
    font->drawString(text, position.x - font->stringWidth(text)/2, position.y - backgro->getHeight() * 3 / 8);
    ofSetColor(ofColor::white);
//    std::cout << answered << std::endl;
    if (answered == 1)
    {
        wrongAns->draw(TLpos);
    }
    else if (answered == 2)
    {
        rightAns->draw(TLpos);
    }

}
