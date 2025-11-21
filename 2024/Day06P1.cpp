#include <iostream>
#include <cstring>
using namespace std;
int i,j,fr[130][130],pozi,pozj;
char a[130][130],g='^';
int main()
{
    for(i=0; i<130; i++)
    {
        cin>>a[i];
        if(strchr(a[i],'^'))
        {
            pozi=i;
            pozj=strchr(a[i],'^')-a[i];
        }
    }
    while(pozi<130&&pozi>0&&pozj<130&&pozj>0)
    {
        if(g=='^')
        {
            while(a[pozi-1][pozj]!='#'&&pozi-1>=0)
            {
                fr[pozi][pozj]++;
                pozi--;
            }
            g='>';
        }
        else if(g=='>')
        {
            while(a[pozi][pozj+1]!='#'&&pozj+1<=130)
            {
                fr[pozi][pozj]++;
                pozj++;
            }
            g='v';
        }
        else if(g=='v')
        {
            while(a[pozi+1][pozj]!='#'&&pozi+1<=130)
            {
                fr[pozi][pozj]++;
                pozi++;
            }
            g='<';
        }
        else
        {
            while(a[pozi][pozj-1]!='#'&&pozj-1>=0)
            {
                fr[pozi][pozj]++;
                pozj--;
            }
            g='^';
        }
    }
    fr[pozi][pozj]++;
    int rez=0;
    for(i=0; i<130; i++)
        for(j=0; j<130; j++)
            if(fr[i][j]>0)
                rez++;
    cout <<rez;
    return 0;
}
