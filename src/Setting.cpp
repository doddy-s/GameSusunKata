struct Setting
{
    bool guidePlay;
    int difficulty;

    const std::string setting[3] = {"SHOW GUIDE DURING GAMEPLAY", "DIFFICULTY",
                                    "BACK"};
    const std::string diff[3] = {"EASY", "NORMAL", "HARD"};
}setting{};

void printSetting(int cursor)
{
    cout << c.green << "\t\t\tSETTING\n" << c.reset;
    cout << "\n|| ";
    for(int i{}; i < 3; i++)
    {
        if(i == cursor)
        {
            cout << c.green << setting.setting[i] << c.reset;
            if(cursor == 0)
            {
                cout << ": ";
                if(setting.guidePlay) cout << "ON";
                else cout << "OFF";
            }
            else if(cursor == 1)
                cout << ": "<< setting.diff[setting.difficulty];
        }
        else
            cout << c.red << setting.setting[i] << c.reset;
        cout << " || ";
    }
}

void settingMenu()
{
    int menu = 0, cursor = 0;
    while(true)
    {
        system("cls");
        printSetting(cursor);

        menu = tolower(getch());

        if(menu == 'w')
        {
            if(cursor == 0)
                setting.guidePlay = !setting.guidePlay;
            else if(cursor == 1)
                if(setting.difficulty == 2) setting.difficulty = 0;
                else setting.difficulty++;
            else if(cursor == 2)
                break;
        }
        else if(menu == 'a')
        {
            if(cursor == 0)
            {
                cursor = 2;
                continue;
            }
            cursor--;
        }
        else if(menu == 'd')
        {
            if(cursor == 2)
            {
                cursor = 0;
                continue;
            }
            cursor++;
        }
    }
}