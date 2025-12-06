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
    vector<int> js(n - 1, nums[0].size() - 1);

    for (int i = nums[n - 1].size() - 1; i >= 0; i--)
    {
        char c = nums[n - 1][i];

        if (c == '+')
        {
            int nr = 0;

            while (true)
            {
                int operand = 0;

                for (int j = 0; j < n - 1; j++)
                {
                    if (js[j] >= 0 && nums[j][js[j]] != ' ')
                    {
                        operand = operand * 10 + nums[j][js[j]] - '0';
                    }
                }

                for (int j = 0; j < n - 1; j++)
                {
                    js[j]--;
                }

                if (operand == 0)
                {
                    break;
                }

                nr += operand;
            }

            rez += nr;
        }
        else if (c == '*')
        {
            long long nr = 1;

            while (true)
            {
                int operand = 0;

                for (int j = 0; j < n - 1; j++)
                {
                    if (js[j] >= 0 && nums[j][js[j]] != ' ')
                    {
                        operand = operand * 10 + nums[j][js[j]] - '0';
                    }
                }

                for (int j = 0; j < n - 1; j++)
                {
                    js[j]--;
                }

                if (operand == 0)
                {
                    break;
                }

                nr *= operand;
            }

            rez += nr;
        }
    }

    cout << rez;
    return 0;
}
