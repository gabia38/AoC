#include <iostream>
#include <set>
#include <map>
#include <utility>
using namespace std;
int main()
{
    char c;
    multimap<char,pair<int,int>> antennas;
    set<pair<int,int>> antinodes;
    int i,j;
    for(i=0; cin.peek()!=EOF; i++)
    {
        for(j=0; cin.peek()!='\n'; j++)
        {
            cin>>c;
            if(c!='.')
                antennas.insert({c,{i,j}});
        }
        cin.ignore();
    }
    for(auto it:antennas)
    {
        auto chr=antennas.equal_range(it.first);
        for(auto itc1=chr.first; itc1!=chr.second; itc1++)
        {
            int x1=itc1->second.first,y1=itc1->second.second;
            for(auto itc2=next(itc1); itc2!=chr.second; itc2++)
            {
                int x2=itc2->second.first,y2=itc2->second.second;
                int dx=x2-x1,dy=y2-y1;
                int xa1=x1-dx,xa2=x2+dx,ya1=y1-dy,ya2=y2+dy;
                if(xa1>=0&&xa1<i&&ya1>=0&&ya1<j)
                    antinodes.insert({xa1,ya1});
                if(xa2>=0&&xa2<i&&ya2>=0&&ya2<j)
                    antinodes.insert({xa2,ya2});
            }
        }
    }
    cout<<antinodes.size();
    return 0;
}
