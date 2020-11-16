#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;
typedef long long ll;
const int Max=1000000;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        string a[100][100];
        cin>>n>>m;
        _for(i,0,n)
        {
            _for(j,0,m)
            {
                cin>>a[i][j];
            }
        }
        bool flag=true;
        int cnt=n*m;
        _for(i,0,n)
        {
            if(flag)
            {
                for(int j=0;j<m;++j)
                {
                    cout<<a[i][j];
                    cnt--;
                    if(cnt!=0)
                        cout<<" ";
                }
                flag=false;
            }
            else
            {
                for(int j=m-1;j>=0;--j)
                {
                    cout<<a[i][j];
                    cnt--;
                    if(cnt!=0)
                        cout<<" ";
                }
                flag=true;
            }
        }
        if(t!=0)
            cout<<endl;
    }
    return 0;
}
