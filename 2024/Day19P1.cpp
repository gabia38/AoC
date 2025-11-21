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
    int rez=0;
    while(cin>>word)
    {
        int n=word.size();
        vector<bool> is_possible(n+1,false);
        is_possible[n]=true;
        for(int i=n-1; i>=0; i--)
        {
            for(auto const &it:patern)
            {
                int l=it.size();
                if(i+l<=n&&word.substr(i,l)==it&&is_possible[i+l]==true)
                {
                    is_possible[i]=true;
                }
            }
        }
        if(is_possible[0])
            {
                rez++;
            }
    }
    cout<<rez;
    return 0;
}
