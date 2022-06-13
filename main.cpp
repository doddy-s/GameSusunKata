#include <iostream>
#include <ctime>
//#include <stdlib.h>
#include "modules/LinkedList.cpp"
#include "modules/LetterPicker.cpp"
#include "modules/DictionaryChecker.cpp"

using std::cout;
using std::cin;
using std::string;

int main()
{
    //srand(time(NULL));
    int menu, subMenu, index;
    Node* tableHead = NULL;
    Node* handHead = NULL;
    Dictionary Checker;
    
    do
    {
        system("clear");
        cout << "1.) Play\n";
        cout << "2.) Highscores\n";
        cout << "3.)\n";
        cout << "4.)\n";
        cout << "5.)\n";
        cout << "6.)\n";
        cout << "0.) Exit\n";
        cout << "Input = ";
        
        cin >> menu;

        system("clear");

        if(menu == 1)
        {
            for(int i = 0; i < 4; i++)
            {
                addNodeLeft(&tableHead, getLetter());
                addNodeLeft(&handHead, getLetter());
            }

            do
            {
                system("clear");

                cout << "Table";
                printIndex(tableHead);
                printLinkedList(tableHead);
                cout << '\n';
                cout << "Hand";
                printIndex(handHead);
                printLinkedList(handHead);
                cout << '\n';

                cout << "1.) Ambil huruf dari table\n";
                cout << "2.) Masukkan huruf ke table\n";
                cout << "0.) Submit susunan pada table\n";
                if(subMenu == 1)
                {
                    cout << "Index ke? ";
                    cin >> index;
                    deleteNode(&tableHead, &handHead, index);
                }
                else if(subMenu == 2)
                {
                    cout << "Dari index ke? ";
                    cin >> index;
                    deleteNode(&handHead, &tableHead, index);
                }
            } while (subMenu != 0);

            system("clear");
            
            string* submitted = new string;

            if(Checker.checkDictionary(*submitted))
            {
                cout << "Kata yang anda submit ada di kamus";
            }
            else
            {
                cout << "Kata yang anda submit tidak ada di kamus";
            }
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