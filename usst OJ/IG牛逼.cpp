#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int a[1005];
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
            /*左端点最短，右端点最长*/
        int big=0,sma=1000005;
        for(int i=0;i<n;i++)
        {
            big=max(big,a[i]);
            sma=min(sma,a[i]);
        }
        int left,right;
        for(int i=0;i<n;i++)
        {
            if(a[i]==sma)
            {
                left=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]==big)
            {
                right=i;
                break;
            }
        }
        if(right>=left)
            cout<<right-left<<endl;
        else
            cout<<0<<endl;
    }
    return 0;
}
