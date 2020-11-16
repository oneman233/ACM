#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<string,int> m;
    map<string,int>::iterator it,maxit;
    int n,i,j;
    string temp;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>temp;
        m[temp]++;
    }
    if(m.size()==1)
    {
        cout<<"1";
        return 0;
    }
    int maxn=0;
    for(it=m.begin();it!=m.end();it++)
    {
        if(it->second>maxn)
        {
            maxn=it->second;
            maxit=it;
        }
    }
    int sum=0;
    for(it=m.begin();it!=m.end();it++)
    {
        if(it!=maxit)
            sum+=it->second;
    }
    if(sum>=maxn-1)
    {
        cout<<n;
    }
    else
    {
        cout<<n+sum-maxn+1;
    }
    return 0;
}
