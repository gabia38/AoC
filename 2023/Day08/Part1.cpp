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
    while (getline(cin, line))
    {
        Node node;
        string name;

        name = line.substr(0, 3);
        node.left = line.substr(line.find('(') + 1, 3);
        node.right = line.substr(line.find(',') + 2, 3);

        map[name] = node;
    }

    int rez = 0, l = instructions.size();
    string node = "AAA";
    for (int i = 0; node != "ZZZ";)
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

    cout << rez;
    return 0;
}
