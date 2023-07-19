#include <iostream>
#include "application.h"
#include "cloth.cpp"
#include "mouse.cpp"
#include "point.cpp"
#include "renderer.cpp"
#include "stick.cpp"

void application::setup(int clothWidth, int clothHeight, int clothSpacing){
    renderer = new Renderer();
    mouse = new Mouse();

    isRunning = renderer->setup();

    int startX = (renderer->getWindowWidth() - clothWidth) / 2;
    int startY = (renderer->getWindowHeight() - clothHeight) / 2; 

    clothHeight/= clothSpacing;
    clothWidth/= clothSpacing;

    cloth = new Cloth(clothWidth, clothHeight, clothSpacing, startX, startY);

    lastUpdateTime = SDL_GetTicks();
}

void application::update(){
    unsigned long currentTime = SDL_GetTicks();
    double deltaTime = (currentTime - lastUpdateTime)/ 1000.0f;

    cloth->update(renderer, mouse, deltaTime);

    lastUpdateTime = currentTime;
}

void application::input() {
  SDL_Event event;
  int x,y;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        isRunning = false;
        break;
      case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_ESCAPE)
          isRunning = false;
        else if(event.key.keysym.sym == SDLK_r)
            reset();
        break;
      case SDL_MOUSEMOTION:
        x = event.motion.x;
        y = event.motion.y;
        mouse->updatePosition(x, y);
        break;
      case SDL_MOUSEBUTTONDOWN:
        SDL_GetMouseState(&x, &y);
        mouse->updatePosition(x, y);

        if (!mouse->getLbState() && event.button.button == SDL_BUTTON_LEFT) {
          mouse->setLbState(true);
        }
        if (!mouse->getRbState() && event.button.button == SDL_BUTTON_RIGHT) {
          mouse->setRbState(true);
        }
        break;
      case SDL_MOUSEBUTTONUP: 
        if (mouse->getLbState() && event.button.button == SDL_BUTTON_LEFT) {
          mouse->setLbState(false);
        }
        if (mouse->getRbState() && event.button.button == SDL_BUTTON_RIGHT) {
          mouse->setRbState(false);
        }
        break;
      case SDL_MOUSEWHEEL:
        if (event.wheel.y > 0) {
          mouse->increaseCursorSize(10);
        } else if (event.wheel.y < 0) {
          mouse->increaseCursorSize(-10);
        }
        break;
    }
  }
}

bool application::IsRunning() const{
  return isRunning;
}

void application::render() const {
  renderer->clearScreen(0xFFFFFF);
  cloth->draw(renderer);
  renderer->render();
}

void application::destroy(){
  delete renderer;
  delete mouse;
  delete cloth;
}

void application::reset(){
    delete cloth;
    setup(1500, 360, 10);
}