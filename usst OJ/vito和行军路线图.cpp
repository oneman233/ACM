#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s,e;
    long long way[85];
    cin>>s>>e;
    way[1]=1;
    way[2]=1;
    for(int i=3;i<=e-s+1;i++)
        way[i]=way[i-1]+way[i-2];
    cout<<way[e-s+1];
    return 0;
}
