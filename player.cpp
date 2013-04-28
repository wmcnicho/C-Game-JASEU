#include "player.h"
#include <iostream>

Player::Player(QPixmap *pm, int nx, int ny): Thing(pm, nx, ny){
    
}


void Player::updatePos() {
    //setX(x + getVelocityX());
    //setY(y + getVelocityY());
    y -= getVelocityY();
    x += getVelocityX();
    //std::cout << "Velocity Y" << getVelocityY() << std::endl;
    setPos(x, y);

}


