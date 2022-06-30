class Randomizer
{
    std::mt19937 random;
    std::string vowel = "EUIOA";
    std::string consonant = "QWRTYPSDFGHJKLZXCVBNM";

    public:
    Randomizer()
    {
        random.seed(time(NULL));
    }
    
    char getLetter()
    {
        return 'a' + random() % 26;
    }

    char getVowel()
    {
        return vowel[random() % 5];
    }

    char getConsonant()
    {
        return consonant[random() % 21];
    }

    char getPoin()
    {
        return random() % 10;
    }
};