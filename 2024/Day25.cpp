#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

int main()
{
    map<int,vector<int>> locks,keys;
    int nrlock=0,nrkey=0;
    char pattern[7][5];
    while(!cin.eof())
    {
        for(int i=0; i<7; i++)
            cin>>pattern[i];
        if(pattern[0][0]=='#')
        {
            vector<int> currlock= {0,0,0,0,0};
            for(int j=0; j<5; j++)
            {
                int nrcolumn=0;
                for(int i=1; i<6; i++)
                    if(pattern[i][j]=='#')
                        nrcolumn++;
                currlock[j]=nrcolumn;
            }
            locks[nrlock++]=currlock;
        }
        else
        {
            vector<int> currkey= {0,0,0,0,0};
            for(int j=0; j<5; j++)
            {
                int nrcolumn=0;
                for(int i=1; i<6; i++)
                    if(pattern[i][j]=='#')
                        nrcolumn++;
                currkey[j]=nrcolumn;
            }
            keys[nrkey++]=currkey;
        }
        cin>>ws;
    }
    int rez=0;
    for(int i=0; i<nrlock; i++)
        for(int j=0; j<nrkey; j++)
        {
            bool ok=true;
            for(int k=0; k<5&&ok; k++)
                if(locks[i][k]+keys[j][k]>5)
                    ok=false;
            if(ok)
                rez++;
        }
    cout<<rez;
    return 0;
}
