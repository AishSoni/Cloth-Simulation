#include <iostream>
#include "stick.h"

void Stick::update(){
    if(!isActive) return;

    vec2 p0Pos = p0.getPosition();
    vec2 p1Pos = p1.getPosition();
    
    vec2 diff = p0Pos - p1Pos;
    double dist = sqrt((diff.x * diff.x) + (diff.y * diff.y));
    double diffFactor = (length - dist)/dist;
    vec2 offset = diff * diffFactor * 0.5f;

    //Tear by distance
    if(dist > 100) breakStick();
    
    p0.setPosition(p0Pos.x + offset.x, p0Pos.y + offset.y);
    p1.setPosition(p1Pos.x - offset.x, p1Pos.y - offset.y);
}

void Stick::draw(const Renderer* renderer){
    if(!isActive) return;

    vec2 p0Pos = p0.getPosition();
    vec2 p1Pos = p1.getPosition();

    renderer->drawLine(p0Pos.x, p0Pos.y, p1Pos.x, p1Pos.y, isSelected ? colorWhenSelected : color);
}

void Stick::breakStick(){
    isActive = false;
}