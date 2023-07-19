#include <iostream>
#include <cmath>
#include "application.h"
#include "application.cpp"

int main(int argc, char* args[]){
    application app;
    app.setup(1500, 360, 10);

    while(app.IsRunning()){
        app.input();
        app.update();
        app.render();
    }

    app.destroy();
    return 0;
}