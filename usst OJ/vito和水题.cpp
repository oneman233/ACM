#include <bits/stdc++.h>

using namespace std;

int main()
{
    string in;
    getline(cin,in);
    string::size_type idx;
    idx=in.find("shui");
    if(idx!=string::npos)
        cout<<"yes";
    else
        cout<<"no";
    return 0;
}
