#include <bits/stdc++.h>
using namespace std;

string a,b;

void mul()
{
    if(a=="0"||b=="0")
    {
        cout<<"0";
        return;
    }
    if(b.length()>a.length())
    {
        string tmp=a;
        a=b;
        b=tmp;
    }
    vector<int> va,vb;
    vector<int> vab[10000];
    for(int i=0;i<a.length();++i)
        va.push_back(a[i]-'0');
    for(int i=0;i<b.length();++i)
        vb.push_back(b[i]-'0');
    for(int i=vb.size()-1;i>=0;--i)
    {
        for(int j=va.size()-1;j>=0;--j)
        {
            vab[vb.size()-1-i].insert(vab[vb.size()-1-i].begin(),va[j]*vb[i]);
        }
    }
    /*
    for(int i=0;i<vb.size();++i)
    {
        for(int j=0;j<vab[i].size();++j)
        {
            cout<<vab[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    for(int i=0;i<vb.size();++i)
    {
        for(int j=0;j<i;++j)
        {
            vab[i].push_back(0);
        }
    }
    for(int i=0;i<vb.size();++i)
    {
        while(vab[i].size()<va.size()+vb.size()-1)
        {
            vab[i].insert(vab[i].begin(),0);
        }
    }
    /*
    for(int j=0;j<vb.size();++j)
    {
        for(int i=0;i<vb.size()+va.size()-1;++i)
        {
            cout<<vab[j][i]<<" ";
        }
        cout<<endl;
    }
    */
    vector<int> ans;
    for(int i=0;i<vb.size()+va.size()-1;++i)
    {
        int sum=0;
        for(int j=0;j<vb.size();++j)
        {
            sum+=vab[j][i];
        }
        ans.push_back(sum);
    }
    for(int i=ans.size()-1;i>=1;--i)
    {
        if(ans[i]>=10)
        {
            ans[i-1]+=ans[i]/10;
            ans[i]%=10;
        }
    }
    if(ans[0]>=10)
    {
        ans.insert(ans.begin(),ans[0]/10);
        ans[1]%=10;
    }
    for(int i=0;i<ans.size();++i)
        cout<<ans[i];
}

int main()
{
    cin>>a>>b;
    mul();
    return 0;
}
