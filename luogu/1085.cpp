#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool unhappy=false;
    int a,b;
    int most=0,day;
    for(int i=1;i<=7;i++)
    {
        cin>>a>>b;
        if(a+b>=8)
        {
            unhappy=true;
            if(a+b>most)
            {
                most=a+b;
                day=i;
            }
        }
    }
    if(unhappy)
        cout<<day;
    else
        cout<<0;
    return 0;
}
