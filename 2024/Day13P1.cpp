#include <iostream>
#include <climits>
using namespace std;
int main()
{ int xa,ya,xb,yb,x,y,fin=0;
    while(scanf("Button A: X+%d, Y+%d\nButton B: X+%d, Y+%d\nPrize: X=%d, Y=%d\n\n",&xa,&ya,&xb,&yb,&x,&y)==6)
    {   int mini=INT_MAX;
        for(int i=0;i*xa<=x&&i*ya<=y;i++)
        {
            for(int j=0;i*xa+j*xb<=x&&i*ya+j*yb<=y;j++)
            {
                if(i*xa+j*xb==x&&i*ya+j*yb==y)
                {
                    if(3*i+j<mini)
                    {
                        mini=3*i+j;
                    }
                }
            }
        }
        if(mini<INT_MAX)
        {
            fin+=mini;
        }

    }
    cout<<fin;
    return 0;
}
