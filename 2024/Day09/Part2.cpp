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
    int l=rez.size();
    for(int j=l-1; j>=0; j--)
    {
        if(rez[j]!=-1)
        {
            int MemBlock=1;
            while(rez[j]==rez[j-1])
            {
                MemBlock++;
                j--;
            }
            int EmptyBlock=0,pozi;
            for(int i=0; i<j&&EmptyBlock<MemBlock; i++)
                if(rez[i]==-1)
                {
                    if(EmptyBlock==0)
                        pozi=i;
                    EmptyBlock++;
                }
                else
                    EmptyBlock=0;
            if(EmptyBlock>=MemBlock)
            {
                for(int i=pozi; i<pozi+MemBlock; i++)
                    rez[i]=rez[j];
                for(int jaux=j; jaux<j+MemBlock; jaux++)
                    rez[jaux]=-1;
            }
        }
    }
    long long sum=0;
    for(int i=0; i<l; i++)
        if(rez[i]>-1)
            sum+=i*rez[i];
    cout<<sum;
    return 0;
}
