#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string word;
    unordered_set<string> patern;
    int mini=100,maxi=0;
    while(cin>>word)
    {
        if(word.back()==',')
        {
            word.pop_back();
            patern.insert(word);
        }
        else
        {
            patern.insert(word);
            cin.ignore();
            cin.ignore();
            break;
        }
    }
    long long rez=0;
    while(cin>>word)
    {
        int n=word.size();
        vector<long long> is_possible(n+1,0);
        is_possible[n]=1;
        for(int i=n-1; i>=0; i--)
        {
            for(auto const &it:patern)
            {
                int l=it.size();
                if(i+l<=n&&word.substr(i,l)==it)
                {
                    is_possible[i]+=is_possible[i+l];
                }
            }
        }
        rez+=is_possible[0];
    }
    cout<<rez;
    return 0;
}
