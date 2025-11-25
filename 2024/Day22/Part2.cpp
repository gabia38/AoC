#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    map<vector<int>,int> rez;
    map<vector<int>,set<unsigned long long>>visited;
    unsigned long long x;
    while(cin>>x)
    {
        vector<int> pattern= {0,0,0,0};
        unsigned long long nr=x;
        for(int i=0; i<2000; i++)
        {
            int aux=x%10;
            x=(x^(x*64))%16777216;
            x=(x^(x/32))%16777216;
            x=(x^(x*2048))%16777216;
            if(i<3)
                pattern[i]=x%10-aux;
            else
            {
                if(i>3)
                    for(int j=0; j<3; j++)
                        pattern[j]=pattern[j+1];
                pattern[3]=x%10-aux;
                if(visited[pattern].find(nr)==visited[pattern].end())
                {
                    visited[pattern].insert(nr);
                    if(rez.find(pattern)!=rez.end())
                        rez[pattern]+=x%10;
                    else
                        rez[pattern]=x%10;
                }
            }
        }
    }
    int smax=0;
    for(auto entry : rez)
        if(entry.second>smax)
            smax=entry.second;
    cout<<smax;
    return 0;
}
