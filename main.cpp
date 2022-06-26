#include <iostream>
#include <time.h>
#include <fstream>
#include <random>

using std::cout;
using std::cin;

#include "LinkedList.cpp"
#include "Randomizer.cpp"
#include "Dictionary.cpp"
#include "Score.cpp"
#include "io.cpp"

int main()
{
    int menu, subMenu;
    Node* tableHead = NULL;
    Node* handHead = NULL;
    Randomizer random;
    Dictionary checker;

    Score highScore[10];
    Score history[10];

    //loadData('highScore.dat', &highScore[10]);
    //loadData('history.dat', &history[10]);
    
    do
    {
        system("cls");
        cout << "1.) Play\n";
        cout << "2.) Highscores\n";
        cout << "3.) History\n";
        cout << "4.) Cara Main\n";
        cout << "0.) Exit\n";
        cout << "Input: ";
        
        menu = inputInteger(0, 6);

        system("cls");

        if(menu == 1)
        {
            int tableIndex, handIndex, index, index2, score{};
            bool win = true;
            char name[8];

            do
            {
                for(int i{}; i < 4; i++)
                    {
                        addNodeLeft(&tableHead, random.getLetter());
                        addNodeLeft(&handHead, random.getLetter());
                    }
                tableIndex = 4;
                handIndex = 4;
                do
                {
                    system("cls");

                    cout << "\tTable\n";
                    printIndex(tableHead);
                    printLetter(tableHead);

                    cout << "\n\tHand\n";
                    printIndex(handHead);
                    printLetter(handHead);

                    cout << "\n1.) Hapus huruf dari table\n";
                    cout << "2.) Masukkan huruf ke table\n";
                    cout << "3.) Reverse huruf pada table\n";
                    cout << "0.) Submit susunan pada table\n";
                    cout << "Input: ";

                    subMenu = inputInteger(0, 3);
                    if(subMenu == 1)
                    {
                        if(tableHead == 0) continue;

                        cout << "Index ke? ";
                        index = inputInteger(1, tableIndex);

                        deleteNode(&tableHead, index);
                        tableIndex--;
                    }
                    else if(subMenu == 2)
                    {
                        if(handIndex == 0) continue;

                        cout << "Dari index ke? ";
                        index = inputInteger(1, handIndex);
                        
                        if(tableIndex == 0)
                        {
                            addNodeLeft(&tableHead,getLetter(handHead,index));
                        }
                        else
                        {
                            cout << "Ke index setelah? ";
                            index2 = inputInteger(1, tableIndex);
                            addNodeMid(&tableHead,
                            getLetter(handHead, index), index2);
                        }

                        deleteNode(&handHead, index);
                        handIndex--;
                        tableIndex++;
                    }
                    else if(subMenu == 3)
                    {
                        if(tableIndex == 0) continue;
                        reverse(&tableHead);
                    }
                } while (subMenu != 0);

                system("cls");
                
                std::string submit;
                for(int i = 1; i <= tableIndex; i++)
                    submit += getLetter(tableHead, i);
                
                //submit = "test";
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

                hold();
            }while(win);

            cout << "Game Over";
            cout << "Masukkan nama anda: ";
            cin >> name;

            //Proses input score ke highScore[] disini

            //Proses input score ke history[] disini
            
        }
        else if(menu == 2)
        {
            //Tampilkan highScore[]

        }
        else if(menu == 3)
        {
            //Tampilkan history[]

        }
        else if(menu == 4)
        {
            //Tampilkan cara bermain

        }
    } while (menu != 0);

    //saveData('highScore.dat', &highScore[10]);
    //saveData('history.dat', &history[10]);

}