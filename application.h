#pragma once

#include <vector>
#include "mouse.h"
#include "renderer.h"
#include "cloth.h"

class application{
    Renderer* renderer = nullptr;
    Mouse* mouse = nullptr;
    Cloth* cloth = nullptr;

    bool isRunning = false;

    Uint32 lastUpdateTime;

    public:
    application() = default;
    ~application() = default;

    bool IsRunning() const;
    
    void setup(int clothWidth, int clothHeight, int clothSpacing);
    void input();
    void update();
    void render();
    void guiSetup();

    void reset();
    void destroy();
};