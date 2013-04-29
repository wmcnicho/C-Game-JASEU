#include "player.h"
#include <iostream>
#include "jaseuwindow.h"


Player::Player(QPixmap *pm, int nx, int ny): Thing(pm, nx, ny) {
   good = true;
}
void Player::changePos(){
   if( (x>SCENE_WINDOW_X-30) && (getVelocityX()>0) )
       setVelocityX(0);
   if( (x<10) && (getVelocityX()<0) )
       setVelocityX(0);
   if( (y>SCENE_WINDOW_Y-20) && (getVelocityY()<0) )
       setVelocityY(0);
   if( (y<20) && (getVelocityY()>0) )
       setVelocityY(0);
       
}

int Player::getX() {
    return x;
}
int Player::getY() {
    return y;
}
