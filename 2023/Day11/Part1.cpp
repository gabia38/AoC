#include <bits/stdc++.h>

using namespace std;

int main()
{
    struct Galaxy
    {
        int pozi, pozj;
    };

    vector<Galaxy> galaxies;
    vector<string> image;
    string line;
    unordered_set<int> extendedRows;

    int i = 0;
    while (getline(cin, line))
    {
        image.push_back(line);

        bool empty = true;
        int j = 0;
        for (const char &c : line)
        {
            if (c == '#')
            {
                Galaxy galaxy;

                galaxy.pozi = i;
                galaxy.pozj = j;

                galaxies.push_back(galaxy);
                empty = false;
            }

            j++;
        }

        if (empty)
        {
            extendedRows.insert(i);
        }

        i++;
    }

    unordered_set<int> extendedCols;

    int l = image[0].size();
    for (int j = 0; j < l; j++)
    {
        bool empty = true;
        for (int i = 0; i < image.size(); i++)
        {
            if (image[i][j] == '#')
            {
                empty = false;
                break;
            }
        }

        if (empty)
        {
            extendedCols.insert(j);
        }
    }

    int rez = 0;
    for (int i = 0; i < galaxies.size(); i++)
    {
        for (int j = i + 1; j < galaxies.size(); j++)
        {
            int local = abs(galaxies[i].pozi - galaxies[j].pozi) + abs(galaxies[i].pozj - galaxies[j].pozj);

            for (auto it : extendedCols)
            {
                if ((galaxies[i].pozj < it && it < galaxies[j].pozj) || (galaxies[j].pozj < it && it < galaxies[i].pozj))
                {
                    local++;
                }
            }
            for (auto it : extendedRows)
            {

                if ((galaxies[i].pozi < it && it < galaxies[j].pozi) || (galaxies[j].pozi < it && it < galaxies[i].pozi))
                {
                    local++;
                }
            }

            rez += local;
        }
    }

    cout << rez;
    return 0;
}
