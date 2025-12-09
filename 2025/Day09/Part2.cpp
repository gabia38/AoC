#include <bits/stdc++.h>

using namespace std;

struct Point
{
    int row, col;

    bool operator<(const Point &other) const
    {
        if (row != other.row)
        {
            return row < other.row;
        }

        return col < other.col;
    }
};

bool validRectangle(const Point &a, const Point &b, const map<int, pair<int, int>> &rowInterval, const map<int, pair<int, int>> &colInterval);
bool goodPoint(const Point &p, const map<int, pair<int, int>> &rowInterval, const map<int, pair<int, int>> &colInterval);

int main()
{
    vector<Point> points;
    int row, col;
    char separator;

    cin >> col >> separator >> row;

    Point point;

    point.col = col;
    point.row = row;

    points.push_back(point);

    map<int, pair<int, int>> rowInterval, colInterval;

    for (int i = 1; cin >> col >> separator >> row; i++)
    {
        Point point;

        point.col = col;
        point.row = row;

        if (col == points[i - 1].col)
        {
            for (int j = min(row, points[i - 1].row); j <= max(row, points[i - 1].row); j++)
            {
                if (rowInterval.find(j) == rowInterval.end())
                {
                    rowInterval[j].first = col;
                    rowInterval[j].second = col;
                }
                else
                {
                    rowInterval[j].first = min(rowInterval[j].first, col);
                    rowInterval[j].second = max(rowInterval[j].second, col);
                }
            }
        }
        else
        {
            for (int j = min(col, points[i - 1].col); j <= max(col, points[i - 1].col); j++)
            {
                if (colInterval.find(j) == colInterval.end())
                {
                    colInterval[j].first = row;
                    colInterval[j].second = row;
                }
                else
                {
                    colInterval[j].first = min(colInterval[j].first, row);
                    colInterval[j].second = max(colInterval[j].second, row);
                }
            }
        }

        points.push_back(point);
    }

    int n = points.size();

    if (points[0].col == points[n - 1].col)
    {
        for (int j = min(points[0].row, points[n - 1].row); j <= max(points[0].row, points[n - 1].row); j++)
        {
            rowInterval[j].first = min(rowInterval[j].first, points[0].col);
            rowInterval[j].second = max(rowInterval[j].second, points[0].col);
        }
    }
    else
    {
        for (int j = min(points[0].col, points[n - 1].col); j <= max(points[0].col, points[n - 1].col); j++)
        {
            colInterval[j].first = min(colInterval[j].first, points[0].row);
            colInterval[j].second = max(colInterval[j].second, points[0].row);
        }
    }

    sort(points.begin(), points.end());

    long long rez = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long long area = 1ll * (points[j].row - points[i].row + 1) * (abs(points[i].col - points[j].col) + 1);

            if (area > rez && validRectangle(points[i], points[j], rowInterval, colInterval))
            {
                rez = max(rez, area);
            }
        }
    }

    cout << rez;
    return 0;
}

bool validRectangle(const Point &a, const Point &b, const map<int, pair<int, int>> &rowInterval, const map<int, pair<int, int>> &colInterval)
{
    for (int i = a.row; i <= b.row; i++)
    {
        Point p1, p2;

        p1.row = i;
        p1.col = a.col;
        p2.row = i;
        p2.col = b.col;

        if (!goodPoint(p1, rowInterval, colInterval) || !goodPoint(p2, rowInterval, colInterval))
        {
            return false;
        }
    }

    for (int j = min(a.col, b.col); j <= max(a.col, b.col); j++)
    {
        Point p1, p2;

        p1.row = a.row;
        p1.col = j;
        p2.row = b.row;
        p2.col = j;

        if (!goodPoint(p1, rowInterval, colInterval) || !goodPoint(p2, rowInterval, colInterval))
        {
            return false;
        }
    }

    return true;
}

bool goodPoint(const Point &p, const map<int, pair<int, int>> &rowInterval, const map<int, pair<int, int>> &colInterval)
{
    bool valid = false;

    if (p.row >= colInterval.at(p.col).first && p.row <= colInterval.at(p.col).second)
    {
        valid = true;
    }

    if (!valid)
    {
        return false;
    }

    return (p.col >= rowInterval.at(p.row).first && p.col <= rowInterval.at(p.row).second);
}
