#include <iostream>
#include <string>
#include <vector>
using namespace std;
void compute(vector<string> &matrix,char c,int i, int j,int &area, int &perimeter);
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
    if(i+1<matrix.size())
    {
        if(matrix[i+1][j]==c)
        {
            compute(matrix,c,i+1,j,area,perimeter);
        }
        else if(matrix[i+1][j]!=c+32)
        {
            perimeter++;
        }
    }
    else
    {
        perimeter++;
    }
    if(i>0)
    {
        if(matrix[i-1][j]==c)
        {
            compute(matrix,c,i-1,j,area,perimeter);
        }
        else if(matrix[i-1][j]!=c+32)
        {
            perimeter++;
        }
    }
    else
    {
        perimeter++;
    }
    if(j+1<matrix[0].size())
    {
        if(matrix[i][j+1]==c)
        {
            compute(matrix,c,i,j+1,area,perimeter);
        }
        else if(matrix[i][j+1]!=c+32)
        {
            perimeter++;
        }
    }
    else
    {
        perimeter++;
    }
    if(j>0)
    {
        if(matrix[i][j-1]==c)
        {
            compute(matrix,c,i,j-1,area,perimeter);
        }
        else if(matrix[i][j-1]!=c+32)
        {
            perimeter++;
        }
    }
    else
    {
        perimeter++;
    }
}
