#include <iostream>
#include <map>
using namespace std;
int x,y,z,v[25],s,k;
char c;
int verificare(multimap<int,int>& rezmap, int v[],int k);
int rezolvare(multimap<int,int>& rezmap, int v[],int k);
int main()
{
    multimap<int, int> rezmap;
    while(cin>>x>>c>>y)
    {
        if(c!='|')
            break;
        rezmap.insert({x,y});
    }
    v[k++]=x;
    v[k++]=y;
    while(true)
    {
        if(cin.peek()==',')
            cin.ignore();
        else if(cin.peek()=='\n'||cin.peek()==EOF)
        {
            cin.ignore();
            if(k>0 && verificare(rezmap,v,k))
                s+=rezolvare(rezmap,v,k);
            k=0;
            if(cin.peek()==EOF)
                break;
        }
        else
            cin>>v[k++];
    }
    cout<<s;

    return 0;
}
int verificare(multimap<int,int>& rezmap, int v[],int k)
{
    for(int i=0; i<k; i++)
    {
        auto range=rezmap.equal_range(v[i]);
        for(auto x=range.first; x!=range.second; x++)
        {
            int tr=x->second;
            for(int j=0; j<i; j++)
                if(tr==v[j])
                    return 1;
        }
    }
    return 0;
}
int rezolvare(multimap<int,int>& rezmap, int v[],int k)
{
    int ok=1;
    while(ok)
    {
        ok=0;
        for(int i=0; i<k; i++)
        {
            auto range=rezmap.equal_range(v[i]);
            for(auto x=range.first; x!=range.second; x++)
            {
                int tr=x->second;
                for(int j=0; j<i; j++)
                    if(tr==v[j])
                    {
                        swap(v[j],v[i]);
                        ok=1;
                    }
            }
        }
    }
    return v[k/2];
}
