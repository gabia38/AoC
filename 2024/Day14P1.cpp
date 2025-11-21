#include <iostream>
using namespace std;

int main()
{
    int i,j,movei,movej,fr[103][101]= {0};
    while(scanf("p=%d,%d v=%d,%d",&j,&i,&movej,&movei)==4)
    {
        i=(i+100*movei)%103;
        if(i<0)
            i+=103;
        j=(j+100*movej)%101;
        if(j<0)
            j+=101;
        fr[i][j]++;
        if(cin.peek()=='\n')
            cin.ignore();
    }
    int q1=0,q2=0,q3=0,q4=0;
    for(i=0; i<51; i++)
        for(j=51; j<101; j++)
            q1+=fr[i][j];
    for(i=0; i<51; i++)
        for(j=0; j<50; j++)
            q2+=fr[i][j];
    for(i=52; i<103; i++)
        for(j=0; j<50; j++)
            q3+=fr[i][j];
    for(i=52; i<103; i++)
        for(j=51; j<101; j++)
            q4+=fr[i][j];
    cout << q1*q2*q3*q4;
    return 0;
}
