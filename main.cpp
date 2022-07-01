#include <iostream>
#include <time.h>
#include <fstream>
#include <random>
#include <conio.h>
#include <cstring>

using std::cout;
using std::cin;

#include "src/LinkedList.cpp"
#include "src/Randomizer.cpp"
#include "src/Dictionary.cpp"
#include "src/Score.cpp"
#include "src/io.cpp"
#include "src/Display.cpp"
#include "src/Sort.cpp"
#include "src/HighScore.cpp"

int main()
{
    int mainMenu, subMenu;
    Node* tableHead = NULL;
    Node* handHead = NULL;
    Randomizer random;
    Dictionary checker;

    Score *highScore = new Score[10]{};
    Score *history = new Score[10]{};

    //loadData("highScore.dat", highScore);
    //loadData("history.dat", history);

    for(int i{}; i < 10; i++)
    {
        highScore[i] = {1, "DEV", "NULL"};
        strcpy(highScore[i].time, getTime().c_str());
    }

    for(int i{}; i < 10; i++)
    {
        history[i] = {1, "DEV", "NULL"};
        strcpy(history[i].time, getTime().c_str());
    }
    
    do
    {
        system("cls");
        red("1.) Play\n");
        cout << "2.) Highscores\n";
        cout << "3.) History\n";
        cout << "4.) Cara Main\n";
        cout << "0.) Exit\n";

        mainMenu = getch();

        system("cls");

        if(mainMenu == '1')
        {
            int tableIndex, handIndex, index, index2, score{}, pointed = 1;
            bool win = true;
            char play{};
            std::string submit{}, name{};

            do
            {
                for(int i{}; i < 4; i++)
                    {
                        addNodeLeft(&handHead, random.getVowel());
                        addNodeLeft(&handHead, random.getConsonant());
                    }
                tableIndex = 0;
                handIndex = 8;
                do
                {
                    system("cls");

                    printLetter(tableHead);
                    cout << '\n';
                    printLetter(handHead);
                    cursor(pointed);

                    if(handIndex == 0) break;

                    play = getch();

                    if(play == 'w')
                    {
                        addNodeRight(&tableHead, getLetter(handHead, pointed));
                        deleteNode(&handHead, pointed);

                        handIndex--;
                        tableIndex++;
                    }
                    else if(play == 'a')
                    {
                        if(pointed == 0) continue;
                        pointed--;
                    }
                    else if(play == 'd')
                    {
                        if(pointed == handIndex) continue;
                        pointed++;
                    }
                    else if(play == 's')
                    {
                        deleteNode(&handHead, pointed);
                        handIndex--;
                    }
                    else if(play == 'e')
                    {
                        addNodeRight(&handHead, random.getLetter());
                        handIndex++;
                    }
                } while (play != 'q');

                system("cls");
                
                for(int i = 1; i <= tableIndex; i++)
                    submit += tolower(getLetter(tableHead, i));

                //scout << submit;
                
                if(checker.checkDictionary(submit))
                {
                    cout << "Kata yang anda submit ada di kamus";
                    score += tableIndex;
                    hold();
                }
                else
                {
                    cout << "Kata yang anda submit tidak ada di kamus";
                    win = false;
                }

                deleteList(&tableHead);
                deleteList(&handHead);
                submit.erase();
            }while(win);

            cout << "Game Over\n";
            cout << "Masukkan nama anda: ";
            cin >> name;

            //Proses input score ke highScore[] disini
            inputHighScore(highScore, score, name);
            
            //Proses input score ke history[] disini
            inputHistory(history, score, name);

            hold();
            
        }
        else if(mainMenu == '2')
        {
            //Tampilkan highScore[],
            for(int i{}; i < 10; i++)
            {
                cout << i+1 << ".)  " << highScore[i].name << "\t"
                    << highScore[i].score << "\t"
                    << highScore[i].time << '\n';
            }

            hold();

        }
        else if(mainMenu == '3')
        {
            //Tampilkan history[]
            for(int i{}; i < 10; i++)
            {
                cout << i << ".)  " << history[i].name << "\t"
                    << history[i].score << "\t"
                    << history[i].time << '\n';
            }

            hold();
        }
        else if(mainMenu == '4')
        {
            //Tampilkan cara bermain

        }
    } while (mainMenu != '0');

    //saveData("highScore.dat", highScore);
    //saveData("history.dat", history);

}