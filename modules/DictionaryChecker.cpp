class Dictionary
{
    std::string* dictionary = new std::string[370105];

    public:
    Dictionary()
    {
        std::fstream f;
        f.open("src/words_alpha.txt");

        if(!f.is_open())
        {
            cout << "Error when opening file.\n";
        }

        int i = 0;
        while(!f.eof())
        {
            f>>dictionary[i];
            i++;
        }
        f.close();
    }

    bool checkDictionary(std::string search)
    {
        for(int i = 0; i<370105; i++)
        {
            if(search == dictionary[i])
            {
                return true;
            }
        }
        return false;
    }
};