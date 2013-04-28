#include "player.h"
#include <iostream>
#include "jaseuwindow.h"


Player::Player(QPixmap *pm, int nx, int ny): Thing(pm, nx, ny) {
   good = true;
}
int Player::getX() {
    return x;
}
int Player::getY() {
    return y;
}
