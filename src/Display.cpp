struct color
{
    const std::string red = "\033[0;31m";
    const std::string green = "\033[1;32m";
    const std::string yellow = "\033[1;33m";
    const std::string blue = "\033[38;5;19m";
    const std::string magenta = "\033[0;35m";
    const std::string reset = "\033[0m";
}c;

struct menu
{
    const std::string menu[6] = {"   PLAY    ", " HIGHSCORE ",
                                 "  HISTORY  ", "HOW TO PLAY",
                                 "  SETTING  ", "   EXIT    "};
}m;

void printMenu(int cursor)
{
    cout << c.green << "\t\t\t\t\tMAIN MENU\n" << c.reset;
    cout << "\n|| ";
    for(int i{}; i < 6; i++)
    {
        if(i == cursor)
            cout << c.green << m.menu[i] << c.reset;
        else
            cout << c.red << m.menu[i] << c.reset;
        cout << " || ";
    }
}

void point(int i)
{
    cout << "  ";
    while(i > 1)
    {
        cout << "    ";
        i--;
    }
    cout << '^';
}

void printScore(Score *temp)
{
    bool clr = true;
    cout << "\n\nNo.  Name\tScore\tTime\n";
    for(int i{}; i < 10; i++)
    {
        if(clr)
        cout << c.red << i+1 << ".   " << temp[i].name << "\t"
             << temp[i].score << "\t" << temp[i].time << c.reset << '\n';
        else
        cout << c.green << i+1 << ".   " << temp[i].name << "\t"
             << temp[i].score << "\t" << temp[i].time << c.reset << '\n';

        clr = !clr;
    }

    hold();
}

void printScoreReversed(Score *temp)
{
    bool clr = true;
    cout << "\n\nNo.  Name\tScore\tTime\n";
    for(int i{}; i < 10; i++)
    {
        if(clr)
        cout << c.red << i+1 << ".   " << temp[9 - i].name << "\t"
             << temp[9 - i].score << "\t" << temp[9 - i].time << c.reset << '\n';
        else
        cout << c.green << i+1 << ".   " << temp[9 - i].name << "\t"
             << temp[9 - i].score << "\t" << temp[9 - i].time << c.reset << '\n';

        clr = !clr;
    }

    hold();
}