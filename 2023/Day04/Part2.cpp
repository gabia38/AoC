#include <bits/stdc++.h>

using namespace std;

int main()
{
    int rez = 0;
    string line;
    unordered_map<int, int> freq;

    while (getline(cin, line))
    {
        int poz1 = line.find(':');
        string card = line.substr(0, poz1);
        stringstream ssCard(card);

        int nr;
        ssCard >> card >> nr;

        freq[nr]++;
        rez += freq[nr];

        string numbers = line.substr(poz1 + 1);

        int poz2 = numbers.find('|');
        string winning = numbers.substr(0, poz2);
        stringstream ssWinning(winning);
        unordered_set<int> good;
        int x;

        while (ssWinning >> x)
        {
            good.insert(x);
        }

        string mine = numbers.substr(poz2 + 1);
        stringstream ssMine(mine);
        int matching = 0;

        while (ssMine >> x)
        {
            if (good.find(x) != good.end())
            {
                matching++;
            }
        }

        for (int i = nr + 1; i <= nr + matching; i++)
        {
            freq[i] += freq[nr];
        }
    }

    cout << rez;
    return 0;
}
