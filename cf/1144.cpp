#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define sci(a) scanf("%d",&a)
#define pri(a) printf("%d",a)
using namespace std;
typedef long long ll;

int n;
int a[2005];

int main()
{
    sci(n);
    _for(i,0,n)
    {
        sci(a[i]);
    }
    sort(a,a+n);
    int ji=0,ou=0;
    _for(i,0,n)
    {
        if(a[i]%2==0)
            ou++;
        else
            ji++;
    }
    if(ji-ou==1||ji-ou==-11||ji-ou==0)
    {
        cout<<0;
    }
    else
    {
        int ans=0;
        if(ji>ou)
        {
            int cnt=ji-ou-1;
            _for(i,0,n)
            {
                if(a[i]&1)
                {
                    cnt--;
                    ans+=a[i];
                    if(cnt==0)
                        break;
                }
            }
        }
        else
        {
            int cnt=ou-ji-1;
            _for(i,0,n)
            {
                if(!(a[i]&1))
                {
                    cnt--;
                    ans+=a[i];
                    if(cnt==0)
                        break;
                }
            }
        }
        pri(ans);
    }
    return 0;
}
