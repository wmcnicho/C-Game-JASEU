#include "thing.h"

Thing::Thing(double nx, double ny, double w, double h, int vx, int vy ){
    //QGraphicsPixmapItem(nx, ny, w, h) {
    QPixmap image = QPixmap("./images/playerShip.jpg");
    setPixmap(image);
    setPos(nx, ny);
    x = nx;
    y = ny;
    width = w;
    height = h;
    velocityX = vx;
    velocityY = vy;
}

int Thing::getVelocityX() {
    return velocityX;
}

int Thing::getVelocityY() {
    return velocityY;
}

void Thing::setVelocityX( int vx ) {
    velocityX = vx;
}

void Thing::setVelocityY( int vy ) {
    velocityY = vy;
}

void Thing::move( int windowMaxX, int windowMaxY ) {
    //We move by adding the velocity to the current position.
    //Then we test whether we have reached the edge of our moving space
    //If so, we reverse the velocity (y-velocity when we hit the top/bottom and
    //x-velocity when we hit the left/right sides) and undo the position change
    //that moved part of the rectangle off the screen.
    x += velocityX;
    y += velocityY;

    if ( x < 0 ) {
        velocityX = -velocityX;
        x +=velocityX;
    }

    if ( y < 0 ) {
        velocityY = -velocityY;
        y +=velocityY;
    }

    if ( (x+width) > windowMaxX ) {
         velocityX = -velocityX;
         x+=velocityX;
    }

    if ( (y+height) > windowMaxY ) {
         velocityY = -velocityY;
         y+=velocityY;
    }


    //Everything is good. Update the QRectF that is actually displayed.
    /*QPointF p( x, y );
    QRectF r( rect() );
    r.moveTo(p);
    setRect( r );*/

}


int Thing::getX() {
    return x;
}

int Thing::getY() {
    return y;
}

void Thing::setX(int nx) {
    x = nx;
}

void Thing::setY(int ny) {
    y = ny;
}

