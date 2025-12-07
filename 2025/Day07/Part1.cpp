#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<string> room;
    string line;

    while (getline(cin, line))
    {
        room.push_back(line);
    }

    int start, m = room[0].size();

    for (int i = 0; i < m; i++)
    {
        if (room[0][i] == 'S')
        {
            start = i;
            room[1][i] = '|';
            break;
        }
    }

    int rez = 0, n = room.size(), finish = start + 1;

    for (int i = 1; i < n - 1; i += 2)
    {
        for (int j = start; j < finish; j++)
        {
            if (room[i][j] == '|')
            {
                if (room[i + 1][j] == '^')
                {
                    room[i + 1][j - 1] = '|';
                    room[i + 1][j + 1] = '|';
                    room[i + 2][j - 1] = '|';
                    room[i + 2][j + 1] = '|';

                    rez++;
                }
                else
                {
                    room[i + 1][j] = '|';
                    room[i + 2][j] = '|';
                }
            }
        }

        start--;
        finish++;
    }

    cout << rez;
    return 0;
}
