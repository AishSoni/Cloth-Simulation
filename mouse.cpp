#include <iostream>
#include "mouse.h"

const vec2& Mouse::getPosition() const { return pos; }
const vec2& Mouse::getPreviousPosition() const { return prevPos; }

bool Mouse::getLbState() const { return mouseLbDown; }
void Mouse::setLbState(bool state) { this->mouseLbDown = state; }

bool Mouse::getRbState() const { return mouseRbDown; }
void Mouse::setRbState(bool state) { this->mouseRbDown = state; }

double Mouse::getCursorSize() const { return cursorSize; }

void Mouse::increaseCursorSize(double increment){
    if(cursorSize + increment > maxCursorSize || cursorSize + increment < minCursorSize) 
        return;

    cursorSize += increment;
}

void Mouse::updatePosition(int x, int y){
    prevPos.x = pos.x;
    prevPos.y = pos.y;
    pos.x = x;
    pos.y = y;
}