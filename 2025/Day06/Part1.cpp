#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<string> nums;
    string line;

    while (getline(cin, line))
    {
        nums.push_back(line);
    }

    long long rez = 0;
    int n = nums.size();
    vector<int> js(n - 1);
    int l = nums[0].size();
    
    for (char c : nums[n - 1])
    {
        if (c == '+')
        {
            int nr = 0;
            for (int i = 0; i < n - 1; i++)
            {
                int operand = 0;

                while (js[i] < l && nums[i][js[i]] == ' ')
                {
                    js[i]++;
                }

                while (js[i] < l && nums[i][js[i]] != ' ')
                {
                    operand = operand * 10 + nums[i][js[i]] - '0';
                    js[i]++;
                }

                nr += operand;
            }

            rez += nr;
        }
        else if (c == '*')
        {
            long long nr = 1;
            for (int i = 0; i < n - 1; i++)
            {
                int operand = 0;

                while (js[i] < l && nums[i][js[i]] == ' ')
                {
                    js[i]++;
                }

                while (js[i] < l && nums[i][js[i]] != ' ')
                {
                    operand = operand * 10 + nums[i][js[i]] - '0';
                    js[i]++;
                }

                nr *= operand;
            }

            rez += nr;
        }
    }

    cout << rez;
    return 0;
}
