#include "player.h"
#include <iostream>
#include "jaseuwindow.h"


Player::Player(QPixmap *pm, int nx, int ny): Thing(pm, nx, ny){
    
}
int Player::getX(){
return x;
}
    int Player::getY(){
return y;
}
/*Laser* Player::shoot(){
 //Laser* shot = new Laser(window_->laserImage, x, y);
 

}*/
