#include <bits/stdc++.h>
using namespace std;

int n,m,k,tmp;
int ans=0;

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;++i){
        bool can=false;
        for(int j=0;j<m;++j){
            scanf("%d",&tmp);
            if(tmp==k)
                can=true;
        }
        if(!can)
            ans++;
    }
    printf("%d",ans);
    return 0;
}
