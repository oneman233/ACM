#include <bits/stdc++.h>
using namespace std;

int n;
string s[105];

void dfs(int i,int j)
{
    if(i<0||i>=n||j<0||j>=s[i].length()||!isalpha(s[i][j]))
        return;
    s[i][j]='*';
    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j+1);
    dfs(i,j-1);
}

void debug()
{
    for(int i=0;i<n;++i)
        cout<<s[i]<<endl;
}

int main()
{
    int ans=0;
    scanf("%d",&n);
    getline(cin,s[0]);
    for(int i=0;i<n;++i)
        getline(cin,s[i]);
    for(int i=0;i<n;++i){
        for(int j=0;j<s[i].length();++j){
            if(isalpha(s[i][j])){
                ans++;
                dfs(i,j);
            }
        }
    }
    //debug();
    cout<<ans;
    return 0;
}
