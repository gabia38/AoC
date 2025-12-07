#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<vector<long long>> room;
    string line;

    auto toVector = [](const string &line)
    {
        vector<long long> v;

        for (char c : line)
        {
            switch (c)
            {
            case '.':
            {
                v.push_back(0);
                break;
            }
            case '^':
            {
                v.push_back(-1);
                break;
            }
            case 'S':
            {
                v.push_back(-2);
                break;
            }
            }
        }

        return v;
    };

    while (getline(cin, line))
    {
        room.push_back(toVector(line));
    }

    int start, m = room[0].size();

    for (int i = 0; i < m; i++)
    {
        if (room[0][i] == -2)
        {
            start = i;
            room[1][i] = 1;
            break;
        }
    }

    int n = room.size(), finish = start + 1;

    for (int i = 1; i < n - 1; i += 2)
    {
        for (int j = start; j < finish; j++)
        {
            if (room[i][j] > 0)
            {
                if (room[i + 1][j] == -1)
                {
                    room[i + 1][j - 1] += room[i][j];
                    room[i + 1][j + 1] += room[i][j];
                    room[i + 2][j - 1] += room[i][j];
                    room[i + 2][j + 1] += room[i][j];
                }
                else
                {
                    room[i + 1][j] += room[i][j];
                    room[i + 2][j] += room[i][j];
                }
            }
        }

        start--;
        finish++;
    }

    long long rez = 0;

    for(int i = 0; i < m; i++)
    {
        rez+=room[n-1][i];
    }

    cout << rez;
    return 0;
}
