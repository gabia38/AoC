#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<string, vector<string>> adj;
    string source;

    while (cin >> source)
    {
        source = source.substr(0, 3);

        string dest;

        while (cin.peek() != '\n')
        {
            cin >> dest;

            adj[source].push_back(dest);
        }
    }

    unordered_map<string, int> freq;
    queue<string> bfs;
    bfs.push("you");
    freq["you"] = 1;

    while (!bfs.empty())
    {
        string s = bfs.front();

        bfs.pop();

        for (auto d : adj[s])
        {
            if (freq[d] == 0)
            {
                bfs.push(d);
            }

            freq[d] += freq[s];
        }
    }

    cout << freq["out"];
    return 0;
}
