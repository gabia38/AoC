#include <bits/stdc++.h>

using namespace std;

int main()
{
    struct Corner
    {
        int row, col;

        bool operator<(const Corner &other) const
        {
            if (row != other.row)
            {
                return row < other.row;
            }

            return col < other.col;
        }
    };

    set<Corner> corners;
    int row, col;
    char separator;

    while (cin >> col >> separator >> row)
    {
        Corner corner;

        corner.col = col;
        corner.row = row;

        corners.insert(corner);
    }

    long long rez = 0;

    for (auto it1 = corners.begin(); it1 != corners.end(); it1++)
    {
        for (auto it2 = next(it1); it2 != corners.end(); it2++)
        {
            long long area = 1ll * (it2->row - it1->row + 1) * (abs(it1->col - it2->col) + 1);

            rez = max(rez, area);
        }
    }

    cout << rez;
    return 0;
}
