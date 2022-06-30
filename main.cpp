#include <iostream>
#include <time.h>
#include <fstream>
#include <random>
#include <conio.h>

using std::cout;
using std::cin;

#include "LinkedList.cpp"
#include "Randomizer.cpp"
#include "Dictionary.cpp"
#include "Score.cpp"
#include "io.cpp"
#include "Display.cpp"

int main()
{
    int mainMenu, subMenu;
    Node* tableHead = NULL;
    Node* handHead = NULL;
    Randomizer random;
    Dictionary checker;

    Score *highScore = new Score[10];
    Score *history = new Score[10];

    //loadData('highScore.dat', &highScore[10]);
    //loadData('history.dat', &history[10]);
    
    do
    {
        system("cls");
        red("1.) Play\n");
        //cout << "\033[1;31m1.) Play\033[0m\n";
        cout << "2.) Highscores\n";
        cout << "3.) History\n";
        cout << "4.) Cara Main\n";
        cout << "0.) Exit\n";
        
        //mainMenu = inputInteger(0, 6);

        mainMenu = getch();

        system("cls");

        if(mainMenu == '1')
        {
            int tableIndex, handIndex, index, index2, score{}, pointed = 1;
            bool win = true;
            char name[8], play{};
            std::string submit{};

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
                } while (play != 'q');

                system("cls");
                
                for(int i = 1; i <= tableIndex; i++)
                    submit += tolower(getLetter(tableHead, i));

                //scout << submit;
                
                if(checker.checkDictionary(submit))
                {
                    cout << "Kata yang anda submit ada di kamus";
                    score += tableIndex;
                }
                else
                {
                    cout << "Kata yang anda submit tidak ada di kamus";
                    win = false;
                }

                deleteList(&tableHead);
                deleteList(&handHead);
                submit.erase();

                hold();
            }while(win);

            cout << "Game Over";
            //cout << "Masukkan nama anda: ";
            //cin >> name;

            //Proses input score ke highScore[] disini

            //Proses input score ke history[] disini
            hold();
            
        }
        else if(mainMenu == '2')
        {
            //Tampilkan highScore[]

        }
        else if(mainMenu == '3')
        {
            //Tampilkan history[]

        }
        else if(mainMenu == '4')
        {
            //Tampilkan cara bermain

        }
    } while (mainMenu != '0');

    //saveData('highScore.dat', &highScore[10]);
    //saveData('history.dat', &history[10]);

}