#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100000;

int n,ans=maxn+5;
ll t,a[maxn+5],sum=0;
deque<ll> d;

int main()
{
    scanf("%d %lld",&n,&t);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    int i=0;
    while(i<n)
    {
        while(sum<t&&i<n){
            d.push_back(a[i]);
            sum+=a[i];
            i++;
        }
        if(sum==t){
            ans=min(ans,(int)d.size());
            sum-=d.front();
            d.pop_front();
        }
        while(sum>t&&!d.empty()){
            sum-=d.front();
            d.pop_front();
        }
    }
    if(sum==t)
        ans=min(ans,(int)d.size());
    if(ans!=maxn+5)
        printf("%d",ans);
    else
        printf("No");
    return 0;
}
