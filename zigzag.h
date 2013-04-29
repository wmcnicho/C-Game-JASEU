#ifndef ZIGZAG_H
#define ZIGZAG_H

#include "thing.h"

class Zigzag : public Thing {
public:
    Zigzag(QPixmap* pm, int nx, int ny);
    void changePos();

private:

};

#endif
