#include <iostream>
#include <regex>

using namespace std;

int main()
{
    regex mojRegex("hujA.");
    string str = "hujA ";
    bool match = regex_match(str,mojRegex);
    cout<<(match? "elo" : "lipa")<<endl;
return 0;
}

