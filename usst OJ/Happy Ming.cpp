#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define _rep(i,a,b) for(int i=(a);i<=(b);i++)

const long long INF=0x3f3f3f3f;

using namespace std;

int main()
{
    int n,m;
    long long ans=0;
    long long sum,he;
    int num[30][2];
    scanf("%d %d",&n,&m);
    _for(i,0,m)
    {
        scanf("%d %d",&num[i][0],&num[i][1]);
    }
    _for(i,1,(1<<m))
    {
        sum=0;
        he=0;
        _for(j,0,m)
        {
            if(i&(1<<j))
            {
                he+=num[j][0];
                if(he>n)
                    break;
                sum+=num[j][0]*num[j][1];
            }
        }
        if(sum>ans)
            ans=sum;
    }
    printf("%lld",ans);
    return 0;
}
