#include <bits/stdc++.h>

using namespace std;

int main()
{
    struct Edge
    {
        int row, col;

        bool operator<(const Edge &other) const
        {
            if (row != other.row)
            {
                return row < other.row;
            }

            return col < other.col;
        }
    };

    set<Edge> edges;
    int row, col;
    char separator;

    while (cin >> col >> separator >> row)
    {
        Edge edge;

        edge.col = col;
        edge.row = row;

        edges.insert(edge);
    }

    long long rez = 0;

    for (auto it1 = edges.begin(); it1 != edges.end(); it1++)
    {
        for (auto it2 = next(it1); it2 != edges.end(); it2++)
        {
            long long area = 1ll * (it2->row - it1->row + 1) * (abs(it1->col - it2->col) + 1);

            rez = max(rez, area);
        }
    }

    cout << rez;
    return 0;
}
