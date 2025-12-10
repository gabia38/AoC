#include <bits/stdc++.h>

using namespace std;

void solve(const vector<bool> &target, vector<bool> state, const vector<vector<int>> &buttons, int n, int poz, int k, int &best);

int main()
{
    string line;
    int n = line.size(), rez = 0;

    while (getline(cin, line))
    {
        vector<bool> target;
        vector<vector<int>> buttons;

        int i = 1;
        while (line[i] != ']')
        {
            line[i] == '.' ? target.push_back(false) : target.push_back(true);
            i++;
        }

        i += 2;
        while (line[i] != '{')
        {
            vector<int> option;
            while (line[i] != ')')
            {
                if (isdigit(line[i]))
                {
                    option.push_back(line[i] - '0');
                }
                i++;
            }

            buttons.push_back(option);
            i += 2;
        }

        vector<int> joltage;

        while (i < n)
        {
            int nr = 0;

            while (line[i] != ',' && line[i] != '}')
            {
                nr = nr * 10 + line[i] - '0';
                i++;
            }

            joltage.push_back(nr);
            i++;
        }

        vector<bool> state(target.size());
        int best = INT_MAX;

        solve(target, state, buttons, buttons.size(), 0, 0, best);

        rez += best;
    }

    cout << rez;
    return 0;
}

void solve(const vector<bool> &target, vector<bool> state, const vector<vector<int>> &buttons, int n, int poz, int k, int &best)
{
    if (k > best)
    {
        return;
    }

    if (target == state)
    {
        best = min(best, k);
        return;
    }

    for (int i = poz; i < n; i++)
    {
        for (auto it : buttons[i])
        {
            state[it] = !state[it];
        }

        solve(target, state, buttons, n, poz + 1, k + 1, best);

        for (auto it : buttons[i])
        {
            state[it] = !state[it];
        }
    }
}
