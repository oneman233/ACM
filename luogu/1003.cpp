#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define _rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;
const long long INF=0x3f3f3f3f;

int main()
{
    int n;
    int a,b,g,k;
    vector<int> v;
    int x,y;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d %d %d",&a,&b,&g,&k);
        v.push_back(a);
        v.push_back(b);
        v.push_back(g);
        v.push_back(k);
    }
    scanf("%d %d",&x,&y);
    for(int i=v.size()-1;i>=0;i-=4)
    {
        if(x<=v[i-3]+v[i-1]&&y<=v[i-2]+v[i]&&x>=v[i-3]&&y>=v[i-2])
        {
            printf("%d",i/4+1);
            return 0;
        }
    }
    printf("-1");
    return 0;
}
