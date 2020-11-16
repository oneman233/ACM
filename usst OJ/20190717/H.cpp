#include <bits/stdc++.h>
using namespace std;
const int maxn=5000005;

int n,ans=0;
int tr[maxn][2],tot=1;
int cnt[maxn];
char s[10000][205];

int mx(int x,int y)
{
    return x>y?x:y;
}

void in(char s[])
{
    int len=strlen(s),p=1;
    for(int i=0;i<len;++i)
    {
        if(tr[p][s[i]-'0']==0)
            tr[p][s[i]-'0']=++tot;
        p=tr[p][s[i]-'0'];
        cnt[p]++;
    }
}

void _search(char s[])
{
    int len=strlen(s),p=1;
    for(int i=0;i<len;++i)
    {
        p=tr[p][s[i]-'0'];
        ans=mx(ans,cnt[p]*(i+1));
    }
    ans=mx(ans,len);
}

int main()
{
    memset(cnt,0,sizeof(cnt));
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%s",s[i]);
        in(s[i]);
    }
    //search(s[0]);
    for(int i=0;i<n;++i)
        _search(s[i]);
    printf("%d",ans);
    return 0;
}
/*
4
0000
0001
10101
010

2
01010010101010101010
11010010101010101010

5
00
00
00
00
11
*/
