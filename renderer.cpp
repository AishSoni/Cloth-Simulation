#include <iostream>
#include "renderer.h"
 
bool Renderer::setup(){
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cerr<<"Error Initializing SDL..."<<std::endl;
        return false;
    }

    SDL_DisplayMode displayMode;
    SDL_GetCurrentDisplayMode(0, &displayMode);
    windowWidth = displayMode.w;
    windowHeight = displayMode.h;

    window = SDL_CreateWindow("Cloth Simulation C++", 0, 0, windowWidth, windowHeight,SDL_WINDOW_BORDERLESS);

    if(!window){
        std::cerr<<"Error Initializing SDL Window..."<<std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(!renderer){
        std::cerr<<"Error Initializing SDL Renderer..."<<std::endl;
        return false;
    }

    return true;
}

void Renderer::clearScreen(Uint32 color){
    SDL_SetRenderDrawColor(renderer, color>>16, color>>8, color, 255);
    SDL_RenderClear(renderer);
}

void Renderer::render() const{
    SDL_RenderPresent(renderer);
}

void Renderer::drawLine(int x0, int y0, int x1, int y1, Uint32 color) const{
    SDL_SetRenderDrawColor(renderer, color>>16, color>>8, color, 255);
    SDL_RenderDrawLine(renderer, x0, y0, x1, y1);
}

void Renderer::drawPoint(int x, int y, Uint32 color) const{
    SDL_SetRenderDrawColor(renderer, color>>16, color>>8, color, 255);
    SDL_RenderDrawPoint(renderer, x, y);
}

int Renderer::getWindowWidth() const{
    return windowWidth;
}

int Renderer::getWindowHeight() const{
    return windowHeight;
}

Renderer::~Renderer(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}