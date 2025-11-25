#include <bits/stdc++.h>

using namespace std;

int main()
{
    int rez=0;
    string line;
    while(getline(cin,line))
    {
        int nr=0;
        for(auto c:line)
        {
            if(isdigit(c))
            {
                nr+=(c-'0')*10;
                break;
            }
        }
        for(int i=line.size()-1;i>=0;i--)
        {
            if(isdigit(line[i]))
            {
                nr+=line[i]-'0';
                break;
            }
        }
        rez+=nr;
    }
    cout<<rez;
    return 0;
}
