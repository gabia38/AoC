#include <bits/stdc++.h>

using namespace std;

int main()
{
    string instructions;
    getline(cin, instructions);
    cin.get();

    struct Node
    {
        string left, right;
    };

    unordered_map<string, Node> map;
    string line;
    vector<string> nodes;
    while (getline(cin, line))
    {
        Node node;
        string name;

        name = line.substr(0, 3);
        node.left = line.substr(line.find('(') + 1, 3);
        node.right = line.substr(line.find(',') + 2, 3);

        map[name] = node;

        if (name[2] == 'A')
        {
            nodes.push_back(name);
        }
    }

    int l = instructions.size();
    vector<long long> steps;
    for (string &node : nodes)
    {
        long long rez = 0;
        for (int i = 0; node[2] != 'Z';)
        {
            if (instructions[i] == 'L')
            {
                node = map[node].left;
            }
            else
            {
                node = map[node].right;
            }

            rez++;
            i = i < l - 1 ? i + 1 : 0;
        }

        steps.push_back(rez);
    }

    long long rez = 1;
    for (const int &step : steps)
    {
        rez = lcm(rez, step);
    }

    cout << rez;
    return 0;
}
