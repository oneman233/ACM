#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    bool lock=false;
    cin>>m;
    while(m--)
    {
        lock=false;
        cin>>n;
        if(n==0)
        {
            cout<<"210"<<endl;
            continue;
        }
        if(n==1)
        {
            cout<<"310"<<endl;
            continue;
        }
        for(int i=20;i>=3;i--)
        {
            for(int j=20;j>=0;j--)
            {
                for(int k=0;k<=20;k++)
                {
                    if(i*(i-1)*(i-2)/6+j*(j-1)/2+k==n)
                    {
                        if(lock==false)
                        {
                            cout<<i<<j<<k<<endl;
                            lock=true;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
