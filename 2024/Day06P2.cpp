#include <iostream>
#include <cstring>
using namespace std;
int i,j,pozi,pozj;
char a[130][130],g='^';
int rezolvare(char a[130][130], int pozi, int pozj);
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
    int rez=0;
    for(i=0; i<130; i++)
        for(j=0; j<130; j++)
        {
            if(a[i][j]!='#'&&a[i][j]!='^')
            {
                a[i][j]='#';
                if(rezolvare(a,pozi,pozj))
                    rez++;
                a[i][j]='.';
            }
        }
    cout<<rez;
    return 0;
}
int rezolvare(char a[130][130], int pozi, int pozj)
{
    int fr[130][130]= {0};
    char g='^';
    while(pozi<130&&pozi>0&&pozj<130&&pozj>0)
    {
        if(g=='^')
        {
            while(a[pozi-1][pozj]!='#'&&pozi-1>=0)
            {
                fr[pozi][pozj]++;
                if(fr[pozi][pozj]>4)
                    return 1;
                pozi--;
            }
            g='>';
        }
        else if(g=='>')
        {
            while(a[pozi][pozj+1]!='#'&&pozj+1<=130)
            {
                fr[pozi][pozj]++;
                if(fr[pozi][pozj]>4)
                    return 1;
                pozj++;
            }
            g='v';
        }
        else if(g=='v')
        {
            while(a[pozi+1][pozj]!='#'&&pozi+1<=130)
            {
                fr[pozi][pozj]++;
                if(fr[pozi][pozj]>4)
                    return 1;
                pozi++;
            }
            g='<';
        }
        else
        {
            while(a[pozi][pozj-1]!='#'&&pozj-1>=0)
            {
                fr[pozi][pozj]++;
                if(fr[pozi][pozj]>4)
                    return 1;
                pozj--;
            }
            g='^';
        }
    }
    return 0;
}
