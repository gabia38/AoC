#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    getline(cin, line);
    string seeds = line.substr(6);
    stringstream ss(seeds);

    struct Range
    {
        long long start, end;

        bool operator<(const Range &other) const
        {
            if (start != other.start)
            {
                return start < other.start;
            }

            return end < other.end;
        }
    };

    set<Range> numbers;
    long long start, len;
    while (ss >> start >> len)
    {
        Range range;

        range.start = start;
        range.end = start + len;

        numbers.insert(range);
    }

    set<Range> change = numbers;
    while (getline(cin, line))
    {
        if (line.empty())
        {
            numbers = change;
            getline(cin, line);
            continue;
        }

        stringstream ss(line);
        long long destination, source, range;
        ss >> destination >> source >> range;
        set<Range> aux = numbers;
        for (auto &it : aux)
        {
            Range neew;

            if (source <= it.start && it.end <= source + range)
            {
                neew.start = destination + it.start - source;
                neew.end = min(destination + it.end - source, destination + range);

                change.insert(neew);
                change.erase(it);
                numbers.erase(it);
            }
            else if (source <= it.start && it.start < source + range && source + range < it.end)
            {
                Range neew;

                neew.start = destination + it.start - source;
                neew.end = destination + range;

                change.insert(neew);

                Range neew2;

                neew2.start = source + range;
                neew2.end = it.end;

                change.insert(neew2);
                numbers.insert(neew2);

                change.erase(it);
                numbers.erase(it);
            }
            else if (it.start < source && source < it.end && it.end <= source + range)
            {
                neew.start = destination;
                neew.end = destination + it.end - source;

                change.insert(neew);

                Range neew2;

                neew2.start = it.start;
                neew2.end = source;

                change.insert(neew2);
                numbers.insert(neew2);

                change.erase(it);
                numbers.erase(it);
            }
            else if (it.start < source && it.end > source + range)
            {
                Range neew;

                neew.start = destination;
                neew.end = destination + range;

                change.insert(neew);

                Range neew2;

                neew2.start = it.start;
                neew2.end = source;

                change.insert(neew2);
                numbers.insert(neew2);

                Range neew3;

                neew3.start = it.end;
                neew3.end = source + range;

                change.insert(neew3);
                numbers.insert(neew3);

                change.erase(it);
                numbers.erase(it);
            }
        }
    }

    numbers = change;

    cout << numbers.begin()->start;
    return 0;
}
