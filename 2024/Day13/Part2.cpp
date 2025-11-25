#include <iostream>
#include <climits>
using namespace std;
int main()
{
    long long xa,ya,xb,yb,x,y,fin=0;
    while(scanf("Button A: X+%lld, Y+%lld\nButton B: X+%lld, Y+%lld\nPrize: X=%lld, Y=%lld\n\n",&xa,&ya,&xb,&yb,&x,&y)==6)
    {
        long long mini=LLONG_MAX;
        x+=10000000000000LL;
        y+=10000000000000LL;
        long long D=xa*yb-ya*xb;
        long long i=(x*yb-y*xb);
        long long j=(xa*y-ya*x);
        if(i%D==0&&j%D==0)
        {
            fin+=3*i/D+j/D;
        }
    }
    cout<<fin;
    return 0;
}
