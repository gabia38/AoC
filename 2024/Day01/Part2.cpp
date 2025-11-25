#include <iostream>
#include <list>
#include <algorithm>
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
    n=list1.size();
    while(n--)
    {
        int a=list1.front();
        int b=count(list2.begin(),list2.end(),a);
        s+=a*b;
        list1.pop_front();
    }
    cout <<s;
    return 0;
}

