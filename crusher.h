#ifndef CRUSHER_H
#define CRUSHER_H

#include "thing.h"

class Crusher : public Thing {
public:
    Crusher(QPixmap* pm, int nx, int ny);
    void changePos();
    

private:

};

#endif // Thing_H
