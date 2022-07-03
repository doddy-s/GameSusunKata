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

void saveData(std::string fileName, Score *write)
{
	std::ofstream f(fileName, std::ios::binary);

	if (f.is_open()) {
		f.write(reinterpret_cast<char*>(write), 10 * sizeof(Score));
		std::cout << "Save data berhasil\n";
		f.close();
	}
	else
	{
		std::cout << "Gagal tersimpan\n";
	}
}
void loadData(std::string fileName, Score *read)
{
	std::ifstream f(fileName, std::ios::binary);

	if (f.is_open()) {
		f.read(reinterpret_cast<char*>(read), 10 * sizeof(Score));
		std::cout << "Load data berhasil\n";
		f.close();
	}
	else
	{
		std::cout << "Load file gagal. Pastikan nama file benar!\n";
	}
}
