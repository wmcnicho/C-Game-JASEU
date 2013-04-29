#ifndef THING_H
#define THING_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

#define SCENE_WINDOW_Y 600
#define SCENE_WINDOW_X 720
#define PLAYER_SPAWN_Y SCENE_WINDOW_Y-75
#define PLAYER_SPAWN_X SCENE_WINDOW_X/2
#define PLAYER_SPAWN_Y SCENE_WINDOW_Y-75
#define PLAYER_SPAWN_X SCENE_WINDOW_X/2
#define ENEMY_SPAWN_1_X 75
#define ENEMY_SPAWN_1_Y 75
#define ENEMY_SPAWN_2_X SCENE_WINDOW_X-74
#define ENEMY_SPAWN_2_Y 150
#define ENEMY_SPAWN_M_X (SCENE_WINDOW_X/2)-1
#define ENEMY_SPAWN_M_Y 125

class Thing : public QGraphicsPixmapItem {
public:
    Thing(QPixmap* pm, int nx, int ny);
    int getX();
    int getY();
    double getVelocityX();
    double getVelocityY();
    void setVelocityX(double x);
    void setVelocityY(double y);
    void setX(int nx);
    void setY(int ny);
    virtual void changePos() = 0;
    bool inPlay();
    void updatePos();
    
protected:
    int x;
    int y;
    bool good;

private:
    int width;
    int height;
    QPixmap* pixMap;
    double velocityX;
    double velocityY;
};

#endif // Thing_H
