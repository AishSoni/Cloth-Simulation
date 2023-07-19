#pragma once

#include <SDL2/SDL.h>

class Renderer{
    int windowWidth, windowHeight;
    SDL_Window* window;
    SDL_Renderer* renderer;

    public:
    Renderer() = default;
    ~Renderer();

    int getWindowWidth() const;
    int getWindowHeight() const;
    
    bool setup();

    void clearScreen(Uint32 color);
    void render() const;

    void drawLine(int x0, int y0, int x1, int y1, Uint32 color) const;
    void drawPoint(int x, int y, Uint32 color) const;
};