#ifndef SONOFA_H
#define SONOFA_H

#include "thing.h"
#include <cmath>

class SonOfA : public Thing {
public:
    SonOfA(QPixmap* pm, int nx, int ny);
    void changePos();
    int getPoints();

private:
   int counter;

};

#endif
