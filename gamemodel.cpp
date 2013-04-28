#include "gamemodel.h"

Game::Game() {
    started = false;
    end = false;
    continuesRemaining = 3;
    lives = 3;
    score = 0;
    scoreRate = 1.0;
    newLife = 0;

}
bool Game::start(){
return started;
}


    void Game::reset(){
    started = false;
    end = false;
    continuesRemaining = 3;
    lives = 3;
    score = 0;
    scoreRate = 1.0;
    newLife = 0;
    
    }
Game::~Game() {
}

void Game::go() {
    started = true;
}
void Game::addLife() {
    lives++;
}
void Game::updateScore(int s) {
    score += s*scoreRate;
    newLife += s*scoreRate;
    if(newLife >499) {
        lives++;
        newLife -= 500;
    }

}
void Game::removeLife() {
    lives--;
    if(lives == 0)
    {
        end = true;
    }
}
bool Game::gameOver() {
    return end;

}
void Game::useContinue() {
    if(continuesRemaining == 0) {
        return;
    }
    continuesRemaining--;
    end = false;
    score = score/2;
    scoreRate = scoreRate/2;
    lives = 3;
    newLife = 0;
}

double Game::getRate(){
   return scoreRate;
}

int Game::getScore() {
    return score;
}
int Game::getLives() {
    return lives;
}
int Game::getCont() {
    return continuesRemaining;
}
