class Game {
public:
    Game();
    ~Game();

    void go();
    void addLife();
    void updateScore(int s);
    void removeLife();
    bool gameOver();
    void useContinue();

    int getScore();
    int getLives();
    int getCont();


private:
    bool started;
    bool end;
    int continuesRemaining;
    int lives;
    int score;
    double scoreRate;
    int newLife;
};
