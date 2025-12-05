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

        bool change = false;

        for (auto it = ranges.begin(); it != ranges.end();)
        {
            Range cur = *it;
            if (cur.start <= r.start && cur.finish >= r.start && cur.finish <= r.finish)
            {
                cur.finish = r.finish;
                ranges.erase(it);
                ranges.insert(cur);
                change = true;
                break;
            }
            else if (cur.start >= r.start && r.finish >= cur.start && cur.finish >= r.finish)
            {
                cur.start = r.start;
                ranges.erase(it);
                ranges.insert(cur);
                change = true;
                break;
            }
            else if (cur.start >= r.start && cur.finish <= r.finish)
            {
                cur.start = r.start;
                cur.finish = r.finish;
                ranges.erase(it);
                ranges.insert(cur);
                change = true;
                break;
            }
            else if (cur.start <= r.start && cur.finish >= r.finish)
            {
                change = true;
                break;
            }
            it++;
        }

        if (!change)
        {
            ranges.insert(r);
        }

        cin.ignore();
    } while (cin.peek() != '\n');

    bool found;
    do
    {
        found = false;

        for (auto it1 = ranges.begin(); it1 != ranges.end();)
        {
            bool change = false;

            for (auto it2 = next(it1); it2 != ranges.end();)
            {
                Range cur = *it2;
                if (cur.start <= it1->start && cur.finish >= it1->start && cur.finish <= it1->finish)
                {
                    cur.finish = it1->finish;
                    ranges.erase(it2);
                    it1 = ranges.erase(it1);
                    ranges.insert(cur);
                    found = true;
                    change = true;
                    break;
                }
                else if (cur.start >= it1->start && it1->finish >= cur.start && cur.finish >= it1->finish)
                {
                    cur.start = it1->start;
                    ranges.erase(it2);
                    it1 = ranges.erase(it1);
                    ranges.insert(cur);
                    found = true;
                    change = true;
                    break;
                }
                else if (cur.start >= it1->start && cur.finish <= it1->finish)
                {
                    cur.start = it1->start;
                    cur.finish = it1->finish;
                    ranges.erase(it2);
                    it1 = ranges.erase(it1);
                    ranges.insert(cur);
                    found = true;
                    change = true;
                    break;
                }
                else if (cur.start <= it1->start && cur.finish >= it1->finish)
                {
                    found = true;
                    change = true;
                    break;
                }
                it2++;
            }

            if (!change)
            {
                it1++;
            }
        }
    } while (found);

    long long rez = 0;

    for (auto it : ranges)
    {
        rez += it.finish - it.start + 1;
    }

    cout << rez;
    return 0;
}
