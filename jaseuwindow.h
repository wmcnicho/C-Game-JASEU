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
#include "jaseuwidget.h"


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
    //void show();
    
    /**Takes in a given tile number based off of the tile clicked and updates it in the model and the view,
    *starts the timer for the animation, and checks the winning condition.
    *This function is called when a tile is clicked on.
    @param value The number of the tile to be moved
    */
    //void moveTiles(int value);

private:
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



public slots:


};

#endif

