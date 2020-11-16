#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
const int Max = 100000;

int main()
{
    double s,x;
    cin>>s>>x;
    double len=0.0,spd=7.0;
    if(s-x<len)
    {
        if(s+x>=7)
        {
            cout<<"y";
        }
        else
        {
            cout<<"no";
        }
        return 0;
    }
    while(1)
    {
        len+=spd;
        spd*=0.98;
        if(len>=s-x)
            break;
    }
    if(len+spd>s+x)
    {
        cout<<"n";
    }
    else
    {
        cout<<"y";
    }
    return 0;
}
