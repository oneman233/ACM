#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a,b,c;
        long long ans=1;
        cin>>a>>b>>c;
        for(int i=0;i<(a+b+c);i++)
            ans*=2;
        cout<<ans<<endl;
    }
    return 0;
}
