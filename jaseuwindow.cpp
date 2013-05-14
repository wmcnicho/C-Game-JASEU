#include "jaseuwindow.h"
#include <qapplication.h>


using namespace std;

#define FILE_NAME "scores.txt"

void JaseuWindow::handleTimer() {
    QBrush greenBrush(Qt::green);
    QBrush blackBrush(Qt::black);
    QBrush whiteBrush(Qt::white);
    //cout << "timer is going" << endl;
    if(model.getScore() > 2000){
    	if(model.getScore() > 10000){
    	view->setBackgroundBrush(greenBrush);
    	spawnRateRate = .35;
    	}
    	else{
    	view->setBackgroundBrush(whiteBrush);
    	spawnRateRate = .25;
    	}
    }
    
    if(model.getLives()<0)
    {
    writeHighScores(FILE_NAME);
    updateScoreboard();
    timer->stop();
    return;
    }
    timeCounter++;
    increaseSpeed++;
    if(increaseSpeed%10000==0)
     {
     speed--;
     if(speed<1){
        speed =1;
     }
     timer->setInterval(speed);
     }
    if(timeCounter%100 == 0) {
        model.updateScore(10);
    }
    int temp = static_cast<unsigned int>(timeCounter*spawnRate);
    if(temp >= 500) {
        Thing* newEnemy = spawnEnemy();
        scene -> addItem(newEnemy);
        enemies.push_back(newEnemy);
        spawnRate+= spawnRateRate;
        timeCounter = 0;
    }
    handleCollisions();
    for(unsigned int i=0; i<goodies.size(); i++) {
        goodies[i]->changePos();
        goodies[i]->updatePos();
    }
    for(unsigned int i=0; i<enemies.size(); i++) {
        enemies[i]->changePos();
        enemies[i]->updatePos();
    }
    for(unsigned int i=0; i < enemies.size()+goodies.size(); i++) {
        if( (i>enemies.size())&&(i>goodies.size()) ) {
            break;
        }
        if(i<enemies.size() )
        {
            if(!enemies[i]->inPlay()) {
                scene->removeItem(enemies[i]);
                enemies.erase(enemies.begin() + i);
                 }
        }
        if(i<goodies.size())
        {
            if(!goodies[i]->inPlay()) {
                scene->removeItem(goodies[i]);
                goodies.erase(goodies.begin() + i);
                }
        }
    }

    updateNums();
}

void JaseuWindow::handleCollisions() {
    for(unsigned int i=0; i<goodies.size(); i++) {
        for(unsigned int j=0; j<enemies.size(); j++) {
            if( (goodies[i]->collidesWithItem(enemies[j])) ||  (goodies[i]->collidesWithItem(enemies[j])) )
            {
                if(goodies[i] == player) {
                    model.removeLife();
                    scene->clear();
                    enemies.clear();
                    goodies.clear();
                    setToDefaultPositions();
                    return;
                }
                scene->removeItem(goodies[i]);
                scene->removeItem(enemies[j]);
                goodies.erase(goodies.begin() + i);
                enemies.erase(enemies.begin() + j);
                model.updateScore(enemies[j]->getPoints());
                continue;
            }
        }
    }


}

void JaseuWindow::handlePause() {
    if(model.start() == false) {
        return;

    }
    if(timer->isActive()) {
        timer->stop();
    }
    else if(!timer->isActive()) {
        timer->start();
    }
}

Thing* JaseuWindow::spawnEnemy() {
    
    int adjust = static_cast<int>(spawnRate + 0.5);
    if(adjust>9)
    	adjust = 10;
    int type = rand()%adjust;
    int randX = rand()%3;
    int randY = rand()%2;
    int spawnX = 0;
    int spawnY = 0;
    
    if(randX==1) {
        spawnX = ENEMY_SPAWN_1_X;

    }
    else if(randX == 2) {
        spawnX = ENEMY_SPAWN_2_X;
    }

    if(randY==0) {
        spawnY = ENEMY_SPAWN_1_Y;
    }
    else if(randY==1) {
        spawnY = ENEMY_SPAWN_2_Y;
    }

    if(randX==0) {
        spawnX = ENEMY_SPAWN_M_X;
        spawnY = ENEMY_SPAWN_M_Y;
    }
    Thing* enemy;
    if((type>=0)&&(type<3)) {
        enemy = new Crusher(crusherShip, spawnX, spawnY);
    }
    if((type>=3)&&(type<5)) {
        enemy = new Zigzag(zShip, spawnX, spawnY);
    }
    if(((type>=5)&&(type<7))) {
        enemy = new Shooter(shootShip, spawnX, spawnY);
    }
    if((type>=7)&&(type<9)) {
        enemy = new Top(topShip, spawnX, spawnY);
    }
    if(type>=9) {
        enemy = new SonOfA(trollShip, spawnX, spawnY);
    }

    return enemy;
}

void JaseuWindow::setToDefaultPositions() {
    QBrush greenBrush(Qt::green);
    QBrush redBrush(Qt::red);
    QBrush blueBrush(Qt::blue);

    //spawners
    /*QGraphicsRectItem* spawn1 = new QGraphicsRectItem(ENEMY_SPAWN_1_X, ENEMY_SPAWN_1_Y, 10, 10);
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
    */

    //walls
    /*QGraphicsRectItem* leftWall = new QGraphicsRectItem(0, 0, 5, SCENE_WINDOW_Y);
    leftWall->setBrush(blueBrush);
    scene->addItem(leftWall);
    QGraphicsRectItem* rightWall = new QGraphicsRectItem(SCENE_WINDOW_X-5, 0, 5, SCENE_WINDOW_Y);
    rightWall->setBrush(blueBrush);
    scene->addItem(rightWall);
    QGraphicsRectItem* topWall = new QGraphicsRectItem(0, 0, SCENE_WINDOW_X, 5);
    topWall->setBrush(blueBrush);
    scene->addItem(topWall);
    QGraphicsRectItem* botWall = new QGraphicsRectItem(0, SCENE_WINDOW_Y-5, SCENE_WINDOW_X, 5);
    botWall->setBrush(blueBrush);
    scene->addItem(botWall);
    */

    player = new Player(playerShip, PLAYER_SPAWN_X, PLAYER_SPAWN_Y);
    scene->addItem(player);
    goodies.push_back(player);
}

    
    bool JaseuWindow::readHighScores(const char* fn){
    ifstream input;
    input.open(fn);
    if(!input.good()){
    	cout << "no valid input file" << endl;
    	return false;
    }
    for(int i=0; i<5; i++){
    getline(input, topScoreNames[i]);
    //cout << "read name " << i << " as " << topScoreNames[i] << endl;
    input >> intTopScores[i];
    input.ignore(256, '\n');
    //cout << "read score " << i << " as " << intTopScores[i] << endl;
    }
    return true;
    
    }
    bool JaseuWindow::writeHighScores(const char* fn){
    ofstream output;
    output.open(fn);
    if(!output.good()) {//checks to see if filename is valid
        cout << "Bad file name" << endl;
        return false;
    }
    for(int i=0; i<5; i++){
    output << topScoreNames[i] << endl;
    output << intTopScores[i] << endl;
    }
    return true;
    
    }

void JaseuWindow::initialize() {
    currentPlayer = nameBox->text().toStdString();
    //cout << currentPlayer << endl;
    if(currentPlayer == "Enter your name. (Game won't start until you do)")
    {
    	return;
    }
    scene->clear();
    enemies.clear();
    goodies.clear();
    updateScoreboard();
    writeHighScores(FILE_NAME);
    model.reset();
    timeCounter = 0;
    spawnRate = 1;
    speed = 10;
    increaseSpeed =0;
    timer->setInterval(10);
    setToDefaultPositions();

    model.go();
    timer->start();
}
void JaseuWindow::updateScoreboard(){
	int newScore = model.getScore()/10;
	//int newScore = 1337;
	string newName = currentPlayer;
	
	for(int i=0; i<5; i++){
	if(newScore >= intTopScores[i])
	{
		int temp1 = intTopScores[i];
		string temp2 = topScoreNames[i];
		intTopScores[i] = newScore;
		topScoreNames[i] = newName;
		while(i < 4){
		intTopScores[i+1] = temp1;
		topScoreNames[i+1] = temp2;
		temp1 = intTopScores[i+1];
		temp2 = topScoreNames[i+1];
		i++;
		}
	  }
	}
    topScores->clear();
    string beginning = "High Scores:\n\n";
    topScores->addItem(beginning.c_str());
    for(int i=0; i<5; i++) {
     string str;
     stringstream out;
     out << topScoreNames[i] << ":	" << intTopScores[i];
     str = out.str();
     
    topScores->addItem(str.c_str());
    }
	


}
void JaseuWindow::keyPressEvent( QKeyEvent *e ) {
    //cout << "Key is " << e->key() << endl;
    if(( e->key() == Qt::Key_W) || (e->key() == Qt::Key_Up) ) {
        if(player) {
                player->setVelocityY(2);

        }
        return;
    }
    if(( e->key() == Qt::Key_S) || (e->key() == Qt::Key_Down) ) {
        if(player) {
                player->setVelocityY(-2);
        }
        return;
    }
    if(( e->key() == Qt::Key_A) || (e->key() == Qt::Key_Left) ) {
        if(player) {
               player->setVelocityX(-2);

        }
        return;
    }
    if(( e->key() == Qt::Key_D) || (e->key() == Qt::Key_Right) ) {
        if(player) {
               player->setVelocityX(2);
        }
        return;
    }


}
void JaseuWindow::keyReleaseEvent( QKeyEvent *e ) {
    if(( e->key() == Qt::Key_W) || (e->key() == Qt::Key_Up) ) {
        if(player) {
            if(player->getVelocityY()>0)
                player->setVelocityY(0);
        }
    }
    if(( e->key() == Qt::Key_S) || (e->key() == Qt::Key_Down) ) {
        if(player)
        {
            if(player->getVelocityY()<0)

                player->setVelocityY(0);
        }
    }
    if(( e->key() == Qt::Key_A) || (e->key() == Qt::Key_Left) ) {
        if(player)
        {   if(player->getVelocityX()<0)

                player->setVelocityX(0);
        }
    }
    if(( e->key() == Qt::Key_D) || (e->key() == Qt::Key_Right) ) {
        if(player) {
            if(player->getVelocityX()>0)
                player->setVelocityX(0);
        }
    }
    if((e->key() == Qt::Key_F)|| (e->key() == 16777220)  || (e->key() == 32) ) {
        if(player) {
            Laser* bullet = new Laser(laserImage, player->getX(), player->getY());
            scene -> addItem(bullet);
            goodies.push_back(bullet);
        }
    }
}

JaseuWindow::JaseuWindow()  {
    srand(time(0));
    
    for(int i=0; i<5; i++){
    intTopScores[i] = (5-i)*100;
    string temp = "John Doe";
    topScoreNames[i] = temp;
    }
    readHighScores(FILE_NAME);
    player = NULL;
    timer = NULL;
    speed = 10;
    increaseSpeed = 0;
    spawnRateRate = .1;
    
    playerShip = new QPixmap("./images/playerShip_clear.gif");
    crusherShip = new QPixmap("./images/crusher_clear.gif");
    laserImage = new QPixmap("./images/laser_clear.gif");
    zShip = new QPixmap("./images/ZigZagger_clear.gif");
    topShip = new QPixmap("./images/top_clear.gif");
    shootShip = new QPixmap("./images/shooter1_clear.gif");
    trollShip = new QPixmap("./images/troll_clear.gif");


    timer = new QTimer(this);
    timer->setInterval(speed);
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
    
    //QLabel* currentPlayerName = new QLabel();
    
    nameBox = new QLineEdit("Enter your name. (Game won't start until you do)");
    


    //start: layout stuff
    setFixedSize(1000, 700);

    pause = new QPushButton("Pause");
    start = new QPushButton("Start");
    quit = new QPushButton("Quit");
    scoreLabel = new QLabel("Score: ");
    livesLabel = new QLabel("Lives: ");
    //continuesLabel = new QLabel("Continues Used: ");

    debug = new QTextEdit();
    debug->setFixedSize(1000,50);



    score = new QLCDNumber();
    score->setAutoFillBackground(true);
    QPalette scorePal = score->palette();
    scorePal.setColor(QPalette::Normal, QPalette::WindowText, Qt::green);
    scorePal.setColor(QPalette::Normal, QPalette::Window, Qt::black);
    score->setPalette(scorePal);
    score->setSegmentStyle(QLCDNumber::Filled);
    score->setFixedSize(100,25);
    score->display(model.getScore());
    lives = new QLCDNumber();
    lives->setAutoFillBackground(true);
    lives->setPalette(scorePal);
    lives->setSegmentStyle(QLCDNumber::Filled);
    lives->setFixedSize(100,25);
    lives->display(model.getLives());
    /*continues = new QLCDNumber();
    continues->setAutoFillBackground(true);
    continues->setPalette(scorePal);
    continues->setFixedSize(100,25);
    continues->setSegmentStyle(QLCDNumber::Filled);
    continues->display(model.getCont());*/

    QBrush greenBrush(Qt::green);
    QBrush blackBrush(Qt::black);
    QBrush whiteBrush(Qt::white);

    scene = new QGraphicsScene();
    view = new QGraphicsView( scene );
    view->setFixedSize( SCENE_WINDOW_X+10, SCENE_WINDOW_Y+10);

    view->setBackgroundBrush(blackBrush);
    scene->setSceneRect(0,0,SCENE_WINDOW_X,SCENE_WINDOW_Y);


    layout = new QVBoxLayout;

    QHBoxLayout* topButtons = new QHBoxLayout;
    topButtons->addWidget(pause);
    topButtons->addWidget(start);
    topButtons->addWidget(nameBox);

    QHBoxLayout* middleStuff = new QHBoxLayout;


    QVBoxLayout* sideInterface = new QVBoxLayout;
    //sideInterface->setFixedSize(150, 600);

    QHBoxLayout* scoreLayout = new QHBoxLayout;
    scoreLayout->addWidget(scoreLabel);
    scoreLayout->addWidget(score);

    sideInterface->addLayout(scoreLayout);

    QHBoxLayout* livesLayout = new QHBoxLayout;
    livesLayout->addWidget(livesLabel);
    livesLayout->addWidget(lives);

    sideInterface->addLayout(livesLayout);
     
    topScores = new QListWidget();
    
    sideInterface->addWidget(topScores); 
     
    //QHBoxLayout* continueLayout = new QHBoxLayout;
    //continueLayout->addWidget(continuesLabel);
    //continueLayout->addWidget(continues);

    //sideInterface->addLayout(continueLayout);
    sideInterface->addWidget(quit);

    middleStuff->addLayout(sideInterface);

    middleStuff->addWidget(view);

    layout->addLayout(topButtons);
    layout->addLayout(middleStuff);
//    layout->addWidget(debug);

    setLayout(layout);
    //End: Layout stuff

    //start button connections
    connect(start, SIGNAL(clicked()), this, SLOT(initialize()));
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(pause, SIGNAL(clicked()), this, SLOT(handlePause()));

    
    updateScoreboard();
    
    setFocusPolicy(Qt::StrongFocus);
}

void JaseuWindow::updateNums() {

    score->display(model.getScore()/10);
    lives->display(model.getLives());
    //continues->display(model.getCont());


}

JaseuWindow::~JaseuWindow()
{

}

