#include <bits/stdc++.h>
using namespace std;

int n;
int a[105];

int main()
{
    while(~scanf("%d",&n))
    {
        bool can=true;
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        int stage[10];
        stage[1]=0;stage[2]=0;stage[3]=-1;
        for(int i=1;i<=n;++i)
        {
            if(stage[a[i]]==-1)
            {
                can=false;
                break;
            }
            stage[a[i]]=1;
            for(int j=1;j<=3;++j)
            {
                if(stage[j]==0)
                    stage[j]=-1;
                else if(stage[j]==-1)
                    stage[j]=0;
            }
            stage[a[i]]=0;
        }
        if(can)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
