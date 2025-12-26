#include <bits/stdc++.h>

using namespace std;

int solve(const vector<int> &values);

int main()
{
    string history;
    int rez = 0;

    while (getline(cin, history))
    {
        stringstream ss(history);
        vector<int> values;
        int value;

        while (ss >> value)
        {
            values.push_back(value);
        }

        rez += solve(values);
    }

    cout << rez;
    return 0;
}

int solve(const vector<int> &values)
{
    bool allEqual = true;
    for (auto value : values)
    {
        if (value != values[0])
        {
            allEqual = false;
        }
    }

    if (allEqual)
    {
        return values[0];
    }

    vector<int> newValues;
    for (int i = 1; i < values.size(); i++)
    {
        newValues.push_back(values[i] - values[i - 1]);
    }

    return values[values.size() - 1] + solve(newValues);
}
