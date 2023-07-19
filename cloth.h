#pragma once

#include <vector>
#include "point.h"
#include "stick.h"

class Cloth{
    vec2 gravity = { 0.0f, 981.0f };
    double drag = 0.01f;
    double elasticity = 10.0f;

    std::vector<class Point*> points;
    std::vector<class Stick*> sticks;

    public:
    Cloth() = default;
    Cloth(int width, int height, int spacing, int startX, int startY);
    ~Cloth();

    void update(Renderer* renderer, Mouse* mouse, double deltaTime);
    void draw(Renderer* renderer) const;
};