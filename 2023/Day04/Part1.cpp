#include <bits/stdc++.h>

using namespace std;

int main()
{
    int rez = 0;
    string line;

    while (getline(cin, line))
    {
        int poz1 = line.find(':');
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
        int points = 0;

        while (ssMine >> x)
        {
            if (good.find(x) != good.end())
            {
                points = points == 0 ? 1 : points * 2;
            }
        }

        rez += points;
    }

    cout << rez;
    return 0;
}
