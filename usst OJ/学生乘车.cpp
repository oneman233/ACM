#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,b;
    int tempa,tempb;
    int ans=0;
    int sex;
    string s;
    cin>>n>>a>>b;
    tempa=a;tempb=b;
    cin>>s;
    if(a>=b)
        sex=1;
    else
        sex=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='.')
        {
            if(sex==1)
            {
                a--;
                ans++;
                sex=0;
            }
            else
            {
                b--;
                ans++;
                sex=1;
            }
        }
        else
        {
            if(a>=b)
                sex=1;
            else
                sex=0;
        }
    }
    if(ans>=tempa+tempb)
    {
        cout<<tempa+tempb;
    }
    else
    {
        cout<<ans;
    }
    return 0;
}
