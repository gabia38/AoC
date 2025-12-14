#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> joltage, const vector<vector<int>> &buttons, const int &n);
void construct(const vector<bool> &target, vector<bool> state, const vector<vector<int>> &buttons,
                const int &n, int poz, vector<vector<int>> &options, bool &exist, vector<int> option = {});

int main()
{
    string line;
    int rez = 0;

    while (getline(cin, line))
    {
        int n = line.size();
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

        i++;
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

        rez += solve(joltage, buttons, buttons.size());
    }

    cout << rez;
    return 0;
}

int solve(vector<int> joltage, const vector<vector<int>> &buttons, const int &n)
{
    bool done = true;
    for (auto it : joltage)
    {
        if (it != 0)
        {
            done = false;
        }
    }

    if (done)
    {
        return 0;
    }

    vector<bool> target(joltage.size());
    for (int i = 0; i < joltage.size(); i++)
    {
        joltage[i] % 2 ? target[i] = true : target[i] = false;
    }

    vector<bool> state(joltage.size());
    vector<vector<int>> options;

    bool exist = false;
    construct(target, state, buttons, n, 0, options, exist);

    if (!exist)
    {
        return 1000000;
    }

    int best = 1000000;
    for (auto it1 : options)
    {
        for (auto it2 : it1)
        {
            for (auto it3 : buttons[it2])
            {
                joltage[it3]--;
            }
        }

        bool nonNegatives = true;
        for (auto it2 : joltage)
        {
            if (it2 < 0)
            {
                nonNegatives = false;
            }
        }

        if (nonNegatives)
        {
            int div = 0;
            for (auto it2 : joltage)
            {
                div = gcd(div, it2);
            }

            for (auto &it2 : joltage)
            {
                it2 /= max(div, 1);
            }

            int posible = div * solve(joltage, buttons, n) + it1.size();
            best = min(best, posible);

            for (auto &it2 : joltage)
            {
                it2 *= div;
            }
        }

        for (auto it2 : it1)
        {
            for (auto it3 : buttons[it2])
            {
                joltage[it3]++;
            }
        }
    }

    return best;
}

void construct(const vector<bool> &target, vector<bool> state, const vector<vector<int>> &buttons,
                const int &n, int poz, vector<vector<int>> &options, bool &exist, vector<int> option)
{
    if (target == state)
    {
        exist = true;
        options.push_back(option);
    }

    for (int i = poz; i < n; i++)
    {
        for (auto it : buttons[i])
        {
            state[it] = !state[it];
        }

        option.push_back(i);

        construct(target, state, buttons, n, i + 1, options, exist, option);

        option.pop_back();

        for (auto it : buttons[i])
        {
            state[it] = !state[it];
        }
    }
}
