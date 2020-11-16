#include <bits/stdc++.h>
using namespace std;
const int maxn=10005;

int n,m;
int a[maxn],b[maxn],c[maxn],ans[maxn];

int f(int i,int x)
{
    return a[i]*x*x+b[i]*x+c[i];
}

priority_queue<int> pq;

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;++i)
        scanf("%d %d %d",a+i,b+i,c+i);
    for(int i=1;i<=100;++i){
        for(int j=0;j<n;++j){
            if(pq.size()<m)
                pq.push(f(j,i));
            else{
                if(f(j,i)<=pq.top()){
                    pq.pop();
                    pq.push(f(j,i));
                }
            }
        }
    }
    for(int i=m;i>=1;--i){
        ans[i]=pq.top();
        pq.pop();
    }
    printf("%d",ans[1]);
    for(int i=2;i<=m;++i)
        printf(" %d",ans[i]);
    return 0;
}
