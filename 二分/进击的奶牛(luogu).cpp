#include <bits/stdc++.h>
using namespace std;

int n,c;
int x[100005];

bool check(int nu)
{
    ///此时nu是可能的最短距离
    int sum=0;
    int l=x[0];
    for(int i=1;i<n;++i)
    {
        if(x[i]-l<nu)
        ///如果某一头牛距离上一头牛的距离必nu小
        ///这意味着我们必须把这头牛放到下一个牛栏里去
        ///这样才能保证nu是最小距离
            sum++;
        else
        ///如果某一头牛距离上一头牛的距离大于等于nu
        ///说明该牛栏没问题，可以放牛
            l=x[i];
        if(sum>(n-c))
        ///事实上，num记录的是空出来的牛栏数
        ///如果需要空出来的牛栏数大于最大空闲牛栏数
        ///该答案一定不可行
            return false;
    }
    return true;
}

int half()
{
    int l=1;
    int r=x[n-1]-x[0];
    ///最大答案是a[n-1]-a[0]，最小答案是1
    while(l+1<r)
    ///为什么是l+1<r呢？
    ///首先如果开l<r的话会死循环
    ///实际上我们希望的遍历终点是l+1=r
    ///这样只需要尽量取出较大的那个答案即可
    ///所以下面检查的时候先检查r再检查l
    {
        int mid=(l+r)/2;
        if(check(mid))
            l=mid;
        else
            r=mid;
        ///想要答案尽量大，那么就要尽量到大数区域里找答案
    }
    if(check(r))
        return r;
    if(check(l))
        return l;
}

int main()
{
    cin>>n>>c;
    for(int i=0;i<n;++i)
        cin>>x[i];
    sort(x,x+n);
    ///二分到有序数组里找答案
    cout<<half();
    return 0;
}
