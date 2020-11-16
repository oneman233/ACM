#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;

int t,k;
int a[100],cnt1=0;
ll ans=0;

signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        cnt1=0;
        ans=0;
        scanf("%lld",&k);
        for(int i=0;i<7;++i)
        {
            scanf("%lld",&a[i]);
            a[i+7]=a[i];
            a[i+14]=a[i];
            if(a[i]==1)
                cnt1++;
        }
        if(cnt1==0)
        {
            printf("-1\n");
            continue;
        }
        if(k==1)
        {
            printf("1\n");
            continue;
        }
        if(k<=cnt1*2)
        {
            ll mn=inf;
            for(int i=0;i<21;++i)
            {
                if(a[i]==1)
                {
                    ll cost=1,val=1;
                    for(int j=i+1;j<21;++j,++cost)
                    {
                        if(a[j]==1)
                        {
                            val++;
                            if(val>=k)
                            {
                                cost++;
                                break;
                            }
                        }
                    }
                    if(val>=k)
                        mn=min(mn,cost);
                }
            }
            printf("%lld\n",mn);
        }
        else
        {
            int qujian=k/cnt1;
            if(k%cnt1!=0)
                qujian++;
            k-=(qujian-2)*cnt1;
            ans+=(qujian-2)*7;
            ll mn=inf;
            for(int i=0;i<21;++i)
            {
                if(a[i]==1)
                {
                    ll cost=1,val=1;
                    for(int j=i+1;j<21;++j,++cost)
                    {
                        if(a[j]==1)
                        {
                            val++;
                            if(val>=k)
                            {
                                cost++;
                                break;
                            }
                        }
                    }
                    if(val>=k)
                        mn=min(mn,cost);
                }
            }
            printf("%lld\n",mn+ans);
        }
    }
    return 0;
}
/*
100000
4
1 0 0 0 0 1 0
*/
