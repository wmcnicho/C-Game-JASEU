#include "top.h"
#include <iostream>

Top::Top(QPixmap *pm, int nx, int ny): Thing(pm, nx, ny){
    good = false;
    radius = 100;
    originY = y+radius;
    originX = x;
}


void Top::changePos() {
    
    double relX = x-originX;
    double relY = y-originY;
    double cos = relX/radius; 
    double sin = relY/radius;
    setVelocityY(3*(cos));
    setVelocityX(3*(sin));
}

