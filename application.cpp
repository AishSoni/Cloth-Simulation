#include <iostream>
#include "application.h"
#include "mouse.h"
#include "point.h"
#include "renderer.h"
#include "cloth.h"

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

void application::render() {
  // Start the Dear ImGui frame
  //ImGui_ImplOpenGL3_NewFrame();
  //ImGui_ImplSDL2_NewFrame();
  //ImGui::NewFrame();

  renderer->clearScreen();
  cloth->draw(renderer);
  //guiSetup();
  renderer->render();
}

void application::guiSetup(){
  // Edit a color stored as 4 floats
  //float* my_color;
  //ImGui::ColorEdit4("Color", my_color);

  // Generate samples and plot them
  float samples[100];
  for (int n = 0; n < 100; n++)
      samples[n] = sinf(n * 0.2f + 0 * 1.5f);
  //ImGui::PlotLines("Samples", samples, 100);

  // Display contents in a scrolling region
  //ImGui::TextColored(ImVec4(1,1,0,1), "Important Stuff");
  //ImGui::BeginChild("Scrolling");
  //for (int n = 0; n < 50; n++)
      //ImGui::Text("%04d: Some text", n);
  //ImGui::EndChild();
}

void application::destroy(){
  delete renderer;
  delete mouse;
  delete cloth;
}

void application::reset(){
    delete cloth;
    setup(1800, 400, 15);
}