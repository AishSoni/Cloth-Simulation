#pragma once
#include "renderer.h"
#include "point.h"
#include <cmath>

class Point;

class Stick{
    Point &p0, &p1;
    double length;

    bool isActive = true;
    bool isSelected = false;

    ImVec4 color;
    ImVec4 colorWhenSelected;

    public:
    
    Stick(Point& p0, Point& p1, double length) :
        p0(p0),
        p1(p1),
        length(length), 
        color(ImVec4(1.0f, 1.0f, 1.0f, 1.0f)),
        colorWhenSelected(ImVec4(1.0f, 0.5f, 0.5f, 1.0f)) {}
    ~Stick() = default;

    void setIsSelected(bool val) { isSelected = val; };
    const double getLength() const { return length; }
    void update();
    void draw(const Renderer* renderer);
    void breakStick();
};