#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;

int main()
{
    string a,b;
    getline(cin,a);
    getline(cin,b);
    _for(i,0,a.length())
        a[i]=tolower(a[i]);
    _for(i,0,b.length())
        b[i]=tolower(b[i]);

    return 0;
}
