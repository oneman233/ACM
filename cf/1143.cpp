#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define sci(a) scanf("%d",&a)
#define pri(a) printf("%d",a)
using namespace std;
typedef long long ll;
const int Max=200000;

int main()
{
    int n,dor[Max+10];
    int l=0,r=0;
    sci(n);
    _for(i,0,n)
    {
        sci(dor[i]);
        if(dor[i]==0)
            l++;
        else
            r++;
    }
    int ans=1,tl=0,tr=0;
    _for(i,0,n)
    {
        if(dor[i]==0)
            tl++;
        else
            tr++;
        if(tl==l||tr==r)
            break;
        ++ans;
    }
    pri(ans);
    return 0;
}
