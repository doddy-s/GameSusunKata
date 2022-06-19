void hold()
{
    cin.ignore();
    cout << "\nTekan 'Enter' untuk melanjutkan";
    cin.ignore();
}

char inputChar(char a, char b)
{
    char userInput;

    while(1)
    {
        cin.clear();
        cin >> userInput;

        if(userInput == a || userInput == b) break;

        cout << "Input tidak sesuai!!, ulangi: ";
    }

    return userInput;
}

bool isNumber(const std::string &str)
{
    for (const char &c : str)
        if (!std::isdigit(c)) return false;

    return true;
}

int inputInteger(int a, int b)
{
    std::string userInput;

    while(1)
    {
        cin.clear();
        cin >> userInput;

        if(isNumber(userInput))
            if(stoi(userInput) >= a && stoi(userInput) <= b) break;
            
        cout << "Input tidak sesuai!!, ulangi: ";
    }

    return stoi(userInput);
}