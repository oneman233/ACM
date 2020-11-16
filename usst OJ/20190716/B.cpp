#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    while(~scanf("%d",&n))
    {
        if(n==0)
            break;
        int ans=ceil(log(n)/log(3));
        printf("%d\n",ans);
    }
    return 0;
}
