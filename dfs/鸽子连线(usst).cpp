#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;
typedef long long ll;
const int Max=1000000;

int n,m;
char p[15][15];
int si,sj,ei,ej;
bool flag=false;

void dfs(int i,int j,int zhuan,char direct)
{
    if(i<0||i>=n||j<0||j>=m)///����
        return;
    if(zhuan==3)///ת��̫��
        return;
    if(p[i][j]=='*')///����ǽ
        return;
    p[i][j]='*';///���߻�ͷ·
    if(i==ei&&j==ej)///�����յ�
    {
        flag=true;
        return;
    }
    if(direct=='@')
    {
        ///����Lʵ�������������ݵĿ���
        dfs(i,j-1,0,'L');
        dfs(i+1,j,0,'D');
        dfs(i-1,j,0,'U');
        dfs(i,j+1,0,'R');
    }
    else if(direct=='L')
    {
        dfs(i,j-1,zhuan,'L');
        dfs(i+1,j,zhuan+1,'D');
        dfs(i-1,j,zhuan+1,'U');
    }
    else if(direct=='R')
    {
        dfs(i,j+1,zhuan,'R');
        dfs(i+1,j,zhuan+1,'D');
        dfs(i-1,j,zhuan+1,'U');
    }
    else if(direct=='U')
    {
        dfs(i-1,j,zhuan,'U');
        dfs(i,j-1,zhuan+1,'L');
        dfs(i,j+1,zhuan+1,'R');
    }
    else if(direct=='D')
    {
        dfs(i+1,j,zhuan,'D');
        dfs(i,j-1,zhuan+1,'L');
        dfs(i,j+1,zhuan+1,'R');
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    _for(i,0,n)
    {
        getchar();
        _for(j,0,m)
        {
            scanf("%c",&p[i][j]);
            if(p[i][j]=='S')
            {
                si=i;sj=j;
            }
            if(p[i][j]=='T')
            {
                ei=i;ej=j;
            }
        }
    }
    dfs(si,sj,0,'@');
    if(flag)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
