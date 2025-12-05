#include <bits/stdc++.h>

using namespace std;

int main()
{
    struct Range
    {
        long long start, finish;

        bool operator<(const Range &other) const
        {
            if (start != other.start)
            {
                return start < other.start;
            }
            return finish < other.finish;
        }
    };

    set<Range> ranges;

    do
    {
        Range r;
        char c;
        cin >> r.start >> c >> r.finish;

        ranges.insert(r);

        cin.ignore();
    } while (cin.peek() != '\n');

    int rez = 0;
    long long id;

    while (cin >> id)
    {
        if (id >= ranges.begin()->start && id <= prev(ranges.end())->finish)
        {
            for (auto it : ranges)
            {
                if (id >= it.start && id <= it.finish)
                {
                    rez++;
                    break;
                }
            }
        }
    }

    cout << rez;
    return 0;
}
