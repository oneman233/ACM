#include <bits/stdc++.h>
using namespace std;

int sum(int x)
{
    int sum=0;
    while(x)
    {
        sum+=x%10;
        x/=10;
    }
    return sum;
}

int main()
{
    int t,a;
    cin>>t;
    while(t--)
    {
        int ans;
        cin>>a;
        string s,sa="";
        stringstream ss,ssa;
        ss<<a;
        ss>>s;
        for(int i=0;i<s.length()-1;++i)
            sa.append(1,'9');
        if(s[0]==1)
            sa.append(1,'9');
        else
            sa.append(1,s[0]-1+'0');
        ssa<<sa;
        ssa>>ans;
        cout<<sum(ans)+sum(a-ans)<<endl;
    }
    return 0;
}
