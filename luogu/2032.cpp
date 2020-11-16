#include <bits/stdc++.h>
using namespace std;
const int maxn=2000000;

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

int n,k;
deque<int> d;
int a[maxn+5];

int main()
{
    n=read();
    k=read();
    for(int i=1;i<=n;++i)
        a[i]=read();
    d.push_back(1);
    for(int i=2;i<=k;++i){
        while(!d.empty()&&a[i]>=a[d.back()])
            d.pop_back();
        d.push_back(i);
    }
    cout<<a[d.front()]<<endl;
    int i=k+1;
    while(i<=n){
        while(!d.empty()&&a[i]>=a[d.back()])
            d.pop_back();
        d.push_back(i);
        while(d.back()-d.front()+1>k)
            d.pop_front();
        cout<<a[d.front()]<<endl;
        ++i;
    }
    return 0;
}
