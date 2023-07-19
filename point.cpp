#include <iostream>
#include "point.h"

Point::Point(double x, double y) { pos = prevPos = initPos = vec2(x,y); }

void Point::addStick(Stick* s, int index) { sticks[index] = s; }

void Point::setPosition(double x, double y){
    pos.x = x;
    pos.y = y;
}

void Point::pin() { isPinned = true; }

void Point::keepInsideView(int windowWidth, int windowHeight){
    if(pos.x > windowWidth){
        pos.x = windowWidth;
        prevPos.x = pos.x;
    }
    else if(pos.x < 0){
        pos.x = 0;
        prevPos.x = pos.x;
    }
    if(pos.y > windowHeight){
        pos.y = windowHeight;
        prevPos.y = pos.y;
    }
    else if(pos.y < 0){
        pos.y = 0;
        prevPos.y = pos.y;
    }
}

void Point::update(double deltaTime, double drag, vec2 gravity, double elasticity, Mouse* mouse, int windowWidth, int windowHeight){
    vec2 mouseDir = pos - mouse->getPosition();
    double mouseDist = sqrt((mouseDir.x * mouseDir.x) + (mouseDir.y * mouseDir.y));
    isSelected = mouseDist < mouse->getCursorSize();

    for(Stick* s : sticks){
        if(s != nullptr)
            s->setIsSelected(isSelected);
    }

    if(mouse->getLbState() && isSelected){
        vec2 diff = mouse->getPosition() - mouse->getPreviousPosition();
        if (diff.x > elasticity) diff.x = elasticity;
        if (diff.y > elasticity) diff.y = elasticity;
        if (diff.x < -elasticity) diff.x = -elasticity;
        if (diff.y < -elasticity) diff.y = -elasticity;
        prevPos = pos - diff;
    }
    
    if(mouse->getRbState() && isSelected){
        for(Stick* s : sticks){
            if(s != nullptr)
                s->breakStick();
        }
    }

    if(isPinned){
        pos = initPos;
        return;
    }

    vec2 newPos = pos + (pos - prevPos)*(1.0f - drag) + gravity*(1.0f - drag)*deltaTime*deltaTime;
    prevPos = pos;
    pos = newPos;

    keepInsideView(windowWidth, windowHeight);
}