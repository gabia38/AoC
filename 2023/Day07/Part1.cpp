#include <bits/stdc++.h>

using namespace std;

int main()
{
    struct Hand
    {
        string combo;
        int bid, power;

        void computePower()
        {
            map<char, int> freq;

            for (const char &c : combo)
            {
                freq[c]++;
            }

            if (freq.size() == 1)
            {
                power = 6;
            }
            else if (freq.size() == 2)
            {
                power = freq.begin()->second == 4 || freq.begin()->second == 1 ? 5 : 4;
            }
            else if (freq.size() == 3)
            {
                bool three = false;
                for (auto it : freq)
                {
                    if (it.second == 3)
                    {
                        three = true;
                        break;
                    }
                }

                power = three ? 3 : 2;
            }
            else if (freq.size() == 4)
            {
                power = 1;
            }
            else
            {
                power = 0;
            }
        }
        bool operator<(const Hand &other) const
        {
            if (power != other.power)
            {
                return power < other.power;
            }

            unordered_map<char, int> strength = {{'A', 12}, {'K', 11}, {'Q', 10}, {'J', 9}, {'T', 8}, {'9', 7},
                                        {'8', 6}, {'7', 5}, {'6', 4}, {'5', 3}, {'4', 2}, {'3', 1}, {'2', 0}};
            for (int i = 0; i < 5; i++)
            {
                if (strength[combo[i]] != strength[other.combo[i]])
                {
                    return strength[combo[i]] < strength[other.combo[i]];
                }
            }

            return bid < other.bid;
        }
    };

    set<Hand> hands;

    string combo;
    int bid;
    while (cin >> combo >> bid)
    {
        Hand hand;

        hand.combo = combo;
        hand.bid = bid;
        hand.computePower();

        hands.insert(hand);
    }

    int i = 1;
    long long rez = 0;
    for (auto it : hands)
    {
        rez += it.bid * i;
        i++;
    }

    cout << rez;
    return 0;
}
