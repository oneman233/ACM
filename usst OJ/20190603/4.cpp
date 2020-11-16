#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    while(scanf("%d",&n)){
        if(n==0)
            break;
        int ans=1;
        for(int i=2;i*i<=n;++i){
            if(n%i==0&&i!=n/i)
                ans+=2;
            else if(n%i==0&&i==n/i)
                ans+=1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
