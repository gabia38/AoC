#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    getline(cin, line);
    string times = line.substr(5);
    stringstream st(times);

    string stime, t;
    while (st >> t)
    {
        stime += t;
    }

    int time = stoi(stime);

    getline(cin, line);
    string distances = line.substr(9);
    stringstream sd(distances);

    string sdistance, d;
    while (sd >> d)
    {
        sdistance += d;
    }

    long long distance = stoll(sdistance);

    int rez = 0;
    for (int i = 1; i < time; i++)
    {
        if (1ll * i * (time - i) > distance)
        {
            rez++;
        }
    }

    cout << rez;
    return 0;
}
