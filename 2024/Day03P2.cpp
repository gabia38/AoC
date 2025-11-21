#include <iostream>
#include <string>
#include <regex>
using namespace std;
long long nr1,nr2,sum;
string s;
int main()
{
    regex rezolvare_regex(R"(mul\((\d+),(\d+)\)|do\(\)|don't\(\))");
    smatch match;
    int ok=1;
    while(getline(cin,s))
    {
        string::const_iterator it=(s.cbegin());
        while(regex_search(it,s.cend(),match,rezolvare_regex))
        {
            string matched_str=match.str();
            if(matched_str=="do()")
                ok=1;
            else if(matched_str=="don't()")
                ok=0;
            else if(ok)
            {
                nr1=stoll(match[1].str());
                nr2=stoll(match[2].str());
                sum+=nr1*nr2;
            }
            it=match.suffix().first;
        }
    }
    cout<<sum;
    return 0;
}
