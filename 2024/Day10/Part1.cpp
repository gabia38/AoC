#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <utility>
using namespace std;
void backtrack(set<pair<pair<int,int>,pair<int,int>>> &paths,vector<string> &matrix,int i,int j,int i0, int j0, char nr);
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
    set<pair<pair<int,int>,pair<int,int>>> paths;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(matrix[i][j]=='0')
            {
                backtrack(paths,matrix,i,j,i,j,'0');
            }
        }
    }
    cout << paths.size() << endl;
    return 0;
}
void backtrack(set<pair<pair<int,int>,pair<int,int>>> &paths,vector<string> &matrix,int i, int j,int i0,int j0, char nr)
{
    if(nr=='9')
    {
        paths.insert({{i0,j0},{i,j}});
        return;
    }
    if(j+1<matrix[0].size()&&matrix[i][j+1]==nr+1)
    {
        backtrack(paths,matrix,i,j+1,i0,j0,nr+1);
    }
    if(i+1<matrix.size()&&matrix[i+1][j]==nr+1)
    {
        backtrack(paths,matrix,i+1,j,i0,j0,nr+1);
    }
    if(j>0&&matrix[i][j-1]==nr+1)
    {
        backtrack(paths,matrix,i,j-1,i0,j0,nr+1);
    }
    if(i>0&&matrix[i-1][j]==nr+1)
    {
        backtrack(paths,matrix,i-1,j,i0,j0,nr+1);
    }
    return;
}
