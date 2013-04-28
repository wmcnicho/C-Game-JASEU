#include "jaseuwindow.h"
#include <qapplication.h>

#define SCENE_WINDOW_Y 600
#define SCENE_WINDOW_X 790
#define PLAYER_SPAWN_Y SCENE_WINDOW_Y-75
#define PLAYER_SPAWN_X SCENE_WINDOW_X/2

using namespace std;
JaseuWindow::JaseuWindow()  {

    //start: layout stuff    
    setFixedSize(1000, 750);

    pause = new QPushButton("Pause");
    start = new QPushButton("Start");
    quit = new QPushButton("Quit");
    scoreLabel = new QLabel("Score: ");
    livesLabel = new QLabel("Lives: ");
    continuesLabel = new QLabel("Continues Used: ");
    
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
    timer->setInterval(10);
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
    
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
    //End: Layout stuff
    
    //start button connections
    connect(start, SIGNAL(clicked()), this, SLOT(initialize()));
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(pause, SIGNAL(clicked()), this, SLOT(handlePause()));

    
    setFocusPolicy(Qt::StrongFocus);
}
   void JaseuWindow::initialize(){
   scene->setSceneRect(0,0,780,590);
   QBrush greenBrush(Qt::green);
   QBrush redBrush(Qt::red);
   QPixmap* image = new QPixmap("./images/playerShip.jpg");
   player = new Player(image, PLAYER_SPAWN_X, PLAYER_SPAWN_Y);
   scene->addItem(player);
   timer->start();
   //Thing* bob2 = new Thing(150,150,10,10,0,0);
   //bob2->setBrush(redBrush);
   //scene->addItem(bob2);
   }
   void JaseuWindow::keyPressEvent( QKeyEvent *e ) {
   
          if( e->key() == Qt::Key_W){
            if(player)
            player->setVelocityY(1);
            
            }
            if( e->key() == Qt::Key_S){
            if(player)
            player->setVelocityY(-1);
            }
            if( e->key() == Qt::Key_A){
            if(player)
            player->setVelocityX(-1);
            }
            if( e->key() == Qt::Key_D){
            if(player)
            player->setVelocityX(1);
            }
          

} 
   void JaseuWindow::keyReleaseEvent( QKeyEvent *e ) {
    if((e->key()==Qt::Key_A) || (e->key()==Qt::Key_D)){
     player->setVelocityX(0);
     }
    if((e->key()==Qt::Key_W)||(e->key()==Qt::Key_S)){
      player->setVelocityY(0);
    }
   }

   void JaseuWindow::handleTimer(){
   //cout << "timer is going" << endl;
   player->updatePos();
   //player->setVelocityX(0);
   //player->setVelocityY(0);
   
   }
   void JaseuWindow::handlePause(){
   
   }

JaseuWindow::~JaseuWindow()
{

}

