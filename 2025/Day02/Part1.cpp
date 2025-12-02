#include <bits/stdc++.h>

using namespace std;

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
            if (aux.substr(0, aux.size()/2) == aux.substr(aux.size()/2))
            {
                rez += i;
            }
        }
    } while (cin >> separator);

    cout << rez;
    return 0;
}
