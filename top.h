#ifndef TOP_H
#define TOP_H

#include "thing.h"

class Top : public Thing {
public:
    Top(QPixmap* pm, int nx, int ny);
    void changePos();

private:
   int originX;
   int originY;
   double radius;
};

#endif
