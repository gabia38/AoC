#include <bits/stdc++.h>

using namespace std;

int main()
{
    int rez = 0;
    string line;

    while (getline(cin, line))
    {
        unordered_map<string, int> freq;
        int poz = line.find(':');
        int id = stoi(line.substr(5, poz - 5));

        string rest = line.substr(poz + 1), set;
        stringstream sets(rest);

        while (getline(sets, set, ';'))
        {
            string item;
            stringstream items(set);

            while (getline(items, item, ','))
            {
                stringstream ss(item);
                int nr;
                string color;

                ss >> nr >> color;

                freq[color] = max(freq[color], nr);
            }
        }

        rez += freq["red"] * freq["green"] * freq["blue"];
    }

    cout << rez;
    return 0;
}
