void play(Score *highScore, Score *history)
{
    Node* tableHead = NULL;
    Node* handHead = NULL;
    int tableIndex, handIndex, level = 1, score{}, cursor = 1;
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

            cout << "Level: " << level << '\t' << "Score: " << score << '\n';
            printLetter(tableHead, cursor);
            cout << '\n';
            printLetter(handHead, cursor);
            point(cursor);

            if(handIndex == 0) break;

            play = getch();

            if(play == 'w')
            {
                if(cursor > handIndex)
                {
                    cout << "Index tidak ada";
                    hold();
                    continue;
                }
                addNodeRight(&tableHead, getLetter(handHead, cursor));
                deleteNode(&handHead, cursor);

                handIndex--;
                tableIndex++;
            }
            else if(play == 'a')
            {
                if(cursor == 1)
                {
                    cursor = handIndex;
                    continue;
                }
                cursor--;
            }
            else if(play == 'd')
            {
                if(cursor == handIndex)
                {
                    cursor = 1;
                    continue;
                }
                cursor++;
            }
            else if(play == 's')
            {
                deleteNode(&handHead, cursor);
                handIndex--;
            }
            else if(play == 'e')
            {
                if((*setting).difficulty == 0)
                {
                    addNodeRight(&handHead, random.getLetter());
                }
                else if((*setting).difficulty == 1)
                {
                    if(score > 0)
                    {
                        addNodeRight(&handHead, random.getLetter());
                        score--;
                    }
                    else cout << "\nScore kurang.";
                }
                else if((*setting).difficulty == 2)
                {
                    if(score > 1)
                    {
                        addNodeRight(&handHead, random.getLetter());
                        score-=2;
                    }
                    else cout << "\nScore kurang.";
                }
                handIndex++;
            }
            else if(play == 'z')
            {
                if(cursor > tableIndex)
                {
                    cout << "Index tidak ada";
                    hold();
                    continue;
                }
                deleteNode(&tableHead, cursor);
            }
        } while (play != 'q');

        system("cls");
        
        for(int i = 1; i <= tableIndex; i++)
            submit += tolower(getLetter(tableHead, i));

        
        cout << submit;
        
        if(checker.checkDictionary(submit))
        {
            cout << "\nKata yang anda submit ada di kamus";
            score += tableIndex;
            hold();
        }
        else
        {
            cout << "\nKata yang anda submit tidak ada di kamus";
            win = false;
        }

        deleteList(&tableHead);
        deleteList(&handHead);
        submit.erase();
    }while(win);

    cout << "\nGame Over\n";
    cout << "Masukkan nama anda: ";
    getline(cin, name);

    //Proses input score ke highScore[] disini
    inputHighScore(highScore, score, name);
    
    //Proses input score ke history[] disini
    inputHistory(history, score, name);

    hold();
}