#include <bits/stdc++.h>
using namespace std;

bool cmp(string a,string b)
{
    return a+b>b+a;
}

int main()
{
    int n;
    string ans="",temp[25];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>temp[i];
    }
    sort(temp,temp+n,cmp);
    for(int i=0;i<n;i++)
    {
        ans+=temp[i];
    }
    for(int i=0;i<ans.length();i++)
    {
        if(ans[i]!='0')
        {
            cout<<ans;
            return 0;
        }
    }
    cout<<0;
    return 0;
}
