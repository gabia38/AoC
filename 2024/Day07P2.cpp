#include <iostream>
#include <vector>
using namespace std;
#define ull unsigned long long
bool backtracking(vector<ull> &numere, ull sum, ull result, int i, int n);
ull concat(ull result, ull x);
int main()
{
    ull total=0,sum,x;
    char c;
    while(cin>>sum>>c)
    {
        vector<ull> numere;
        while(cin.peek()!='\n')
        {
            cin>>x;
            numere.push_back(x);
        }
        if(backtracking(numere,sum,numere[0],1,numere.size()))
        {
            total+=sum;
        }
    }
    cout<<total;
    return 0;
}
bool backtracking(vector<ull>&numere, ull sum, ull result, int i, int n)
{
    if(i==n&&sum==result)
        return 1;
    if((i==n&&sum!=result))
        return 0;
    if(backtracking(numere,sum,result+numere[i],i+1,n))
        return 1;
    if(backtracking(numere,sum,result*numere[i],i+1,n))
        return 1;
    if(backtracking(numere,sum,concat(result,numere[i]),i+1,n))
        return 1;
    return 0;
}
ull concat(ull result, ull x)
{
    ull nr=x;
    int p=1;
    while(nr)
    {
        p*=10;
        nr/=10;
    }
    return result*p+x;
}
