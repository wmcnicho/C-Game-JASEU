#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include "thing.h"
#include "laser.h"

class JaseuWindow;
/**
  This class maintains the location, size, and speed of a QGraphicsRectItem.
  It is easier to do the arithmetic with this data, and then update the position
  separately, then to extract coordinates from the QRectF that is contained within
  the QGraphicsRectItem
  */
class Player : public Thing {
public:
    Player(QPixmap* pm, int nx, int ny);
    void changePos(){}
    int getX();
    int getY();
    //Laser* shoot();

private:
   JaseuWindow* window_;
};

#endif // Thing_H
