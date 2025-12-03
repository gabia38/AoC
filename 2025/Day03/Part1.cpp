#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    int rez = 0;

    while (getline(cin, line))
    {
        int max1 = 0, max2 = 0, poz1, poz2, l = line.size();

        for (int i = 0; i < l; i++)
        {
            if (line[i] - '0' > max1)
            {
                max2 = max1;
                max1 = line[i] - '0';
                poz2 = poz1;
                poz1 = i;
            }
            else if (line[i] - '0' > max2)
            {
                max2 = line[i] - '0';
                poz2 = i;
            }
        }

        if (poz1 != l - 1)
        {
            int maxi = 0;

            for (int i = poz1 + 1; i < l; i++)
            {
                maxi = max(maxi, line[i] - '0');
            }

            rez += max1 * 10 + maxi;
        }
        else
        {
            int maxi = 0;

            for (int i = poz2 + 1; i < l; i++)
            {
                maxi = max(maxi, line[i] - '0');
            }

            rez += max2 * 10 + maxi;
        }
    }

    cout << rez;
    return 0;
}
