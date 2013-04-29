#ifndef TOP_H
#define TOP_H

#include "thing.h"

class Top : public Thing {
public:
    Top(QPixmap* pm, int nx, int ny);
    void changePos();

private:
   double originX;
   double originY;
   double radius;
   double speed;
};

#endif
