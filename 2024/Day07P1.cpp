#include <iostream>
#include <vector>
using namespace std;
#define ull unsigned long long
bool backtracking(vector<ull> &numere, ull sum, ull result, int i, int n);
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
    return 0;
}
