#include <bits/stdc++.h>
#define scs(a) scanf("%s",a)
#define scii(a,b) scanf("%d %d",&a,&b)
#define pri(a) printf("%d\n",a)
using namespace std;
const int maxn=1000005;

int n,m;
int as[105][105];

int c2i(char c)
{
    return c-'A';
}

struct trie
{
    int son[maxn][26];
    int tt;
    int dep[maxn],ct[maxn];
    bool fg[maxn];
    trie()
    {
        memset(son,0,sizeof(0));
        memset(fg,0,sizeof(fg));
        memset(ct,0,sizeof(ct));
        tt=1;
    }
    void in(char s[])
    {
        int p=1;
        for(int i=0;i<strlen(s);++i){
            int ch=c2i(s[i]);
            dep[p]=i+1;
            ct[tt]++;
            if(son[p][ch]==0){
                tt++;
                son[p][ch]=tt;
            }
            ///the node doesn't exist
            p=son[p][ch];
        }
        fg[tt]=true;
    }
    void cal()
    {

    }
}t;

int main()
{
    scii(n,m);
    for(int i=1;i<=n;++i){
        char s[105];
        scs(s);
        t.in(s);
    }
    t.cal();
    int x,y;
    while(m--){
        scii(x,y);
        pri(as[y]-as[x-1]);
    }
    return 0;
}
