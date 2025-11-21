#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
using namespace std;
int backtrack(map<pair<int,int>,int> &paths,vector<string> &matrix,int i,int  j,char nr);
int main()
{
    vector<string> matrix;
    string line;
    while(cin>>line)
    {
        if(!line.empty())
            matrix.push_back(line);
    }
    int n=matrix.size(),m=matrix[0].size(),rez=0;
    map<pair<int,int>,int> paths;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(matrix[i][j]=='0')
            {
                rez+=backtrack(paths,matrix,i,j,'0');
            }
        }
    }
    cout << rez << endl;
    return 0;
}
int backtrack(map<pair<int,int>,int> &paths,vector<string> &matrix,int i, int j,char nr)
{
    if(nr=='9')
        return 1;
    if(paths.find({i,j})!=paths.end())
        return paths[{i,j}];
    int rez=0;
    if(j+1<matrix[0].size()&&matrix[i][j+1]==nr+1)
    {
        rez+=backtrack(paths,matrix,i,j+1,nr+1);
    }
    if(i+1<matrix.size()&&matrix[i+1][j]==nr+1)
    {
        rez+=backtrack(paths,matrix,i+1,j,nr+1);
    }
    if(j>0&&matrix[i][j-1]==nr+1)
    {
        rez+=backtrack(paths,matrix,i,j-1,nr+1);
    }
    if(i>0&&matrix[i-1][j]==nr+1)
    {
        rez+=backtrack(paths,matrix,i-1,j,nr+1);
    }
    return paths[{i,j}]=rez;
}
