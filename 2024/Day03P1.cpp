#include <iostream>
#include <string>
#include <regex>
using namespace std;
long long nr1,nr2,sum;
string s;
int main()
{
    regex mul_regex(R"(mul\((\d+),(\d+)\))");
    smatch match;
    while(getline(cin,s))
    {
        string::const_iterator it=(s.cbegin());
        while(regex_search(it,s.cend(),match,mul_regex))
        {
            nr1=stoll(match[1].str());
            nr2=stoll(match[2].str());
            sum+=nr1*nr2;
            it=match.suffix().first;
        }
    }
    cout<<sum;
    return 0;
}
