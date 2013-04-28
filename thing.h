#ifndef THING_H
#define THING_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

/**
  This class maintains the location, size, and speed of a QGraphicsRectItem.
  It is easier to do the arithmetic with this data, and then update the position
  separately, then to extract coordinates from the QRectF that is contained within
  the QGraphicsRectItem
  */
class Thing : public QGraphicsPixmapItem {
public:
    Thing(double nx, double ny, double w, double h, int vx, int vy );
    void setX( int x );
    void setY( int y );
    void setVelocityX( int vx );
    void setVelocityY( int vy );
    int getX();
    int getY();
    int getVelocityX();
    int getVelocityY();
    void move(int windowMaxX, int windowMaxY );

private:
    int x;
    int y;
    int width;
    int height;
    int velocityX;
    int velocityY;
};

#endif // Thing_H
