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
            unordered_map<char, int> freq;

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
                if (freq.begin()->second == 4 || freq.begin()->second == 1)
                {
                    power = freq['J'] > 0 ? 6 : 5;
                }
                else
                {
                    power = freq['J'] > 0 ? 6 : 4;
                }
            }
            else if (freq.size() == 3)
            {
                bool three = false;
                for (auto it : freq)
                {
                    if (it.second == 3)
                    {
                        three = true;
                    }
                }

                if (three)
                {
                    power = freq['J'] > 0 ? 5 : 3;
                }
                else
                {
                    if (freq['J'] == 2)
                    {
                        power = 5;
                    }
                    else if (freq['J'] == 1)
                    {
                        power = 4;
                    }
                    else
                    {
                        power = 2;
                    }
                }
            }
            else if (freq.size() == 4)
            {
                power = freq['J'] > 0 ? 3 : 1;
            }
            else
            {
                power = freq['J'] > 0 ? 1 : 0;
            }
        }
        bool operator<(const Hand &other) const
        {
            if (power != other.power)
            {
                return power < other.power;
            }

            unordered_map<char, int> strength = {{'A', 12}, {'K', 11}, {'Q', 10}, {'T', 9}, {'9', 8}, {'8', 7}, 
                                        {'7', 6}, {'6', 5}, {'5', 4}, {'4', 3}, {'3', 2}, {'2', 1}, {'J', 0}};
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

    int i = 1, rez = 0;
    for (auto it : hands)
    {
        rez += it.bid * i;
        i++;
    }

    cout << rez;
    return 0;
}
