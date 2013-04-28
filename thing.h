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
    Thing(QPixmap* pm, int nx, int ny);
    int getX();
    int getY();
    int getVelocityX();
    int getVelocityY();
    void setVelocityX(int x);
    void setVelocityY(int y);
    void setX(int nx);
    void setY(int ny);
    virtual void changePos() = 0;
    //bool collidesWithItem(Thing* item);
    void updatePos();
    
protected:
    int x;
    int y;
    bool good;

private:
    int width;
    int height;
    QPixmap* pixMap;
    int velocityX;
    int velocityY;
};

#endif // Thing_H
