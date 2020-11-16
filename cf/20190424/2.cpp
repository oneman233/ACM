#include <bits/stdc++.h>
using namespace std;

vector<int> v,ans;
map<int,bool> m;
int x;
bool can=false;

bool chk(int a)
{
    int i=20;
    while((a&(1<<i))==0)
        --i;
    while(a&(1<<i))
        --i;
    if(i==-1)
        return true;
    else
        return false;
}

void dfs(int a,int b)
{
    if(chk(a)&&b<=41&&!can)
    {
        cout<<b-1<<endl;
        can=true;
        for(int i=0;i<ans.size();++i){
            cout<<ans[i];
            if(i!=ans.size()-1)
                cout<<" ";
        }
    }
    if(b>40||can)
        return;
    if(b%2==0)
        dfs(a+1,b+1);
    else
    {
        for(int i=0;i<v.size()&&m[v[i]]==false;++i)
        {
            ans.push_back(i);
            m[v[i]]=true;
            dfs(a^v[i],b+1);
            ans.pop_back();
            m[v[i]]=false;
        }
    }
}

int main()
{
    cin>>x;
    for(int i=0;i<=20;++i){
        v.push_back((1<<i)-1);
        m[v[i]]=false;
    }
    if(chk(x))
        cout<<0;
    else
        dfs(x,1);
    return 0;
}
