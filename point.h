#pragma once
#include "renderer.h"
#include "vec2.h"
#include "mouse.h"
#include "stick.h"

class Point{
    Stick* sticks[2] = { nullptr };

    vec2 pos, prevPos, initPos;
    bool isPinned = false;

    bool isSelected = false;

    void keepInsideView(int windowWidth, int windowHeight);

    public:
    Point() = default;
    Point(double x, double y);
    ~Point() = default;

    void addStick(Stick* s, int index);

    const vec2& getPosition() const { return pos; }
    void setPosition(double x, double y);

    void pin();

    void update(double deltaTime, double drag, vec2 gravity, double elasticity, Mouse* mouse, int windowWidth, int windowHeight);
};