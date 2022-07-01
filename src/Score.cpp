struct Score
{
    int score;
    char name[8], time[25];
};

std::string getTime()
{
   time_t now = time(0);
   return ctime(&now);
}

void inputHighScore(Score *highScore, int score, std::string name)
{
    if(score > highScore[9].score)
    {
        highScore[9].score = score;
        strcpy(highScore[9].name, name.c_str());
        strcpy(highScore[9].time, getTime().c_str());
    }
    sortDescending(highScore);
}

void inputHistory(Score *history, int score, std::string name)
{
    for(int i{}; i < 9; i++)
    {
        history[i] = history[i + 1];
    }
    history[9].score = score;
    strcpy(history[9].name, name.c_str());
    strcpy(history[9].time, getTime().c_str());
}