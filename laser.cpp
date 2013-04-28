#include "laser.h"

Laser::Laser(QPixmap* pm, int nx, int ny):Thing(pm,nx,ny){
   good = true;
}

void Laser::changePos(){
  setVelocityY(2);
}
    
