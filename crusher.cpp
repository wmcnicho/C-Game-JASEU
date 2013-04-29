#include "crusher.h"

Crusher::Crusher(QPixmap *pm, int nx, int ny): Thing(pm, nx, ny){
    good = false;
    points = 50;
}
int Crusher::getPoints() {
    return 50;
}

void Crusher::changePos() {
    setVelocityY(-1);
}

