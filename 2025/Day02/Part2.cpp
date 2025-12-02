#include <bits/stdc++.h>

using namespace std;

bool valid(string s);

int main()
{
    long long start, finish;
    char separator;
    long long rez = 0;

    do
    {
        cin >> start >> separator >> finish;

        long long i = start;

        for (; i <= finish; i++)
        {
            string aux = to_string(i);
            if (valid(aux))
            {
                rez += i;
            }
        }
    } while (cin >> separator);

    cout << rez;
    return 0;
}

bool valid(string s)
{
    int l = s.size();

    for (int i = 1; i <= l / 2; i++)
    {
        string first = s.substr(0, i);
        bool good = true;

        for (int j = i; j < l; j += i)
        {
            if (first != s.substr(j, i))
            {
                good = false;
            }
        }

        if (good)
        {
            return true;
        }
    }

    return false;
}
