#include <iostream>
#include <vector>
using namespace std;
bool evendig(unsigned long long x,int &k);
void split(unsigned long long &x,unsigned long long &y,int k);
int main()
{
    vector<unsigned long long> rez;
    unsigned long long x;
    while(cin>>x)
        rez.push_back(x);
    int l=rez.size(),currentl=l,nrdig=0;
    for(int i=0; i<25; i++)
    {
        int j=0;
        while(j<currentl)
        {
            if(rez[j]==0)
                rez[j]++;
            else if(evendig(rez[j],nrdig))
            {
                unsigned long long y;
                split(rez[j],y,nrdig);
                rez.push_back(y);
                l++;
            }
            else
                rez[j]*=2024;
            j++;
            nrdig=0;
        }
        currentl=l;
    }
    cout<<l;
    return 0;
}
bool evendig(unsigned long long x,int &k)
{
    while(x)
    {
        k++;
        x/=10;
    }
    return k%2==0;
}
void split(unsigned long long &x,unsigned long long &y,int k)
{
    int p=1;
    k/=2;
    while(k--)
        p*=10;
    y=x%p;
    x=x/p;
}
