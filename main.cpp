#include <iostream>
#include <time.h>
#include <fstream>
#include <random>
#include <conio.h>
#include <cstring>

using std::cout;
using std::cin;

#include "src/Randomizer.cpp"
#include "src/Dictionary.cpp"
#include "src/Score.cpp"
#include "src/io.cpp"
#include "src/Display.cpp"
#include "src/LinkedList.cpp"
#include "src/Setting.cpp"
#include "src/Play.cpp"

int main()
{
    int mainCursor{};
    char mainMenu;

    Score *highScore = new Score[10]{};
    Score *history = new Score[10]{};

    //loadData("highScore.dat", highScore);
    //loadData("history.dat", history);
    //loadData("setting.dat", history);

    for(int i{}; i < 10; i++)
    {
        highScore[i] = {i+100, "DEV", "NULL"};
    }

    for(int i{}; i < 10; i++)
    {
        history[i] = {i+100, "DEV", "NULL"};
    }
    
    while(true)
    {
        system("cls");
        printMenu(mainCursor);

        mainMenu = getch();

        if(mainMenu == 'w')
        {
            if(mainCursor == 0)
                play(highScore, history);
            else if(mainCursor == 1)
                printScore(highScore);
            else if(mainCursor == 2)
                printScoreReversed(history);
            else if(mainCursor == 4)
                settingMenu();
            else if(mainCursor == 5)
                break;
        }
        else if(mainMenu == 'a')
        {
            if(mainCursor == 0)
            {
                mainCursor = 5;
                continue;
            }
            mainCursor--;
        }
        else if(mainMenu == 'd')
        {
            if(mainCursor == 5)
            {
                mainCursor = 0;
                continue;
            }
            mainCursor++;
        }
    }

    //saveData("highScore.dat", highScore);
    //saveData("history.dat", history);
    //saveData("setting.dat", history);

}