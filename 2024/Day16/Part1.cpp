#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;
void find_path(vector<string> &matrix,vector<vector<vector<int>>> &minscores,int i,int j,int score,int direction,int &mini);
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
    find_path(matrix,minscores,m-2,1,0,1,mini);
    cout << mini << endl;
    return 0;
}
void find_path(vector<string> &matrix,vector<vector<vector<int>>> &minscores,int i,int j,int score,int direction,int &mini)///direction: 0 for N,1 for E,2 for S,3 for W
{
    if(matrix[i][j]=='E')
    {
        if(score<mini)
        {
            mini=score;
            minscores[i][j][direction]=score;
        }
        return;
    }
    if(score>=mini)
    {
        return;
    }
    if(score>=minscores[i][j][direction])
    {
        return;
    }
        minscores[i][j][direction]=score;
    switch(direction)
    {
    case 0:
    { while(matrix[i][j-1]=='#'&&matrix[i][j+1]=='#'&&matrix[i-1][j]!='#')
    {
        score++;
        i--;
    }
    if(matrix[i][j]=='E')
    {
        if(score<mini)
        {
            mini=score;
            minscores[i][j][direction]=score;
        }
        return;
    }
        if(matrix[i-1][j]!='#')
        {
            find_path(matrix,minscores,i-1,j,score+1,0,mini);
        }
        if(matrix[i][j+1]!='#')
        {
            find_path(matrix,minscores,i,j+1,score+1001,1,mini);
        }
        if(matrix[i][j-1]!='#')
        {
            find_path(matrix,minscores,i,j-1,score+1001,3,mini);
        }
        break;
    }
    case 1:
    { while(matrix[i-1][j]=='#'&&matrix[i+1][j]=='#'&&matrix[i][j+1]!='#')
    {
        score++;
        j++;
    }
    if(matrix[i][j]=='E')
    {
        if(score<mini)
        {
            mini=score;
            minscores[i][j][direction]=score;
        }
        return;
    }
        if(matrix[i-1][j]!='#')
        {
            find_path(matrix,minscores,i-1,j,score+1001,0,mini);
        }
        if(matrix[i][j+1]!='#')
        {
            find_path(matrix,minscores,i,j+1,score+1,1,mini);
        }
        if(matrix[i+1][j]!='#')
        {
            find_path(matrix,minscores,i+1,j,score+1001,2,mini);
        }

        break;
    }
    case 2:
    { while(matrix[i][j-1]=='#'&&matrix[i][j+1]=='#'&&matrix[i+1][j]!='#')
    {
        score++;
        i++;
    }
    if(matrix[i][j]=='E')
    {
        if(score<mini)
        {
            mini=score;
            minscores[i][j][direction]=score;
        }
        return;
    }
        if(matrix[i][j+1]!='#')
        {
            find_path(matrix,minscores,i,j+1,score+1001,1,mini);
        }
        if(matrix[i+1][j]!='#')
        {
            find_path(matrix,minscores,i+1,j,score+1,2,mini);
        }
        if(matrix[i][j-1]!='#')
        {
            find_path(matrix,minscores,i,j-1,score+1001,3,mini);
        }
        break;
    }
    case 3:
    { while(matrix[i-1][j]=='#'&&matrix[i+1][j]=='#'&&matrix[i][j-1]!='#')
    {
        score++;
        j--;
    }
    if(matrix[i][j]=='E')
    {
        if(score<mini)
        {
            mini=score;
            minscores[i][j][direction]=score;
        }
        return;
    }
        if(matrix[i-1][j]!='#')
        {
            find_path(matrix,minscores,i-1,j,score+1001,0,mini);
        }
        if(matrix[i+1][j]!='#')
        {
            find_path(matrix,minscores,i+1,j,score+1001,2,mini);
        }
        if(matrix[i][j-1]!='#')
        {
            find_path(matrix,minscores,i,j-1,score+1,3,mini);
        }
        break;
    }

    }
}
