#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    int ans=0;
    int x[1005],y[1005];
    cin>>m;
    while(m--)
    {
        ans=0;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>x[i]>>y[i];
        for(int i=0;i<n;i++)
        {
            int Min=y[i];
            int temp=i;
            for(int j=i+1;j<n;j++)
            {
                if(y[j]<Min)
                {
                    Min=y[j];
                    temp=j;
                }
            }
            if(temp!=i)
            {
                swap(x[i],x[temp]);
                swap(y[i],y[temp]);
            }
        }
        int End=0;
        for(int i=0;i<n;i++)
        {
            if(x[i]>End)
            {
                ans++;
                End=y[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
