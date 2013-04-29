#include "sonofa.h"

SonOfA::SonOfA(QPixmap *pm, int nx, int ny): Thing(pm, nx, ny){
    good = false;
    counter = 0;
}


void SonOfA::changePos() {
    counter++;
    if(counter%10 == 0){
    int randX = rand();
    int randY = rand();
    int randS = rand()%5 +2;
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
    if((x>=SCENE_WINDOW_X-10) && (getVelocityX()>0))
       setVelocityX(getVelocityX()*-1);
    if((x<5) && (getVelocityX()<0))
       setVelocityX(getVelocityX()*-1);
     if((y<15) && (getVelocityY()>0))
       setVelocityY(getVelocityY()*-1);
    
}

