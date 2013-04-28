#ifndef JWINDOW_H
#define JWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QStandardItemModel>
#include <QAbstractItemModel>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QString>
#include <QTimeLine>
#include <cmath>
#include <iostream>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <vector>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLabel>
#include <QRadioButton>
#include <QListView>
#include <QLCDNumber>
#include <QGridLayout>
#include "thing.h"
#include "player.h"
#include "crusher.h"
#include <QKeyEvent>
#include "gamemodel.h"
#include "laser.h"

class JaseuWindow : public QWidget {
    Q_OBJECT

public:
    /**Default constructor that generates and formats the window layout
    *
    */
    explicit JaseuWindow();
    /**Destructor
    *Note: Currently not implemented because it is not a requirement
    */
    ~JaseuWindow();
    
    
    Thing* spawnEnemy();
    
    void updateNums();
    
    void handleCollisions();
    
    void setToDefaultPositions();
    
     
    QPixmap* laserImage;
      
protected:
     void keyPressEvent(QKeyEvent* e);
     void keyReleaseEvent( QKeyEvent *e );

private:
    Game model;
    
    int timeCounter;
    int spawnRate;

    //pixMap images
    QPixmap* playerShip; 
    QPixmap* crusherShip;
    
/**The data member that stores the created widgets */
    QGraphicsScene *scene;
    /**A view containing the widgets stored in scence */
    QGraphicsView *view;

    /**A timer object used in animation */
    QTimer *timer;




    QPushButton* pause;
    QPushButton* start;
    QPushButton* quit;
    QLabel* scoreLabel;
    QLabel* livesLabel;
    QLabel* continuesLabel;
    
    /**A window that displays errors for debugging a user interaction*/
    QTextEdit *debug;
    
    QLCDNumber* score;
    QLCDNumber* lives;
    QLCDNumber* continues;
    
    //Jaseu* gameWindow;
    
    QVBoxLayout* layout;
    
    
    Player* player;
    
    std::vector<Thing*> enemies;
    std::vector<Thing*> goodies;

public slots:
   void initialize();
   void handleTimer();
   void handlePause();

};

#endif

