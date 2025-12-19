#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> schematic;
    string line;

    while (getline(cin, line))
    {
        schematic.push_back(line);
    }

    int l = schematic[0].size();
    int rez = 0;
    for (int i = 0; i < schematic.size(); i++)
    {
        for (int j = 0; j < l; j++)
        {
            if (schematic[i][j] == '*')
            {
                int local = 1, k = 0;
                if (j < l - 1 && isdigit(schematic[i][j + 1]))
                {
                    int nr = 0;

                    int aux = j + 1;
                    while (aux < l && isdigit(schematic[i][aux]))
                    {
                        nr = nr * 10 + schematic[i][aux] - '0';
                        schematic[i][aux] = '.';
                        aux++;
                    }

                    local *= nr;
                    k++;
                }

                if (i < schematic.size() - 1 && j < l - 1 && isdigit(schematic[i + 1][j + 1]))
                {
                    int aux = j + 1;
                    while (aux >= 0 && isdigit(schematic[i + 1][aux]))
                    {
                        aux--;
                    }

                    int nr = 0;

                    aux++;
                    while (aux < l && isdigit(schematic[i + 1][aux]))
                    {
                        nr = nr * 10 + schematic[i + 1][aux] - '0';
                        schematic[i + 1][aux] = '.';
                        aux++;
                    }

                    local *= nr;
                    k++;
                }

                if (i < schematic.size() - 1 && isdigit(schematic[i + 1][j]))
                {
                    int aux = j;
                    while (aux >= 0 && isdigit(schematic[i + 1][aux]))
                    {
                        aux--;
                    }

                    int nr = 0;

                    aux++;
                    while (aux < l && isdigit(schematic[i + 1][aux]))
                    {
                        nr = nr * 10 + schematic[i + 1][aux] - '0';
                        schematic[i + 1][aux] = '.';
                        aux++;
                    }

                    local *= nr;
                    k++;
                }

                if (i < schematic.size() - 1 && j > 0 && isdigit(schematic[i + 1][j - 1]))
                {
                    int aux = j - 1;
                    while (aux >= 0 && isdigit(schematic[i + 1][aux]))
                    {
                        aux--;
                    }

                    int nr = 0;

                    aux++;
                    while (aux < l && isdigit(schematic[i + 1][aux]))
                    {
                        nr = nr * 10 + schematic[i + 1][aux] - '0';
                        schematic[i + 1][aux] = '.';
                        aux++;
                    }

                    local *= nr;
                    k++;
                }

                if (j > 0 && isdigit(schematic[i][j - 1]))
                {
                    int aux = j - 1;
                    while (aux >= 0 && isdigit(schematic[i][aux]))
                    {
                        aux--;
                    }

                    int nr = 0;

                    aux++;
                    while (aux < l && isdigit(schematic[i][aux]))
                    {
                        nr = nr * 10 + schematic[i][aux] - '0';
                        schematic[i][aux] = '.';
                        aux++;
                    }

                    local *= nr;
                    k++;
                }

                if (i > 0 && j > 0 && isdigit(schematic[i - 1][j - 1]))
                {
                    int aux = j - 1;
                    while (aux >= 0 && isdigit(schematic[i - 1][aux]))
                    {
                        aux--;
                    }

                    int nr = 0;

                    aux++;
                    while (aux < l && isdigit(schematic[i - 1][aux]))
                    {
                        nr = nr * 10 + schematic[i - 1][aux] - '0';
                        schematic[i - 1][aux] = '.';
                        aux++;
                    }

                    local *= nr;
                    k++;
                }

                if (i > 0 && isdigit(schematic[i - 1][j]))
                {
                    int aux = j;
                    while (aux >= 0 && isdigit(schematic[i - 1][aux]))
                    {
                        aux--;
                    }

                    int nr = 0;

                    aux++;
                    while (aux < l && isdigit(schematic[i - 1][aux]))
                    {
                        nr = nr * 10 + schematic[i - 1][aux] - '0';
                        schematic[i - 1][aux] = '.';
                        aux++;
                    }

                    local *= nr;
                    k++;
                }

                if (i > 0 && j < l - 1 && isdigit(schematic[i - 1][j + 1]))
                {
                    int aux = j + 1;
                    while (aux >= 0 && isdigit(schematic[i - 1][aux]))
                    {
                        aux--;
                    }

                    int nr = 0;

                    aux++;
                    while (aux < l && isdigit(schematic[i - 1][aux]))
                    {
                        nr = nr * 10 + schematic[i - 1][aux] - '0';
                        schematic[i - 1][aux] = '.';
                        aux++;
                    }

                    local *= nr;
                    k++;
                }

                if (k == 2)
                {
                    rez += local;
                }
            }
        }
    }

    cout << rez;
    return 0;
}
