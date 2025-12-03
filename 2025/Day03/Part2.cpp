#include <bits/stdc++.h>

using namespace std;

void findmaxi(const string &line, string &maxi, int i, int poz, int l);

int main()
{
    string line;
    long long rez = 0;

    while (getline(cin, line))
    {
        string maxi = "";
        findmaxi(line, maxi, 0, 0, line.size());

        rez += stoll(maxi);
    }

    cout << rez;
    return 0;
}

void findmaxi(const string &line, string &maxi, int i, int poz, int l)
{
    if (poz == 12)
    {
        return;
    }

    int maxim = 0, pozi;
    for (; i < l - 12 + poz + 1; i++)
    {
        if (line[i] - '0' > maxim)
        {
            maxim = line[i] - '0';
            pozi = i;
        }
    }

    maxi += to_string(maxim);

    findmaxi(line, maxi, pozi + 1, poz + 1, l);
}
