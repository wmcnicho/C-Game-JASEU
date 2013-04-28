#include "crusher.h"

Crusher::Crusher(QPixmap *pm, int nx, int ny): Thing(pm, nx, ny){
    good = false;
}


void Crusher::changePos() {
    setVelocityY(-1);
}

