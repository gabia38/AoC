#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
struct Point
{
    int x,y,dist;
};
int main()
{
    vector<string> matrix(71,string(71,'.'));
    int x,y;
    char sep;
    int i=0;
    while(cin>>x>>sep>>y)
    {
        if(i<1024)
        {
            matrix[x][y]='#';
            i++;
        }
    }
    const int dx[]= {-1,0,1,0},dy[]= {0,1,0,-1};
    vector<vector<bool>>visited(71,vector<bool>(71,false));
    queue<Point> q;
    q.push({0,0,0});
    visited[0][0]=true;
    while(!q.empty())
    {
        Point cur=q.front();
        q.pop();
        if(cur.x==70&&cur.y==70)
        {
            cout<<cur.dist;
            return 0;
        }
        for(int i=0; i<4; i++)
        {
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];
            if(nx>=0&&nx<71&&ny>=0&&ny<71&&!visited[nx][ny]&&matrix[nx][ny]!='#')
            {
                visited[nx][ny]=true;
                q.push({nx,ny,cur.dist+1});
            }
        }
    }
    return 0;
}
