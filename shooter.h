#ifndef SHOOTER_H
#define SHOOTER_H

#include "thing.h"

class Shooter : public Thing {
public:
    Shooter(QPixmap* pm, int nx, int ny);
    void changePos();
    int getPoints();

private:

};

#endif
