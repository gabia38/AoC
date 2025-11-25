#include <iostream>
using namespace std;
int i,c[10],k,x,nr,rasp,ok;
int rezolvare(int c[], int i, int nr);
int main()
{
    while(true)
    {
        nr=0;
        while(cin>>c[nr++])
        {
            if(cin.peek()=='\n'||cin.eof())
                break;
        }
        int diff=c[1]-c[0];
        if(diff!=0&&diff>-4&&diff<4)
        {
            if(diff>0)
                k=1;
            else
                k=-1;
            ok=1;
            if(k==1)
                for(i=2; i<nr&&ok==1; i++)
                {
                    if(c[i]-c[i-1]<1||c[i]-c[i-1]>3)
                        ok=0;
                }
            else
                for(i=2; i<nr&&ok==1; i++)
                {
                    if(c[i]-c[i-1]>-1||c[i]-c[i-1]<-3)
                        ok=0;
                }
            if(ok)
                rasp++;
            else
                for(i=0; i<nr; i++)
                {
                    if(rezolvare(c,i,nr))
                    {
                        rasp++;
                        break;
                    }
                }
        }
        else
            for(i=0; i<nr; i++)
            {
                if(rezolvare(c,i,nr))
                {
                    rasp++;
                    break;
                }
            }
        if(cin.eof())
            break;
    }
    cout << rasp;
    return 0;
}
int rezolvare(int c[],int i, int nr)
{
    int j,a[nr],k=0,ind=0;
    for(j=0; j<nr; j++)
        if(j!=i)
            a[ind++]=c[j];
    nr--;
    int diff=a[1]-a[0];
    if(diff==0||diff<=-4||diff>=4)
        return 0;
    if(diff>0)
        k=1;
    else
        k=-1;
    if(k==1)
        for(i=2; i<nr; i++)
        {
            if(a[i]-a[i-1]<1||a[i]-a[i-1]>3)
                return 0;
        }
    else
        for(i=2; i<nr; i++)
        {
            if(a[i]-a[i-1]>-1||a[i]-a[i-1]<-3)
                return 0;
        }
    return 1;
}
