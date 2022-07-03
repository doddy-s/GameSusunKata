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

void hold()
{
    cout << "\nTekan apapun untuk melanjutkan";
    getch();
}

void printMenu(int cursor)
{
    cout << c.magenta << "\t\t\t\t\tGAME SUSUN KATA\n" << c.reset;
    cout << c.green << "\t\t\t\t\t   MAIN MENU\n" << c.reset;
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
             << temp[9 - i].score << "\t" << temp[9- i].time << c.reset << '\n';
        else
        cout << c.green << i+1 << ".   " << temp[9 - i].name << "\t"
             << temp[9 - i].score << "\t" << temp[9- i].time << c.reset << '\n';

        clr = !clr;
    }

    hold();
}

void printMenuGuide()
{
    cout << "Navigasi Menu Dengan Cara\n";
    cout << "a,d - gerakkan kursor\n";
    cout << "w - akses menu\n";
    cout << "Exit secara benar agar data tersimpan\n";
    hold();
}

void printGuide()
{
    cout << "\nGUIDE:\n";
    cout << "a,d - gerakkan kursor\n";
    cout << "w - naikkan huruf\n";
    cout << "s - delete huruf di bawah\n";
    cout << "z - delete huruf di atas\n";
    cout << "e - minta tambahan huruf\n";
    cout << "q - submit kata\n";
}

void printHowToPlay()
{
    cout << "\n\nHOW TO PLAY\n";
    cout << "1. Player akan diberikan sejumlah huruf pada barisan bawah yang dapat disusun pada barisan atas.\n";
    cout << "2. Objective dari game ini adalah menyusun huruf yang disediakan menjadi kata dalam bahasa inggris\n";
    cout << "3. Kata akan otomatis tersubmit setelah huruf pada barisan bawah habis\n";
    cout << "4. Setiap huruf yang benar akan diberikan 1 score\n";
    cout << "5. Player dapat meminta tambahan huruf dengan menukar skor (easy = 0, normal = 1, hard = 2)\n";
    cout << "6. Pada easy difficulty skor akhir tidak dimasukkan ke highScore, pada hard difficulty skor akhir akan dikali 2";
    printGuide();

    hold();
}