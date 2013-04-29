#include "thing.h"
#include <iostream>

Thing::Thing(QPixmap* pm, int nx, int ny){
    setPixmap(*pm);
    x = nx;
    y = ny;
    velocityX = 0.0;
    velocityY = 0.0;
    setPos(x, y);
}

    bool Thing::inPlay(){
    if((y>SCENE_WINDOW_Y)||(y<-2)){
    return false;
    }
    return true;
    }


void Thing::updatePos() {
   y -= getVelocityY();
   x += getVelocityX();
   setPos(x, y);
}

double Thing::getVelocityX() {
    return velocityX;
}

double Thing::getVelocityY() {
    return velocityY;
}

void Thing::setVelocityX( double vx ) {
    velocityX = vx;
}

void Thing::setVelocityY( double vy ) {
    velocityY = vy;
}

int Thing::getX() {
    return x;
}

int Thing::getY() {
    return y;
}

void Thing::setX(int nx) {
    x = nx;
}

void Thing::setY(int ny) {
    y = ny;
}

