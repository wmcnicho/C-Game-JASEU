#include "laser.h"

Laser::Laser(QPixmap* pm, int nx, int ny):Thing(pm,nx,ny){

}

void Laser::changePos(){
  setVelocityY(2);
}
    
