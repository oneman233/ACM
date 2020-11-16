#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define _rep(i,a,b) for(int i=(a);i<=(b);i++)

const long long INF=0x3f3f3f3f;

using namespace std;

int main()
{
    int n,num;
    long long small_he=0,big_he=0;
    //小（大）于区间总和
    int l,r;
    long long rand;//可自由分配空间
    vector<int> v;
    scanf("%d",&n);
    _for(i,0,n)
    {
        scanf("%d",&num);
        v.push_back(num);
    }
    scanf("%d %d",&l,&r);
    _for(i,0,n)
    {
        if(v[i]<l)
        {
            small_he+=l-v[i];
        }
        if(v[i]>r)
        {
            big_he+=v[i]-r;
        }
    }
    if(big_he==small_he)//刚好互相填满
    {
        printf("%lld",big_he);
        return 0;
    }
    if(big_he>small_he)
    {
        rand=0;
        _for(i,0,n)
        {
            if(v[i]<=r)
            {
                rand+=r-v[i];
            }
        }
        if(rand>=big_he)
        {
            printf("%lld",big_he);
        }
        else
        {
            printf("-1");
        }
    }
    if(small_he>big_he)
    {
        rand=0;
        _for(i,0,n)
        {
            if(v[i]>=l)
            {
                rand+=v[i]-l;
            }
        }
        if(rand>=small_he)
        {
            printf("%lld",small_he);
        }
        else
        {
            printf("-1");
        }
    }
    return 0;
}
