#include "sonofa.h"

SonOfA::SonOfA(QPixmap *pm, int nx, int ny): Thing(pm, nx, ny){
    good = false;
    counter = 0;
}


void SonOfA::changePos() {
    counter++;
    if(counter%15 == 0){
    int randX = rand();
    int randY = rand();
    int randS = rand()%5 +5;
    if(randX%2 == 0){
    setVelocityX(randS);
    }
    
    else{
    setVelocityX(randS *-1);
    }
    
    if(randY%2 == 0){
    setVelocityY(randS);
    }
    
    else{
    setVelocityY(randS *-1);
    
    }
    }
}

