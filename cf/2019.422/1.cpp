#include <bits/stdc++.h>
using namespace std;

int n,l,r;
string s;
bool can=false;

int main()
{
    cin>>n;
    cin>>s;
    for(int i=0;i<n-1;++i)
    {
        if(s[i+1]<s[i])
        {
            l=i;
            r=i+1;
            can=true;
            break;
        }
    }
    if(can)
    {
        cout<<"YES"<<endl;
        cout<<l+1<<" "<<r+1;
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}
