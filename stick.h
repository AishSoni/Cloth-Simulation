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

    unsigned long color = 0xFF000000;
    unsigned long colorWhenSelected = 0xFF39FF14;

    public:
    Stick(Point& p0, Point& p1, double length) : p0(p0), p1(p1), length(length) {}
    ~Stick() = default;
    void setIsSelected(bool val) { isSelected = val; };
    const double getLength() const { return length; }
    void update();
    void draw(const Renderer* renderer);
    void breakStick();
};