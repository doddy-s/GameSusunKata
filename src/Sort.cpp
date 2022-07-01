void sortDescending(Score *score)
{
    Score temp;
    for (int i{}; i < 9; i++)
        for (int j{}; j < 9 - i; j++)
            if (score[j].score < score[j + 1].score)
            {
                temp = score[j];
                score[j] = score[j + 1];
                score[j + 1] = temp;
            }
}