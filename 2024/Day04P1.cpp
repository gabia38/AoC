#include <iostream>
#include <cstring>
using namespace std;
int i,j,nr;
char a[150][150]= {'0'};
int main()
{
    for(i=3; i<145; i++)
        cin>>a[i]+3;
    for(i=3; i<144; i++)
        for(j=3; j<144; j++)
            if(a[i][j]=='X')
            {
                if(a[i][j+1]=='M'&&a[i][j+2]=='A'&&a[i][j+3]=='S')
                    nr++;
                if(a[i+1][j+1]=='M'&&a[i+2][j+2]=='A'&&a[i+3][j+3]=='S')
                    nr++;
                if(a[i+1][j]=='M'&&a[i+2][j]=='A'&&a[i+3][j]=='S')
                    nr++;
                if(a[i+1][j-1]=='M'&&a[i+2][j-2]=='A'&&a[i+3][j-3]=='S')
                    nr++;
                if(a[i][j-1]=='M'&&a[i][j-2]=='A'&&a[i][j-3]=='S')
                    nr++;
                if(a[i-1][j-1]=='M'&&a[i-2][j-2]=='A'&&a[i-3][j-3]=='S')
                    nr++;
                if(a[i-1][j]=='M'&&a[i-2][j]=='A'&&a[i-3][j]=='S')
                    nr++;
                if(a[i-1][j+1]=='M'&&a[i-2][j+2]=='A'&&a[i-3][j+3]=='S')
                    nr++;
            }
    cout << nr;
    return 0;
}
