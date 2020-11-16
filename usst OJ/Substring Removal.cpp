#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    char head=s[0],tail=s[n-1];
    int qian=1,hou=1,ans=1;
    for(int i=1;i<n;i++)
    {
        if(s[i]==head)
            qian++;
        else
            break;
    }
    for(int i=n-2;i>=0;i--)
    {
        if(s[i]==tail)
            hou++;
        else
            break;
    }
    if(head!=tail)
    {
        ans+=qian+hou;
        cout<<ans;
    }
    else
    {
        //cout<<qian<<" "<<hou<<" ";
        ans+=qian+hou;
        ans+=qian+hou-1;
        cout<<ans;
    }
    return 0;
}
