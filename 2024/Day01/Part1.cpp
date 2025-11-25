#include <iostream>
#include <list>
#include <cmath>
using namespace std;
int x,i,s,n;
int main()
{
    list<int> list1;
    list<int> list2;
    while(cin>>x)
    {
        if(i%2)
            list2.push_back(x);
        else
            list1.push_back(x);
        i++;
    }
    list1.sort();
    list2.sort();
    n=list1.size();
    while(n--)
    {
        int a=list1.front(), b=list2.front();
        s+=abs(a-b);
        list1.pop_front();
        list2.pop_front();
    }
    cout <<s;
    return 0;
}
