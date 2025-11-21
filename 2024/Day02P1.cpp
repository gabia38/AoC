#include <iostream>
using namespace std;
int i,c[10],k,x,nr,rasp;
int main()
{
    while(true)
    {
        nr=0;
        while(cin>>x)
        {
            c[nr++]=x;
            if(cin.peek()=='\n'||cin.eof())
                break;
        }
        if(c[1]-c[0]!=0&&c[1]-c[0]>-4&&c[1]-c[0]<4)
        {
            if(c[1]-c[0]>0&&c[1]-c[0]<4)
                k=1;
            else if(c[1]-c[0]<0&&c[1]-c[0]>-4)
                k=-1;
            int ok=1;
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
        }
        if(cin.eof())
            break;
    }
    cout << rasp;
    return 0;
}
