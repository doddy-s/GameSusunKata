#include <fstream>

using std::string;

class Dictionary
{
    std::fstream f;
    string* str = new string[370105];

    public : Dictionary()
    {
        f.open("../src/words_alpha.txt", std::ios::in);

        if(!f.is_open())
        {}

        int i = 0;
        while(!f.eof())
        {
            f >> str[i];
            i++;
        }
        f.close();
    }

    bool checkDictionary(string search)
    {
        for(int i = 0; i<370105; i++)
        {
            if(search == *str)
            {
                return true;
            }
            str++;
        }
        return false;
    }
};