#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> grid;
    string line;

    while (getline(cin, line))
    {
        grid.push_back(line);
    }

    int n = grid[0].size(), m = grid.size(), rez = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(grid[i][j] == '.')
            {
                continue;
            }

            int nr = 0;

            if (i > 0 && grid[i - 1][j] == '@')
            {
                nr++;
            }
            if (i > 0 && j < n - 1 && grid[i - 1][j + 1] == '@')
            {
                nr++;
            }
            if (j < n - 1 && grid[i][j + 1] == '@')
            {
                nr++;
            }
            if (i < n - 1 && j < n - 1 && grid[i + 1][j + 1] == '@')
            {
                nr++;
            }
            if (i < n - 1 && grid[i + 1][j] == '@')
            {
                nr++;
            }
            if (i < n - 1 && j > 0 && grid[i + 1][j - 1] == '@')
            {
                nr++;
            }
            if (j > 0 && grid[i][j - 1] == '@')
            {
                nr++;
            }
            if (i > 0 && j > 0 && grid[i - 1][j - 1] == '@')
            {
                nr++;
            }

            if (nr < 4)
            {
                rez++;
            }
        }
    }

    cout << rez;
    return 0;
}
