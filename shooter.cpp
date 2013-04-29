#include "shooter.h"

Shooter::Shooter(QPixmap *pm, int nx, int ny): Thing(pm, nx, ny){
    good = false;
    if(x < 400){
    setVelocityX(-2);
    }
    else
    {
    setVelocityX(2);
    }
    points = 120;
}
int Shooter::getPoints() {
   return 120;
}

void Shooter::changePos() {
    if(x<=10){
      setVelocityX(2);
    }
    if(x>=SCENE_WINDOW_X-20){
      setVelocityX(-2);
    }
}

