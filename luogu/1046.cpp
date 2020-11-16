#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h[10];
    for(int i=0;i<10;i++)
        cin>>h[i];
    int x;
    cin>>x;
    int ans=0;
    for(int i=0;i<10;i++)
    {
        if(h[i]<=(x+30))
            ans++;
    }
    cout<<ans;
    return 0;
}
