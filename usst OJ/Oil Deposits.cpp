#include <bits/stdc++.h>

using namespace std;

const int MAX=100;

char oil[MAX+10][MAX+10];
int x,y;

void dfs(int i,int j)
{
    if(i<0||j<0||i>=x||j>=y)
        return;//严防出界
    if(oil[i][j]!='@')
        return;//不是油田不检查
    oil[i][j]='*';
    dfs(i+1,j);
    dfs(i,j+1);
    dfs(i-1,j);
    dfs(i,j-1);
    dfs(i+1,j+1);
    dfs(i-1,j-1);
    dfs(i+1,j-1);
    dfs(i-1,j+1);
}

int main()
{
    while(scanf("%d %d",&x,&y))
    {
        if(x==0&&y==0)
            break;
        for(int i=0;i<x;i++)
            scanf("%s",oil[i]);
        int shu=0;
        //防止一块油田都没有的情况
        //一旦有油田则从1开始编号
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
            {
                if(oil[i][j]=='@')
                {
                    dfs(i,j);
                    shu++;
                }
            }
        }
        cout<<shu<<endl;
    }
    return 0;
}
