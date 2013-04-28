#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include "thing.h"
#include "laser.h"

class Player : public Thing {
public:
    Player(QPixmap* pm, int nx, int ny);
    void changePos(){}
    int getX();
    int getY();
  
private:
  };

#endif // Thing_H
