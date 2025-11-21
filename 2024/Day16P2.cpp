#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <set>
#include <utility>
using namespace std;
void find_path(vector<string> &matrix,vector<vector<vector<int>>> &minscores,set<pair<int,int>> &minicells,vector<pair<int,int>> &singleroad,int i,int j,int score,int direction,int &mini);
int main()
{
    string line;
    vector<string> matrix;
    while(cin>>line)
    {
        matrix.push_back(line);
    }
    int mini=INT_MAX,m=matrix.size(),n=matrix[0].size();
    vector<vector<vector<int>>> minscores(m,vector<vector<int>>(n,vector<int>(4,INT_MAX)));
    set<pair<int,int>> minicells;
    vector<pair<int,int>> singleroad;
    find_path(matrix,minscores,minicells,singleroad,m-2,1,0,1,mini);
    cout << minicells.size() << endl;
    return 0;
}
void find_path(vector<string> &matrix,vector<vector<vector<int>>> &minscores,set<pair<int,int>> &minicells,vector<pair<int,int>> &singleroad,int i,int j,int score,int direction,int &mini)///direction: 0 for N,1 for E,2 for S,3 for W
{
    if(matrix[i][j]=='E')
    {
        singleroad.push_back({i,j});
        if(score<mini)
        {
            mini=score;
            minscores[i][j][direction]=score;
            minicells.clear();
            minicells.insert(singleroad.begin(),singleroad.end());
        }
        else if(score==mini)
        {
            minicells.insert(singleroad.begin(),singleroad.end());
        }
        return;
    }
    if(score>mini)
    {
        singleroad.push_back({i,j});///for continuity
        return;
    }
    if(score>minscores[i][j][direction])
    {
        singleroad.push_back({i,j});///for continuity
        return;
    }
    minscores[i][j][direction]=score;
    singleroad.push_back({i,j});
    switch(direction)
    {
    case 0:
    {

        if(matrix[i-1][j]!='#')
        {
            find_path(matrix,minscores,minicells,singleroad,i-1,j,score+1,0,mini);
            singleroad.pop_back();
        }
        if(matrix[i][j+1]!='#')
        {
            find_path(matrix,minscores,minicells,singleroad,i,j+1,score+1001,1,mini);
            singleroad.pop_back();
        }
        if(matrix[i][j-1]!='#')
        {
            find_path(matrix,minscores,minicells,singleroad,i,j-1,score+1001,3,mini);
            singleroad.pop_back();
        }
        break;
    }
    case 1:
    {

        if(matrix[i-1][j]!='#')
        {
            find_path(matrix,minscores,minicells,singleroad,i-1,j,score+1001,0,mini);
            singleroad.pop_back();
        }
        if(matrix[i][j+1]!='#')
        {
            find_path(matrix,minscores,minicells,singleroad,i,j+1,score+1,1,mini);
            singleroad.pop_back();
        }
        if(matrix[i+1][j]!='#')
        {
            find_path(matrix,minscores,minicells,singleroad,i+1,j,score+1001,2,mini);
            singleroad.pop_back();
        }


        break;
    }
    case 2:
    {

        if(matrix[i][j+1]!='#')
        {
            find_path(matrix,minscores,minicells,singleroad,i,j+1,score+1001,1,mini);
            singleroad.pop_back();
        }
        if(matrix[i+1][j]!='#')
        {
            find_path(matrix,minscores,minicells,singleroad,i+1,j,score+1,2,mini);
            singleroad.pop_back();
        }
        if(matrix[i][j-1]!='#')
        {
            find_path(matrix,minscores,minicells,singleroad,i,j-1,score+1001,3,mini);
            singleroad.pop_back();
        }
        break;
    }
    case 3:
    {

        if(matrix[i-1][j]!='#')
        {
            find_path(matrix,minscores,minicells,singleroad,i-1,j,score+1001,0,mini);
            singleroad.pop_back();
        }
        if(matrix[i+1][j]!='#')
        {
            find_path(matrix,minscores,minicells,singleroad,i+1,j,score+1001,2,mini);
            singleroad.pop_back();
        }
        if(matrix[i][j-1]!='#')
        {
            find_path(matrix,minscores,minicells,singleroad,i,j-1,score+1,3,mini);
            singleroad.pop_back();
        }
        break;
    }
    }
}
