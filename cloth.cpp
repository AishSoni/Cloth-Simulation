#include <iostream>
#include "cloth.h"

Cloth::Cloth(int width, int height, int spacing, int startX, int startY){
    for(int y=0; y<=height; y++){
        for(int x=0; x<=width; x++){
            Point* point = new Point(startX + (x * spacing), startY + (y * spacing));

            if(x!=0){
                class Point* leftPoint = points[this->points.size() - 1];
                Stick* s = new Stick(*point, *leftPoint, spacing);
                leftPoint->addStick(s,0);
                point->addStick(s,0);
                sticks.emplace_back(s);
            }

            if(y!=0){
                class Point* upPoint = points[x + (y-1)*(width+1)];
                Stick* s = new Stick(*point, *upPoint, spacing);
                upPoint->addStick(s,1);
                point->addStick(s,1);
                sticks.emplace_back(s);
            }

            if(y==0 && x%2==0){
                point->pin();
            }

            points.emplace_back(point);
        }
    }
}

void Cloth::update(Renderer* renderer, Mouse* mouse, double deltaTime){
    for(int i=0; i<points.size(); i++)
        points[i]->update(deltaTime, drag, gravity, elasticity, mouse, renderer->getWindowWidth(), renderer->getWindowHeight());

    for(int i=0; i<sticks.size(); i++)
        sticks[i]->update();
}

void Cloth::draw(Renderer* renderer) const {
    for(int i=0; i<sticks.size(); i++)
        sticks[i]->draw(renderer);
}

Cloth::~Cloth(){
    for(auto point : points)
        delete point;
    for(auto stick : sticks)
        delete stick;
}