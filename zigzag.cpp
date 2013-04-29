#include "zigzag.h"

Zigzag::Zigzag(QPixmap *pm, int nx, int ny): Thing(pm, nx, ny){
    good = false;
    setVelocityX(2);
    points = 100;
 }
 
int Zigzag::getPoints() {
  return 100;
}


void Zigzag::changePos() {
    if(x<=10){
      setVelocityX(2);
    }
    if(x>=SCENE_WINDOW_X-20){
      setVelocityX(-2);
    }
    setVelocityY(-1);
}

