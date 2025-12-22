#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    getline(cin, line);
    string seeds = line.substr(6);
    stringstream ss(seeds);

    vector<unsigned int> numbers;
    unsigned int nr;
    while (ss >> nr)
    {
        numbers.push_back(nr);
    }

    vector<unsigned int> change = numbers;
    while (getline(cin, line))
    {
        if (line.empty())
        {
            numbers = change;
            getline(cin, line);
            continue;
        }

        stringstream ss(line);
        unsigned int destination, source, range;
        ss >> destination >> source >> range;
        for (unsigned int i = 0; i < numbers.size(); i++)
        {
            if (source <= numbers[i] && numbers[i] - source < range)
            {
                change[i] = destination + numbers[i] - source;
            }
        }
    }

    numbers = change;

    unsigned int mini = numbers[0];
    for (const unsigned int &nr : numbers)
    {
        mini = min(mini, nr);
    }

    cout << mini;
    return 0;
}
