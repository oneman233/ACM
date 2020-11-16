#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;

int main()
{
    int m;
    cin>>m;
    while(m--)
    {
        int n;
        int s[1005],e[1005];
        cin>>n;
        _for(i,0,n)
            cin>>s[i]>>e[i];
        _for(i,0,n)
        {
            _for(j,i,n)
            {
                if(e[j] < e[i])
                {
                    swap(s[i],s[j]);
                    swap(e[i],e[j]);
                }
            }
        }
        int temp=e[0];
        int ans=1;
        _for(i,1,n)
        {
            if(s[i]>temp)
            {
                ans++;
                temp=e[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
///早结束的往前排就完事儿了
