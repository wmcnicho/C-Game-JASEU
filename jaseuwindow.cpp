#include "jaseuwindow.h"
#include <qapplication.h>


using namespace std;
JaseuWindow::JaseuWindow()  {
    
    setFixedSize(1000, 750);
    
    pause = new QPushButton("Pause");
    start = new QPushButton("Start");
    quit = new QPushButton("Quit");
    scoreLabel = new QLabel("Score: ");
    livesLabel = new QLabel("Lives: ");
    continuesLabel = new QLabel("Continues Used: ");
    
    /**A window that displays errors for debugging a user interaction*/
    debug = new QTextEdit();
    debug->setFixedSize(1000,50);
     
    score = new QLCDNumber();
    score->setSegmentStyle(QLCDNumber::Filled);
    lives = new QLCDNumber();
    lives->setSegmentStyle(QLCDNumber::Filled);
    continues = new QLCDNumber();
    continues->setSegmentStyle(QLCDNumber::Filled);
    
    QBrush greenBrush(Qt::green);
    QBrush blackBrush(Qt::black);
    QBrush whiteBrush(Qt::white);
    
    scene = new QGraphicsScene();
    view = new QGraphicsView( scene );
    view->setFixedSize( 790, 600);

    view->setBackgroundBrush(blackBrush);

    timer = new QTimer(this);
    timer->setInterval(5);
    //connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));

    
    //gameWindow = new Jaseu;
    
    layout = new QVBoxLayout;
    
    QHBoxLayout* topButtons = new QHBoxLayout;
    topButtons->addWidget(pause);
    topButtons->addWidget(start);
    
    QHBoxLayout* middleStuff = new QHBoxLayout;
    
    
    QVBoxLayout* sideInterface = new QVBoxLayout;
    
    QHBoxLayout* scoreLayout = new QHBoxLayout;
    scoreLayout->addWidget(scoreLabel);
    scoreLayout->addWidget(score);
    
    sideInterface->addLayout(scoreLayout);
    
    QHBoxLayout* livesLayout = new QHBoxLayout;
    livesLayout->addWidget(livesLabel);
    livesLayout->addWidget(lives);
    
    sideInterface->addLayout(livesLayout);
    
    QHBoxLayout* continueLayout = new QHBoxLayout;
    continueLayout->addWidget(continuesLabel);
    continueLayout->addWidget(continues);
    
    sideInterface->addLayout(continueLayout);
    sideInterface->addWidget(quit);
    
    middleStuff->addLayout(sideInterface);
    
    middleStuff->addWidget(view);
    
    layout->addLayout(topButtons);
    layout->addLayout(middleStuff);
    layout->addWidget(debug);
    
    setLayout(layout);

}


JaseuWindow::~JaseuWindow()
{

}

