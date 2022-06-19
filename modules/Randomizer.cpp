class Randomizer
{
    std::mt19937 random;

    public:
    Randomizer()
    {
        random.seed(time(NULL));
    }
    
    char getLetter()
    {
        return 'a' + random() % 26;
    }

    char getPoin()
    {
        return random() % 10;
    }
};