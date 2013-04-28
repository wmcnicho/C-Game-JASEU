#include "thing.h"
#include <iostream>

Thing::Thing(QPixmap* pm, int nx, int ny){
    setPixmap(*pm);
    x = nx;
    y = ny;
    velocityX = 0;
    velocityY = 0;
    setPos(x, y);
}
/*bool Thing::collidesWithItem(Thing* item){
    int x2 = item->getX();
    int y2 = item->getY();
    if(item->good == good){
    return false;
    }
    else
    {
    if( (x==x2) && (y == y2) ){
    std::cout<< "COLLIDE" << std::endl;
    return true;
    }
    }
    return false;
}*/

void Thing::updatePos() {
   y -= getVelocityY();
   x += getVelocityX();
   setPos(x, y);
}

int Thing::getVelocityX() {
    return velocityX;
}

int Thing::getVelocityY() {
    return velocityY;
}

void Thing::setVelocityX( int vx ) {
    velocityX = vx;
}

void Thing::setVelocityY( int vy ) {
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

