#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <set>
using namespace std;

int main()
{
    vector<string> matrix;
    string line;
    int i=0,j,ex,ey;
    while(cin>>line)
    {
        matrix.push_back(line);
        if(line.find('E')!=string::npos)
        {
            ex=i;
            ey=line.find('E');
        }
        i++;
    }
    map<pair<int,int>,int> distances;
    i=ex,j=ey;
    int k=0;
    set<pair<int,int>> visited;
    while(matrix[i][j]!='S')
    {
        distances[ {i,j}]=k;
        k++;
        visited.insert({i,j});
        if((matrix[i+1][j]=='.'||matrix[i+1][j]=='S')&&!visited.count({i+1,j}))
        {
            i++;
            continue;
        }
        if((matrix[i-1][j]=='.'||matrix[i-1][j]=='S')&&!visited.count({i-1,j}))
        {
            i--;
            continue;
        }
        if((matrix[i][j+1]=='.'||matrix[i][j+1]=='S')&&!visited.count({i,j+1}))
        {
            j++;
            continue;
        }
        if((matrix[i][j-1]=='.'||matrix[i][j-1]=='S')&&!visited.count({i,j-1}))
        {
            j--;
            continue;
        }
    }
    distances[ {i,j}]=k;
    int maxi=k,time=0,rez=0;
    visited.clear();
    while(time<=maxi-100)
    {
        visited.insert({i,j});
        if(i>1&&matrix[i-1][j]=='#'&&(matrix[i-2][j]=='.'||matrix[i-2][j]=='E')&&!visited.count({i-2,j})&&time+distances[ {i-2,j}]+2<=maxi-100)
        {
            rez++;
        }
        if(j>1&&matrix[i][j-1]=='#'&&(matrix[i][j-2]=='.'||matrix[i][j-2]=='E')&&!visited.count({i,j-2})&&time+distances[ {i,j-2}]+2<=maxi-100)
        {
            rez++;
        }
        if(i<matrix.size()-2&&matrix[i+1][j]=='#'&&(matrix[i+2][j]=='.'||matrix[i+2][j]=='E')&&!visited.count({i+2,j})&&time+distances[ {i+2,j}]+2<=maxi-100)
        {
            rez++;
        }
        if(j<matrix[0].size()-2&&matrix[i][j+1]=='#'&&(matrix[i][j+2]=='.'||matrix[i][j+2]=='E')&&!visited.count({i,j+2})&&time+distances[ {i,j+2}]+2<=maxi-100)
        {
            rez++;
        }

        time++;
        if((matrix[i+1][j]=='.'||matrix[i+1][j]=='E')&&!visited.count({i+1,j}))
        {
            i++;
            continue;
        }
        if((matrix[i-1][j]=='.'||matrix[i-1][j]=='E')&&!visited.count({i-1,j}))
        {
            i--;
            continue;
        }
        if((matrix[i][j+1]=='.'||matrix[i][j+1]=='E')&&!visited.count({i,j+1}))
        {
            j++;
            continue;
        }
        if((matrix[i][j-1]=='.'||matrix[i][j-1]=='E')&&!visited.count({i,j-1}))
        {
            j--;
            continue;
        }
    }
    cout<<rez;
    return 0;
}
