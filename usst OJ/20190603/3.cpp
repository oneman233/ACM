#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t,n,m,k;

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&m,&k);
        int ans=min(n-m,k+1);
        if(ans<0)
            printf("0\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
