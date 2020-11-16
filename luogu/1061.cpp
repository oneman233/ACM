#include <bits/stdc++.h>
using namespace std;

int s,t,w;
string in,tmp="";
bool vis[1000];
vector<string> ans;

void put()
{
    for(auto i:ans)
        cout<<i<<endl;
}

void dfs(char x)
{
    ///cout<<tmp<<endl;
    if(tmp.length()==w)
    {
        ans.push_back(tmp);
        return;
    }
    for(char i=x;i<='a'+t-1;++i)
    {
        if(!vis[i])
        {
            vis[i]=true;
            tmp.append(1,i);
            dfs(i);
            vis[i]=false;
            tmp.erase(tmp.end()-1);
        }
    }
}

int main()
{
    memset(vis,0,sizeof(vis));
    cin>>s>>t>>w;
    cin>>in;
    dfs('a'+s-1);
    ///put();
    int i=0;
    while(i<ans.size()){
        if(ans[i]==in)
            break;
        ++i;
    }
    int cnt=5;
    while(++i<ans.size()&&--cnt>=0)
        cout<<ans[i]<<endl;
    return 0;
}
