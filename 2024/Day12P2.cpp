#include <iostream>
#include <string>
#include <vector>
using namespace std;
void compute(vector<string> &matrix,char c,int i, int j,int &area, int &perimeter);
int check_corners(vector<string> &matrix,char c,int i, int j);
int main()
{
    string line;
    vector<string> matrix;
    while(cin>>line)
    {

        matrix.push_back(line);
    }
    int m=matrix.size(),n=matrix[0].size();
    int  costs=0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            char c=matrix[i][j];
            if(c>='A'&&c<='Z')
            {
                int area=0,perimeter=0;
                compute(matrix,c,i,j,area,perimeter);
                costs+=area*perimeter;
            }
        }
    }
    cout<<costs;
    return 0;
}
void compute(vector<string> &matrix,char c,int i, int j,int &area, int &perimeter)
{
    area++;
    matrix[i][j]+=32;
    perimeter+=check_corners(matrix,c,i,j);//number of corners=number of lines
    if(i+1<matrix.size()&&matrix[i+1][j]==c)
    {
        compute(matrix,c,i+1,j,area,perimeter);
    }
    if(i>0&&matrix[i-1][j]==c)
    {
        compute(matrix,c,i-1,j,area,perimeter);
    }
    if(j+1<matrix[0].size()&&matrix[i][j+1]==c)
    {
        compute(matrix,c,i,j+1,area,perimeter);
    }
    if(j>0&&matrix[i][j-1]==c)
    {
        compute(matrix,c,i,j-1,area,perimeter);
    }
}
int check_corners(vector<string> &matrix,char c,int i, int j)
{
    int corners=0;
    bool down=(i+1==matrix.size()||(i+1<matrix.size()&&matrix[i+1][j]!=c&&matrix[i+1][j]!=c+32));
    bool up=(i==0||(i>0&&matrix[i-1][j]!=c&&matrix[i-1][j]!=c+32));
    bool right=(j+1==matrix[0].size()||(j+1<matrix[0].size()&&matrix[i][j+1]!=c&&matrix[i][j+1]!=c+32));
    bool left=(j==0||(j>0&&matrix[i][j-1]!=c&&matrix[i][j-1]!=c+32));
    if(down&&right)
        corners++;
    if(!down&&!right&&matrix[i+1][j+1]!=c&&matrix[i+1][j+1]!=c+32)
        corners++;
    if(down&&left)
        corners++;
    if(!down&&!left&&matrix[i+1][j-1]!=c&&matrix[i+1][j-1]!=c+32)
        corners++;
    if(up&&right)
        corners++;
    if(!up&&!right&&matrix[i-1][j+1]!=c&&matrix[i-1][j+1]!=c+32)
        corners++;
    if(up&&left)
        corners++;
    if(!up&&!left&&matrix[i-1][j-1]!=c&&matrix[i-1][j-1]!=c+32)
        corners++;
    return corners;
}
