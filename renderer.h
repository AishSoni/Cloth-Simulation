#pragma once

#include <SDL2/SDL.h>
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#include <SDL.h>
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <SDL_opengles2.h>
#else
#include <SDL_opengl.h>
#endif
#include <fstream>
#include <sstream>
#include <vector>
// This example can also compile and run with Emscripten! See 'Makefile.emscripten' for details.
#ifdef __EMSCRIPTEN__
#include "../libs/emscripten/emscripten_mainloop_stub.h"
#endif

class Renderer{
    int windowWidth, windowHeight;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_WindowFlags window_flags;
    SDL_GLContext gl_context;
    ImVec4 clear_color;

    GLuint shaderProgram;
    GLuint VBO, VAO;

    public:
    Renderer() = default;
    ~Renderer();

    int getWindowWidth() const;
    int getWindowHeight() const;
    
    bool setup();

    void clearScreen();
    void render() const;

    void drawLine(int x0, int y0, int x1, int y1, ImVec4 color) const;
    void drawPoint(int x, int y, ImVec4 color) const;
};