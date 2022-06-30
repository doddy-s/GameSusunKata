void red(std::string s)
{
    cout << "\033[1;31m" << s <<"\033[0m";
}

void cursor(int i)
{
    cout << "  ";
    while(i > 1)
    {
        cout << "    ";
        i--;
    }
    cout << '^';
}

//2 6 10
//| a | a | a |
//          ^