#include <bits/stdc++.h>

using namespace std;

bool check(string line, int i, int  &nr);

int main()
{
    int rez=0;
    string line;
    while(getline(cin,line))
    {
        int nr=0,l=line.size();
        for(int i=0;i<l;i++)
        {
            if(check(line,i,nr))
            {
                break;
            }
        }
        nr*=10;
        for(int i=line.size()-1;i>=0;i--)
        {
            if(check(line,i,nr))
            {
                break;
            }
        }
        rez+=nr;
    }
    cout<<rez;
    return 0;
}
bool check(string line, int i, int &nr)
{
    switch (line[i])
    {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        {
            nr+=line[i]-'0';
            return true;
        }
        case 'o':
        {
            if(line.substr(i,3)=="one")
            {
                nr+=1;
                return true;
            }
            return false;
        }
        case 't':
        {
            if(line.substr(i,3)=="two")
            {
                nr+=2;
                return true;
            }
            if(line.substr(i,5)=="three")
            {
                nr+=3;
                return true;
            }
            return false;
        }
        case 'f':
        {
            if(line.substr(i,4)=="four")
            {
                nr+=4;
                return true;
            }
            if(line.substr(i,4)=="five")
            {
                nr+=5;
                return true;
            }
            return false;
        }
        case 's':
        {
            if(line.substr(i,3)=="six")
            {
                nr+=6;
                return true;
            }
            if(line.substr(i,5)=="seven")
            {
                nr+=7;
                return true;
            }
            return false;
        }
        case 'e':
        {
            if(line.substr(i,5)=="eight")
            {
                nr+=8;
                return true;
            }
            return false;
        }
        case 'n':
        {
            if(line.substr(i,4)=="nine")
            {
                nr+=9;
                return true;
            }
            return false;
        }
    }
    return false;
}
