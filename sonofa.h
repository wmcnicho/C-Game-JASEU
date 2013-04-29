#ifndef SONOFA_H
#define SONOFA_H

#include "thing.h"
#include <cmath>

class SonOfA : public Thing {
public:
    SonOfA(QPixmap* pm, int nx, int ny);
    void changePos();

private:
   int counter;

};

#endif
