#include <iostream>
#include <string>
#include <map>
#include <set>
#include <tuple>
using namespace std;

int main()
{
    multimap<string,string> connections;
    string a,b,line;
    while(cin>>line)
    {
        a=line.substr(0,2);
        b=line.substr(3,2);
        connections.insert({a,b});
        connections.insert({b,a});
    }
    set<tuple<string,string,string>> rez;
    for(auto it1:connections)
    {
        auto range=connections.equal_range(it1.first);
        for(auto it2=range.first; it2!=range.second; it2++)
        {
            for(auto it3=next(it2); it3!=range.second; it3++)
            {
                if(it2->first[0]=='t'||it2->second[0]=='t'||it3->second[0]=='t')
                {
                    auto range2=connections.equal_range(it2->second);
                    for(auto it4=range2.first; it4!=range2.second; it4++)
                    {
                        if(it4->second==it3->second)
                        {
                            string  x=it2->first,y=it2->second,z=it3->second;
                            if(x<y)
                            {
                                swap(x,y);
                            }
                            if(x<z)
                            {
                                swap(x,z);
                            }
                            if(y<z)
                            {
                                swap(y,z);
                            }
                            rez.insert({x,y,z});
                            break;
                        }
                    }

                }
            }
        }
    }
    cout<< rez.size()<< endl;
    return 0;
}
