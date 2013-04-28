#include "jaseuwindow.h"
#include <qapplication.h>

#define SCENE_WINDOW_Y 600
#define SCENE_WINDOW_X 790
#define PLAYER_SPAWN_Y SCENE_WINDOW_Y-75
#define PLAYER_SPAWN_X SCENE_WINDOW_X/2
#define PLAYER_SPAWN_Y SCENE_WINDOW_Y-75
#define PLAYER_SPAWN_X SCENE_WINDOW_X/2
#define ENEMY_SPAWN_1_X 75
#define ENEMY_SPAWN_1_Y 75
#define ENEMY_SPAWN_2_X SCENE_WINDOW_X-75
#define ENEMY_SPAWN_2_Y 150
#define ENEMY_SPAWN_M_X SCENE_WINDOW_X/2
#define ENEMY_SPAWN_M_Y 125

using namespace std;

   void JaseuWindow::initialize(){
   
   
    timeCounter = 0;
    spawnRate = 1;
   
   scene->setSceneRect(0,0,780,590);
   QBrush greenBrush(Qt::green);
   QBrush redBrush(Qt::red);
   QGraphicsRectItem* spawn1 = new QGraphicsRectItem(ENEMY_SPAWN_1_X, ENEMY_SPAWN_1_Y, 10, 10);
   spawn1->setBrush(redBrush);
   scene->addItem(spawn1);
   QGraphicsRectItem* spawn2 = new QGraphicsRectItem(ENEMY_SPAWN_1_X, ENEMY_SPAWN_2_Y, 10, 10);
   spawn2->setBrush(redBrush);
   scene->addItem(spawn2);
   QGraphicsRectItem* spawn3 = new QGraphicsRectItem(ENEMY_SPAWN_2_X, ENEMY_SPAWN_1_Y, 10, 10);
   spawn3->setBrush(redBrush);
   scene->addItem(spawn3);
   QGraphicsRectItem* spawn4 = new QGraphicsRectItem(ENEMY_SPAWN_2_X, ENEMY_SPAWN_2_Y, 10, 10);
   spawn4->setBrush(redBrush);
   scene->addItem(spawn4);
   QGraphicsRectItem* spawn5 = new QGraphicsRectItem(ENEMY_SPAWN_M_X, ENEMY_SPAWN_M_Y, 10, 10);
   spawn5->setBrush(redBrush);
   scene->addItem(spawn5);
   QGraphicsRectItem* pSpawn = new QGraphicsRectItem(PLAYER_SPAWN_X, PLAYER_SPAWN_Y, 10, 10);
   pSpawn->setBrush(greenBrush);
   scene->addItem(pSpawn);
   
   
   
   player = new Player(playerShip, PLAYER_SPAWN_X, PLAYER_SPAWN_Y);
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
   timeCounter++;
   
   
   player->updatePos();
   if(timeCounter*spawnRate%100 == 0){
   Thing* newEnemy = spawnEnemy();
   scene -> addItem(newEnemy);
   enemies.push_back(newEnemy);
   }
   for(unsigned int i=0; i<enemies.size(); i++){
       enemies[i]->changePos();
   }
   for(unsigned int i=0; i<enemies.size(); i++){
       enemies[i]->updatePos();
   }
   //player->setVelocityX(0);
   //player->setVelocityY(0);
   
   }
   void JaseuWindow::handlePause(){
   
    if(timer->isActive()){
    timer->stop();
    }
    else{
    timer->start();
    }
   }
   
Thing *JaseuWindow::spawnEnemy(){
int randX = rand()%3;
int randY = rand()%2;
int spawnX = 0;
int spawnY = 0;

if(randX==1){
spawnX = ENEMY_SPAWN_1_X;

}
else if(randX == 2){
spawnX = ENEMY_SPAWN_2_X;
}

if(randY==0){
spawnY = ENEMY_SPAWN_1_Y;
}
else if(randY==1){
spawnY = ENEMY_SPAWN_2_Y;
}

if(randX==0){
spawnX = ENEMY_SPAWN_M_X;
spawnY = ENEMY_SPAWN_M_Y;
}

Thing* enemy = new Crusher(crusherShip, spawnX, spawnY); 
return enemy;
}
   
   
   
JaseuWindow::JaseuWindow()  {
    srand(time(0));
    
    
    playerShip = new QPixmap("./images/playerShip.jpg");
    crusherShip = new QPixmap("./images/crusher.png");
    
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

JaseuWindow::~JaseuWindow()
{

}
