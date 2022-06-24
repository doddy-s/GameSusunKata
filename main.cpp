#include <iostream>
#include <time.h>
#include <fstream>
#include <random>

using std::cout;
using std::cin;

#include "lib/LinkedList.cpp"
#include "lib/Randomizer.cpp"
#include "lib/Dictionary.cpp"
#include "lib/io.cpp"

int main()
{
    int menu, subMenu;
    Node* tableHead = NULL;
    Node* handHead = NULL;
    Randomizer random;
    Dictionary checker;
    
    do
    {
        system("clear");
        cout << "1.) Play\n";
        cout << "2.) Highscores\n";
        cout << "3.)\n";
        cout << "0.) Exit\n";
        cout << "Input = ";
        
        menu = inputInteger(0, 6);

        system("clear");

        if(menu == 1)
        {
            int tableIndex, handIndex, index, index2, score{};

            for(int i{}; i < 5; i++)
            {
                addNodeLeft(&tableHead, random.getLetter());
                tableIndex = 5;
                addNodeLeft(&handHead, random.getLetter());
                handIndex = 5;
            }

            do
            {
                system("clear");

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

                subMenu = inputInteger(0, 3);
                if(subMenu == 1)
                {
                    cout << "Index ke? ";
                    index = inputInteger(1, tableIndex);
                    deleteNode(&tableHead, index);
                    tableIndex--;
                }
                else if(subMenu == 2)
                {
                    cout << "Dari index ke? ";
                    index = inputInteger(1, handIndex);
                    cout << "Ke index setelah? ";
                    index2 = inputInteger(1, tableIndex);
                    addNodeMid(&tableHead,getLetter(handHead,handIndex),index2);
                    deleteNode(&handHead, index);
                    handIndex--;
                    tableIndex++;
                }
                else if(subMenu == 3)
                {
                    reverse(&tableHead);
                }
            } while (subMenu != 0);

            system("clear");
            
            std::string submit;
            for(int i = 1; i <= tableIndex; i++)
                submit += getLetter(tableHead, i);
            
            if(checker.checkDictionary(submit))
            {
                cout << "Kata yang anda submit ada di kamus\n";
                
                //score akan dimasukkan ke queue highscore
                score += tableIndex; 
            }
            else
                cout << "Kata yang anda submit tidak ada di kamus\n";

            hold();
        }
        /**
        else if(menu == 2)
        {

        }
        else if(menu == 3)
        {

        }
        else if(menu == 4)
        {

        }
        else if(menu == 5)
        {

        }
        else if(menu == 6)
        {

        }
        else if(menu == 7)
        {

        }
        else if(menu == 8)
        {

        }
        **/
    } while (menu != 0);
    
}