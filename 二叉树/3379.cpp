#include <bits/stdc++.h>
using namespace std;

int de[],fa[][];

void dfs(int x,int fax)
{
    de[x]=de[fax]+1;
    fa[x][0]=x;
    for(int i=1;(1<<i)<de[fax];++i)
        fa[x][i]=fa[fa[f][i-1]][i-1];
}

int main()
{

    return 0;
}
