#ifndef LASER_H
#define LASER_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include "thing.h"

class Laser : public Thing {
public:
    Laser(QPixmap* pm, int nx, int ny);
    void changePos();
    
private:
};

#endif
