#include <bits/stdc++.h>

using namespace std;

int main()
{
    int nr = 50, rez = 0;
    string line;
    while (getline(cin, line))
    {
        int move = stoi(line.substr(1));
        if (line[0] == 'R')
        {
            rez += (nr + move) / 100;
            nr = (nr + move) % 100;
        }
        else
        {
            if (move >= nr && nr != 0)
            {
                rez++;
                move -= nr;
                nr = 0;
            }

            rez += move / 100;
            nr = ((nr - move) % 100 + 100) % 100;
        }
    }

    cout << rez;
    return 0;
}
