#include "Answer.h"

Answer::Answer(ofVec2f pos, std::string tex, ofTrueTypeFont& f, ofTexture& bg, ofTexture& stbg, ofTexture& sts, bool cor)
{
    position = pos;
    text = tex;
    font = &f;
    backgro = &bg;
    strikeThroughBG = &stbg;
    strikeThroughS = &sts;
    windowMultiplier = ofVec2f(ofGetWindowWidth() / position.x, ofGetWindowHeight() / position.y);

    resetCorners();
    colors.push_back(ofColor::black);
    colors.push_back(ofColor(0,0,205));
    colors.push_back(ofColor(16,52,166));
    colors.push_back(ofColor::red);
    colors.push_back(ofColor(0, 165, 80));
    correct = cor;
    colorPick = 0;
    selected = false;
    showCorrect = false;
    strikeThrough = false;

}


void Answer::setPosition(ofVec2f p)
{
    position = p;
    windowMultiplier = ofVec2f(ofGetWindowWidth() / position.x, ofGetWindowHeight() / position.y);
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

 void Answer::setShowCorrect(bool b)
 {
     showCorrect = b;
 }

ofVec2f Answer::getTextDrawSpots()
{
    double x = position.x - font->stringWidth(text)/2;
    double y = position.y - font->stringHeight(text)/2 + font->stringHeight("W");
    ofVec2f returnme = ofVec2f(x,y);
    return returnme;
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

int Answer::getClickedDataInt(ofVec2f& mousePos, bool& clicked, bool& pressed, int& mouseButton)
{
    int returnme = 0;
    if (mousePos.x < TLpos.x || mousePos.x > BRpos.x ||
        mousePos.y < TLpos.y || mousePos.y > BRpos.y)
    {
        returnme = 0;
    }
    else
    {

        if (mouseButton == 3 and clicked == true)
        {
            strikeThrough = !strikeThrough;
            returnme = 0;
        }
        else if (mouseButton == 1 and strikeThrough == false)
        {
            if (clicked == true)
            {
                selected = true;
                returnme = 3;
            }
            else if (pressed == true)
            {
                returnme = 2;
            }
        }
        else
        {
            returnme = 1;
        }
    }
    return returnme;
}

void Answer::resetCorners()
{

    TLpos = ofVec2f(position.x - (dimensions.x/2),
                    position.y - (dimensions.y/2));
    BRpos = ofVec2f(position.x + (dimensions.x/2),
                    position.y + (dimensions.y/2));
}

void Answer::setDimensions(ofVec2f dim)
{
    dimensions = dim;
}

ofVec2f Answer::getDimensions()
{
    return dimensions;
}

bool Answer::getCorrect()
{
    return correct;
}

void Answer::reset()
{
    selected = false;
    correct = false;
    showCorrect = false;
    strikeThrough = false;
    colorPick = 0;
}

void Answer::update(ofVec2f& mousepos, bool& clicked, bool& pressed, int& mouseButton)
{
    position = ofVec2f(ofGetWindowWidth() / windowMultiplier.x, ofGetWindowHeight() / windowMultiplier.y);
    resetCorners();
    if (showCorrect == true)
    {
        colorPick = 4;
        strikeThrough = false;
    }
    else if (colorPick != 3 and colorPick != 4)
    {
        int state = getClickedDataInt(mousepos, clicked, pressed, mouseButton);
        if (strikeThrough == true)
        {
            colorPick = 0;
        }
        else
        {
            colorPick = state;
            if (colorPick == 3 and correct == true)
            {
                colorPick = 4;
            }
        }
    }
}

void Answer::draw()
{
    ofVec2f drawsize = ofVec2f(BRpos.x - TLpos.x, BRpos.y - TLpos.y);
    ofVec2f temp = getTextDrawSpots();
    if (strikeThrough == true)
    {
        strikeThroughBG->draw(TLpos, drawsize.x, drawsize.y);
        ofSetColor(colors[colorPick]);
        font->drawString(text, temp.x, temp.y);
        ofSetColor(ofColor::white);
        strikeThroughS->draw(TLpos, drawsize.x, drawsize.y);
    }
    else
    {
        backgro->draw(TLpos, drawsize.x, drawsize.y);
        ofSetColor(colors[colorPick]);
        font->drawString(text, temp.x, temp.y);
        ofSetColor(ofColor::white);
    }

}
