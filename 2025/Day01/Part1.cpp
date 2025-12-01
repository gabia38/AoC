#include <bits/stdc++.h>

using namespace std;

int main()
{
    int nr = 50, rez = 0;
    string line;
    while (getline(cin, line))
    {
        int move = stoi(line.substr(1));
        nr = line[0] == 'L' ? ((nr - move) % 100 + 100) % 100 : (nr + move) % 100;

        if (nr == 0)
        {
            rez++;
        }
    }

    cout << rez;
    return 0;
}
