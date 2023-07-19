#pragma once

#include "vec2.h"

class Mouse{
    vec2 pos, prevPos;

    double cursorSize = 20;
    double maxCursorSize = 100;
    double minCursorSize = 20;

    bool mouseLbDown = false;
    bool mouseRbDown = false;

    public:
    Mouse() = default;
    ~Mouse() = default;

    void updatePosition(int x, int y);
    const vec2& getPosition() const;
    const vec2& getPreviousPosition() const;

    bool getLbState() const;
    void setLbState(bool state);

    bool getRbState() const;
    void setRbState(bool state);

    void increaseCursorSize(double increment);
    double getCursorSize() const;
};