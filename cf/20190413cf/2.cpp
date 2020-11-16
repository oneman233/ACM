#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,h;
    ///m行n列
    ///i行j列
    cin>>n>>m>>h;
    int zheng[110],zuo[110],fu[110][110];
    int ans[110][110];
    for(int i=1;i<=m;++i)
        cin>>zheng[i];
    for(int j=1;j<=n;++j)
        cin>>zuo[j];
    for(int j=1;j<=n;++j)
    {
        for(int i=1;i<=m;++i)
        {
            cin>>fu[i][j];
        }
    }
    for(int j=1;j<=n;++j)
    {
        for(int i=1;i<=m;++i)
        {
            if(fu[i][j]==0)
                ans[i][j]=0;
            else
                ans[i][j]=min(zheng[i],zuo[j]);
        }
    }
    for(int j=1;j<=n;++j)
    {
        for(int i=1;i<=m;++i)
        {
            cout<<ans[i][j];
            if(i!=m)
                cout<<" ";
        }
        if(j!=n)
            cout<<endl;
    }
    return 0;
}
