#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<string>> patterns(6);

    for (int i = 0; i < 6; i++)
    {
        string line;
        cin >> line;
        cin.get();

        for (int j = 0; j < 3; j++)
        {
            getline(cin, line);
            patterns[i].push_back(line);
        }
    }

    int x, y;
    char separator;

    int rez = 0;

    while (cin >> x >> separator >> y >> separator)
    {
        int totalSpace = x * y;

        int neededSpace = 0;

        for (int i = 0; i < 6; i++)
        {
            int nr;
            cin >> nr;

            neededSpace += 9 * nr;
        }

        if (neededSpace <= totalSpace)
        {
            rez++;
        }
    }

    cout << rez;
    return 0;
}
