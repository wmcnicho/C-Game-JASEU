#include "top.h"
#include <iostream>

Top::Top(QPixmap *pm, int nx, int ny): Thing(pm, nx, ny){
    good = false;
    radius = 50;
    originY = ny+radius;
    originX = nx;
    speed = 1.5;
}


void Top::changePos() {
    
    double relX = x-originX;
    double relY = (y-originY);
    double cos = relX/radius; 
    double sin = relY/radius;
    setVelocityY(speed*(cos));
    setVelocityX(speed*(sin));
    if((x>=SCENE_WINDOW_X-10) && (getVelocityX()>0))
       speed *= -1;
    if((x<0) && (getVelocityX()<0))
       speed *= -1;   
}

