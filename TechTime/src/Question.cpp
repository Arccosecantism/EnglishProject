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
    decade = 0;
    windowMultiplier = ofVec2f(ofGetWindowWidth() / position.x, ofGetWindowHeight() / position.y);

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

    TLpos = ofVec2f(position.x - (dimensions.x/2) * ofGetWindowWidth() / 1600.0,
                    position.y - (dimensions.y/2) * ofGetWindowHeight() / 1200.0);
    BRpos = ofVec2f(position.x + (dimensions.x/2) * ofGetWindowWidth() / 1600.0,
                    position.y + (dimensions.y/2) * ofGetWindowHeight() / 1200.0);
}

void Question::setDimensions(ofVec2f dim)
{
    dimensions = dim;
}

ofVec2f Question::getDimensions()
{
    return dimensions;
}

ofVec2f Question::getTextDrawSpots()
{
    double x = position.x - font->stringWidth(text)/2;
    double y = position.y - font->stringHeight(text)/2 + font->stringHeight("W");
    ofVec2f returnme = ofVec2f(x,y);
    return returnme;
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
    position = ofVec2f(ofGetWindowWidth() / windowMultiplier.x, ofGetWindowHeight() / windowMultiplier.y);
    resetCorners();
}

void Question::draw()
{
    ofVec2f drawsize = ofVec2f(BRpos.x - TLpos.x, BRpos.y - TLpos.y);
    ofVec2f temp = getTextDrawSpots();
    backgro->draw(TLpos, drawsize.x, drawsize.y);
    ofSetColor(ofColor::black);
    font->drawString(text, temp.x, temp.y);
    ofSetColor(ofColor::white);
//    std::cout << answered << std::endl;
    if (answered == 1)
    {
        wrongAns->draw(TLpos, drawsize.x, drawsize.y);
    }
    else if (answered == 2)
    {
        rightAns->draw(TLpos, drawsize.x, drawsize.y);
    }

}
