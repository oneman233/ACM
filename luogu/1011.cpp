#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,n,m,x;
    cin>>a>>n>>m>>x;
    int up[10000],down[10000],people[10000];
    int tmp=0;
    people[1]=people[2]=a;
    up[1]=a;
    down[1]=0;
    while(true)
    {
        up[2]=down[2]=tmp;
        for(int i=3;i<=n-1;++i)
        {
            up[i]=up[i-1]+up[i-2];
            down[i]=up[i-1];
            people[i]=people[i-1]+up[i]-down[i];
        }
        if(people[n-1]==m)
            break;
        else
            ++tmp;
    }
    cout<<people[x];
    return 0;
}
