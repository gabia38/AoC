#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
using namespace std;
struct Point
{
    int x,y;
};
bool is_possible(int k,const vector<pair<int,int>> &walls);
int main()
{
    vector<pair<int,int>> walls;
    int x,y;
    char op;
    while(cin>>x>>op>>y)
    {
        walls.push_back({x,y});
    }
    int left=1024,right=walls.size(),answer=0;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(is_possible(mid,walls))
        {
            answer=mid;
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }

    }
    cout<<walls[answer].first<<','<<walls[answer].second;
    return 0;
}
bool is_possible(int k,const vector<pair<int,int>> &walls)
{
    vector<string> matrix(71,string(71,'.'));
    for(int i=0; i<k; i++)
    {
        matrix[walls[i].first][walls[i].second]='#';
    }
    if(matrix[0][0]=='#'||matrix[70][70]=='#')
        return false;
    const int dx[]= {-1,0,1,0},dy[]= {0,1,0,-1};
    vector<vector<bool>>visited(71,vector<bool>(71,false));
    queue<Point> q;
    q.push({0,0});
    visited[0][0]=true;
    while(!q.empty())
    {
        Point cur=q.front();
        q.pop();
        if(cur.x==70&&cur.y==70)
        {
            return true;
        }
        for(int i=0; i<4; i++)
        {
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];
            if(nx>=0&&nx<71&&ny>=0&&ny<71&&!visited[nx][ny]&&matrix[nx][ny]!='#')
            {
                visited[nx][ny]=true;
                q.push({nx,ny});
            }
        }
    }
    return false;
}
