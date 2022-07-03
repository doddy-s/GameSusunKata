#include <iostream>
#include <time.h>
#include <fstream>
#include <random>
#include <conio.h>
#include <cstring>
#include <windows.h>
#include <Lmcons.h>

using std::cout;
using std::cin;

#include "Randomizer.cpp"
#include "Dictionary.cpp"
#include "Score.cpp"
#include "Display.cpp"
#include "LinkedList.cpp"
#include "Setting.cpp"
#include "io.cpp"
#include "Play.cpp"

int main()
{
    char username[UNLEN+1];
    DWORD username_len = UNLEN+1;
    GetUserName(username, &username_len);

    std::string path = "C:/Users/" + std::string(username)
                        + "/Documents/GameSusunKata/data/";
    
    int mainCursor{};
    char mainMenu;

    Score *highScore = new Score[10]{};
    Score *history = new Score[10]{};

    loadData(path + "highScore.dat", highScore);
    loadData(path + "history.dat", history);

    /**
    for(int i{}; i < 10; i++)
    {
        highScore[i] = {0, "DEV", "NULL"};
        strcpy(highScore[i].time, getTime().c_str());
    }

    for(int i{}; i < 10; i++)
    {
        history[i] = {0, "DEV", "NULL"};
        strcpy(history[i].time, getTime().c_str());
    }
    **/

    printMenuGuide();

    while(true)
    {
        system("cls");
        printMenu(mainCursor);

        mainMenu = tolower(getch());

        if(mainMenu == 'w')
        {
            if(mainCursor == 0)
                play(highScore, history);
            else if(mainCursor == 1)
                printScore(highScore);
            else if(mainCursor == 2)
                printScoreReversed(history);
            else if(mainCursor == 3)
                printHowToPlay();
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

    cout << '\n';
    saveData(path + "highScore.dat", highScore);
    saveData(path + "history.dat", history);

}