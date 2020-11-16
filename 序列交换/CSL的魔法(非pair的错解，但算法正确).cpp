#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define sci(a) scanf("%d",&a)
#define scll(a) scanf("%lld",&a)
#define scc(a) scanf("%c",&a)
#define pb(a) push_back(a)
#define prti(a) printf("%d\n",a)
#define prtll(a) printf("%lld\n",a)
using namespace std;
typedef long long ll;
const int Max=100000;
const ll mod=998244353;

bool cmp(int a,int b)
{
    return a>b?true:false;
}

int minswap(vector<int> a,bool flag)
{
    vector<int> b(a);///复制向量
    if(flag)
        sort(b.begin(),b.end());
    else
        sort(b.begin(),b.end(),cmp);
    ///flag为1是由小到大，为0是由大到小
    map<int,int> m;
    int len=b.size();
    _for(i,0,len)
        m[b[i]]=i;
    ///m储存的是序列中的某个数字应该在的位置
    vector<bool> isask(len,false);///表示是否被访问
    int loop=0;///循环节个数
    _for(i,0,len)
    {
        if(!isask[i])
        {
            int j=i;
            while(!isask[j])
            {
                isask[j]=true;
                j=m[a[j]];
                ///j要往这个数字应该在的位置上去遍历以下
                ///如果这个数字被其他的数字占据，则要去遍历那个数字应该在的位置
                ///直到构成一个环或者没有环单所有数字都被访问了一遍
            }
            loop++;
        }
    }
    return len-loop;
}

int main()
{
    int n,read;
    vector<int> a,b;
    sci(n);
    _for(i,0,n)
    {
        sci(read);
        a.pb(read);
    }
    _for(i,0,n)
    {
        sci(read);
        b.pb(read);
    }
    prti(min((minswap(a,1)+minswap(b,0)),(minswap(a,0)+minswap(b,1))));
    ///不一定有序，只需要两两互相匹配就行
    return 0;
}
