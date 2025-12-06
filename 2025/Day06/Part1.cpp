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
    vector<int> limits(n - 1);

    for (int i = 0; i < n - 1; i++)
    {
        limits[i] = nums[i].size();
    }

    for (char c : nums[n - 1])
    {
        if (c == '+')
        {
            int nr = 0;
            for (int i = 0; i < n - 1; i++)
            {
                int operand = 0;

                while (js[i] < limits[i] && nums[i][js[i]] == ' ')
                {
                    js[i]++;
                }

                while (js[i] < limits[i] && nums[i][js[i]] != ' ')
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

                while (js[i] < limits[i] && nums[i][js[i]] == ' ')
                {
                    js[i]++;
                }

                while (js[i] < limits[i] && nums[i][js[i]] != ' ')
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
