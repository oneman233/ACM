#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;

int n;
int a[maxn],b[maxn],ans[maxn];
priority_queue<int> pq;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    for(int i=0;i<n;++i)
        scanf("%d",&b[i]);
    for(int i=0;i<n;++i)
        pq.push(a[i]+b[0]);
    for(int i=1;i<n;++i){
        for(int j=0;j<n;++j){
            if(pq.top()>b[i]+a[j]){
                pq.pop();
                pq.push(b[i]+a[j]);
            }
            else
                break;
        }
    }
    for(int i=n;i>=1;--i){
        ans[i]=pq.top();
        pq.pop();
    }
    printf("%d",ans[1]);
    for(int i=2;i<=n;++i)
        printf(" %d",ans[i]);
    return 0;
}
