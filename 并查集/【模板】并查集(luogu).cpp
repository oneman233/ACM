#include <bits/stdc++.h>
using namespace std;

int n,m;
int z,x,y;
int pre[10005];

int fin(int i)
{
    if(pre[i]==i)
        return i;
    else
        pre[i]=fin(pre[i]);///当前点的pre等于find(pre)
        return fin(pre[i]);
}

void merg(int i,int j)
{
    pre[fin(i)]=fin(j);
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        pre[i]=i;///init
    while(m--)
    {
        cin>>z>>x>>y;
        if(z==1)
            merg(x,y);
        else
        {
            if(fin(x)==fin(y))
                cout<<"Y"<<endl;
            else
                cout<<"N"<<endl;
        }
    }
    return 0;
}
