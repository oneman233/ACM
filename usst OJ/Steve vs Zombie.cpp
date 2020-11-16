#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);i++)

using namespace std;

int x,y,n;
//x群体伤害，y单体伤害
int ri=0;//群体伤害会累加
int blood;
long long ans=0;
priority_queue<int,vector<int>,greater<int> > q;

int main()
{
    scanf("%d %d %d",&n,&x,&y);
    _for(i,0,n)
    {
        scanf("%d",&blood);
        q.push(blood);
    }
    if(x!=0&&y==0)
    {
        ans=q.top()/x;
    }
    else if(x==0&&y!=0)
    {
        int sum=0;
        while(!q.empty())
        {
            sum+=q.top();
            q.pop();
        }
        ans=sum/y;
    }
    else if(x==0&&y==0)
    {
        ans=-1;
    }
    else
    {
        ri=x;
        ans=1;
        while(!q.empty())
        {
            while((ans+ri)<q.top())
            {
                ri+=x;
                ans++;
            }
            q.pop();
        }
    }
    printf("%lld",ans);
    return 0;
}
