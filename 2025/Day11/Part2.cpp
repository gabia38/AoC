#include <bits/stdc++.h>

using namespace std;

long long solve(const string &source, const string &destination, unordered_map<string, vector<string>> &adj, unordered_map<string, long long> &freq);

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

    unordered_map<string, long long> freq;
    long long nr1 = solve("svr", "fft", adj, freq);

    freq = unordered_map<string, long long>();
    long long nr2 = solve("fft", "dac", adj, freq);

    freq = unordered_map<string, long long>();
    long long nr3 = solve("dac", "out", adj, freq);

    cout << nr1 * nr2 * nr3;
    return 0;
}

long long solve(const string &source, const string &destination, unordered_map<string, vector<string>> &adj, unordered_map<string, long long> &freq)
{
    if (source == destination)
    {
        return 1;
    }

    long long rez = 0;

    for (auto it : adj[source])
    {
        if (freq.find(it) == freq.end())
        {
            freq[it] = -1;
        }

        if (freq[it] > -1)
        {
            rez += freq[it];
            continue;
        }

        rez += solve(it, destination, adj, freq);
    }

    return freq[source] = rez;
}
