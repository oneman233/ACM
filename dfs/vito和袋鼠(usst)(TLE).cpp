#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;

const int Max=10000;
int n;
int hi[Max+5];
int ans=Max+5;

void dfs(int i,int step)
{
    if(i>=n)
    ///�յ�������n��λ����ȥ
    {
        ans=min(ans,step);
        return;
    }
    if(hi[i]==0)
    ///��������
        return;
    _for(j,1,hi[i]+1)
        dfs(i+j,step+1);
}

int main()
{

    cin>>n;
    _for(i,0,n)
        cin>>hi[i];
    dfs(0,0);
    if(ans<Max+5)
        cout<<ans;
    else
        cout<<-1;
    return 0;
}
