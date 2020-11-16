#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v,n;
    while(cin>>v>>n)
    {
        int ans=0;
        if(v==0)
            break;
        int p[1000],m[1000];
        for(int i=0;i<n;++i)
            cin>>p[i]>>m[i];
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                if(p[j]>p[i])
                {
                    int temp;
                    temp=p[j];
                    p[j]=p[i];
                    p[i]=temp;
                    temp=m[j];
                    m[j]=m[i];
                    m[i]=temp;
                }
            }
        }
        int i=0;
        while(1)
        {
            while(m[i]!=0)
            {
                ans+=p[i];
                m[i]--;
                v--;
                if(v==0)
                    break;
            }
            ++i;
            if(i==n||v==0)
                break;
        }
        cout<<ans<<endl;
    }
    return 0;
}
