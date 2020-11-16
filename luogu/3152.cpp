#include <bits/stdc++.h>
using namespace std;

int n,ans=0;

inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}

int dfs(int x)
{
    if(x==1)
        return 1;
    else{
        return 1+dfs(x/2);
    }
}

int main()
{
    n=read();
    cout<<dfs(n);
    return 0;
}
