#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int A,B,C;
    scanf("Register A:%d Register B:%d Register C:%d Program:",&A,&B,&C);
    int prog[16],k=0;
    while(cin>>prog[k++])
        cin.ignore();
    int op;
    string delimiter="";
    for(int i=0; i<k; i+=2)
    {
        if(prog[i+1]<4)
            op=prog[i+1];
        else if(prog[i+1]==4)
            op=A;
        else if(prog[i+1]==5)
            op=B;
        else
            op=C;
        if(prog[i]==0)
        {
            if(log2(A)<op)
                A=0;
            else
                A/=pow(2,op);
        }
        else if(prog[i]==1)
            B=B^prog[i+1];
        else if(prog[i]==2)
            B=op%8;
        else if(prog[i]==3&&A)
            i=-2;
        else if(prog[i]==4)
            B=B^C;
        else if(prog[i]==5)
        {
            cout<<delimiter<<op%8;
            delimiter=',';
        }
        else if(prog[i]==6)
        {
            if(log2(A)<op)
                B=0;
            else
                B=A/pow(2,op);
        }
        else if(prog[i]==7)
        {
            if(log2(A)<op)
                C=0;
            else
                C=A/pow(2,op);
        }
    }
    return 0;
}
