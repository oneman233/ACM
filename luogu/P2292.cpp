#include <bits/stdc++.h>
using namespace std;
const int maxn=1000001;

int n,m;
int trie[10000][26],tot=1;
bool isend[10000];
char s[maxn];
int len,ans=0;

void add(char s[])
{
    int len=strlen(s);
    int p=1;
    for(int i=0;i<len;++i){
        int pos=s[i]-'a';
        if(trie[p][pos]==0)
            trie[p][pos]=++tot;
        p=trie[p][pos];
    }
    isend[p]=true;
}

void dfs(int node,int pos)
{
    if(pos>len||node==0)
        return;
    if(isend[node]){
        ans=max(ans,pos);
        if(trie[1][s[pos]-'a']!=0)
            dfs(1,pos);
        if(trie[node][s[pos]-'a']!=0)
            dfs(trie[node][s[pos]-'a'],pos+1);
    }
    else
        if(trie[node][s[pos]-'a']!=0)
            dfs(trie[node][s[pos]-'a'],pos+1);
}

int main()
{
    memset(trie,0,sizeof(trie));
    memset(isend,0,sizeof(isend));
    scanf("%d %d",&n,&m);
    while(n--){
        scanf("%s",s);
        add(s);
    }
    while(m--){
        scanf("%s",s);
        ans=0;
        len=strlen(s);
        dfs(1,0);
        printf("%d\n",ans);
    }
    return 0;
}
