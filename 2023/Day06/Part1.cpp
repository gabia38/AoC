#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    getline(cin, line);
    string times = line.substr(5);
    stringstream st(times);

    vector<int> time;
    int t;
    while (st >> t)
    {
        time.push_back(t);
    }

    getline(cin, line);
    string distances = line.substr(9);
    stringstream sd(distances);

    vector<int> distance;
    int d;
    while (sd >> d)
    {
        distance.push_back(d);
    }

    int rez = 1;
    for (int i = 0; i < time.size(); i++)
    {
        int ways = 0;
        for (int j = 1; j < time[i]; j++)
        {
            if ((time[i] - j) * j > distance[i])
            {
                ways++;
            }
        }

        rez *= ways;
    }

    cout << rez;
    return 0;
}
