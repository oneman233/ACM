#include <bits/stdc++.h>
#define scl(a) scanf("%lld",&a)
#define sci(a) scanf("%d",&a)
#define _for(i,a,b) for(int i=a;i<b;++i)
using namespace std;
typedef long long ll;

const int maxn=100000;

int n,a[maxn+10];
ll sum;

int main()
{
    sci(n);
    _for(i,0,n)
        sci(a[i]);
    scl(sum);
    sort(a,a+n);
    _for(i,0,n)
    {
        _for(j,i+1,n)
        {
            if(a[i]+a[j]>sum)
                break;
            if(a[i]+a[j]==sum)
            {
                cout<<a[i]<<" "<<a[j];
                return 0;
            }
        }
    }
    cout<<"No";
    return 0;
}
