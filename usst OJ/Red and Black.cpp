#include <bits/stdc++.h>

using namespace std;

char pic[25][25];
int x,y;
int out=1;
int hang,lie;

void dfs(int i,int j)
{
    if(i<0||j<0||i>=x||j>=y)
        return;
    if(pic[i][j]=='!'||pic[i][j]=='#')
        return;
    else if(pic[i][j]=='.')
    {
        out++;
        pic[i][j]='!';
    }
    dfs(i+1,j);
    dfs(i,j+1);
    dfs(i-1,j);
    dfs(i,j-1);
}

int main()
{
    while(cin>>y>>x)
    {
        for(int i=0;i<x;i++)//读入一张图
            scanf("%s",pic[i]);
        if(x==0&&y==0)
            break;
        for(int i=0;i<x;i++)//找到起点
        {
            for(int j=0;j<y;j++)
            {
                if(pic[i][j]=='@')
                {
                    hang=i;
                    lie=j;
                    break;
                }
            }
        }
        dfs(hang,lie);
        cout<<out<<endl;
        out=1;
    }
    return 0;
}
