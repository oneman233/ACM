#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define _rep(i,a,b) for(int i=(a);i<=(b);i++)

const int INF=1e+6;

using namespace std;

bool operator>(const string& a,const string& b)
{
    _for(i,0,min(a.length(),b.length()))
    {
        if(a[i]>b[i])
            return true;
        if(a[i]<b[i])
            return false;
    }
    if(a.length()>b.length())
        return false;
    if(a.length()<=b.length())
        return true;
}

int main()
{
    int n,big_idx;
    string temp[25];
    string big;
    string ans="";
    cin>>n;
    _for(i,0,n)
    {
        cin>>temp[i];
    }
    _for(i,0,n)
    {
        big=temp[i];
        big_idx=i;
        _for(j,i+1,n)
        {
            if(temp[j]>big)
            {
               big=temp[j];
               big_idx=j;
            }
        }
        if(big_idx!=i)
        {
            string trans=temp[i];
            temp[i]=temp[big_idx];
            temp[big_idx]=trans;
        }
    }
    _for(i,0,n)
    {
        ans+=temp[i];
    }
    _for(i,0,n)
    {
        if(ans[i]!='0')
        {
            cout<<ans;
            return 0;
        }
    }
    cout<<"0";
    return 0;
}
