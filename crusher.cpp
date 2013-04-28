#include "crusher.h"

Crusher::Crusher(QPixmap *pm, int nx, int ny): Thing(pm, nx, ny){
    
}


void Crusher::changePos() {
    setVelocityY(-1);
}
