#include "Answer.h"

Answer::Answer(ofVec2f pos, std::string tex, ofTrueTypeFont& f)
{
    position = pos;
    text = tex;
    font = &f;
    resetCorners();
}


void Answer::setPosition(ofVec2f p)
{
    pos = p;
    resetCorners();
}

int Answer::getClickedDataInt(ofVec2f& mousepos, bool& clicked, bool& pressed)
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
    TLpos = pos;
    BRpos = ofVec2f(pos.x + font->stringWidth(text), pos.y + font->stringHeight(text));
}

void update()
{

}
