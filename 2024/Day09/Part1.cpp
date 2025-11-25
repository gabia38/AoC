#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s;
    cin>>s;
    vector<int> rez;
    int k=0,n=s.size();
    for(int i=0; i<n; i++)
        if(i%2==0)
        {
            for(int j=0; j<s[i]-'0'; j++)
                rez.push_back(k);
            k++;
        }
        else
            for(int j=0; j<s[i]-'0'; j++)
                rez.push_back(-1);
    int l=rez.size(),RightmostValue=l-1;
    for(int i=0; i<l; i++)
        if(rez[i]==-1)
            for(int j=RightmostValue; j>=i; j--)
                if(rez[j]!=-1)
                {
                    swap(rez[i],rez[j]);
                    RightmostValue=j;
                    break;
                }
    long long sum=0;
    for(int i=0; i<l; i++)
    {
        if(rez[i]<0)
            break;
        sum+=i*rez[i];
    }
    cout<<sum;
    return 0;
}
