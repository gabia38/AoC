#include <iostream>
using namespace std;

int main()
{
    unsigned long long x,sum=0;
    while(cin>>x)
    {
        for(int i=0; i<2000; i++)
        {
            x=(x^(x*64))%16777216;
            x=(x^(x/32))%16777216;
            x=(x^(x*2048))%16777216;
        }
        sum+=x;
    }
    cout<<sum;
    return 0;
}
