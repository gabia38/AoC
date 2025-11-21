#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<string> matrix;
    string line;
    cin>>line;
    matrix.push_back(line);
    int i=1,pozi,pozj;
    while(cin>>line)
    {
        matrix.push_back(line);
        if(line.find('@')!=string::npos)
        {
            pozi=i;
            pozj=line.find('@');
        }
        if(line.find('.')==string::npos)
        {
            cin.ignore();
            break;
        }
        i++;
    }
    char dir;
    while(cin>>dir)
    {
        switch(dir)
        {
        case '<':
        {
            if(matrix[pozi][pozj-1]!='O'&&matrix[pozi][pozj-1]!='#')
            {
                matrix[pozi][pozj-1]='@';
                matrix[pozi][pozj]='.';
                pozj--;
            }
            else if(matrix[pozi][pozj-1]=='O')
            {
                int jbox=pozj;
                while(matrix[pozi][jbox-1]=='O')
                    jbox--;
                if(matrix[pozi][jbox-1]=='.')
                {
                    matrix[pozi][jbox-1]='O';
                    matrix[pozi][pozj-1]='@';
                    matrix[pozi][pozj]='.';
                    pozj--;
                }
            }
            break;
        }
        case '^':
        {
            if(matrix[pozi-1][pozj]!='O'&&matrix[pozi-1][pozj]!='#')
            {
                matrix[pozi-1][pozj]='@';
                matrix[pozi][pozj]='.';
                pozi--;
            }
            else if(matrix[pozi-1][pozj]=='O')
            {
                int ibox=pozi;
                while(matrix[ibox-1][pozj]=='O')
                    ibox--;
                if(matrix[ibox-1][pozj]=='.')
                {
                    matrix[ibox-1][pozj]='O';
                    matrix[pozi-1][pozj]='@';
                    matrix[pozi][pozj]='.';
                    pozi--;
                }
            }
            break;
        }
        case '>':
        {
            if(matrix[pozi][pozj+1]!='O'&&matrix[pozi][pozj+1]!='#')
            {
                matrix[pozi][pozj+1]='@';
                matrix[pozi][pozj]='.';
                pozj++;
            }
            else if(matrix[pozi][pozj+1]=='O')
            {
                int jbox=pozj;
                while(matrix[pozi][jbox+1]=='O')
                    jbox++;
                if(matrix[pozi][jbox+1]=='.')
                {
                    matrix[pozi][jbox+1]='O';
                    matrix[pozi][pozj+1]='@';
                    matrix[pozi][pozj]='.';
                    pozj++;
                }
            }
            break;
        }
        case 'v':
        {
            if(matrix[pozi+1][pozj]!='O'&&matrix[pozi+1][pozj]!='#')
            {
                matrix[pozi+1][pozj]='@';
                matrix[pozi][pozj]='.';
                pozi++;
            }
            else if(matrix[pozi+1][pozj]=='O')
            {
                int ibox=pozi;
                while(matrix[ibox+1][pozj]=='O')
                    ibox++;
                if(matrix[ibox+1][pozj]=='.')
                {
                    matrix[ibox+1][pozj]='O';
                    matrix[pozi+1][pozj]='@';
                    matrix[pozi][pozj]='.';
                    pozi++;
                }
            }
            break;
        }
        }
    }
    int m=matrix.size(),n=matrix[0].size(),sum=0;
    for(int i=1; i<m-1; i++)
    {
        for(int j=1; j<n-1; j++)
        {
            if(matrix[i][j]=='O')
            {
                sum+=i*100+j;
            }
        }
    }
    cout<<sum;
    return 0;
}
