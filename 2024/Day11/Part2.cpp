#include <iostream>
#include <map>
using namespace std;
#define  ull unsigned long  long
bool evendig(ull x,int &k);
void split(ull x,ull &nr1,ull &nr2,int k);
int main()
{
    map<ull,ull> rez;
    ull x;
    while(cin>>x)
        rez[x]++;
    int nrdig=0;
    for(int i=0; i<75; i++)
    {
        map<ull,ull> temp;
        for(auto it:rez)
        {
            if(it.first==0)
            {

                temp[1]+=it.second;
            }
            else if(evendig(it.first,nrdig))
            {
                ull y;
                split(it.first,x,y,nrdig);
                temp[x]+=it.second;
                temp[y]+=it.second;
            }
            else
            {
                temp[it.first*2024]+=it.second;
            }
            nrdig=0;
        }
        rez=temp;
    }
    ull  total=0;
    for(auto it:rez)
    {
        total+=it.second;
    }
    cout<<total;
    return 0;
}
bool evendig(ull x,int &k)
{
    while(x)
    {
        k++;
        x/=10;
    }
    return k%2==0;
}
void split(ull x,ull &nr1, ull &nr2,int k)
{
    int p=1;
    k/=2;
    while(k--)
        p*=10;
    nr1=x%p;
    nr2=x/p;
}
