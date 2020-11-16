#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[10005];

void out()
{
    cout<<a[1];
    for(int i=2;i<=n;++i)
        cout<<" "<<a[i];
}

void change()
{
    int ix=n;
    while(ix>1&&a[ix-1]>a[ix])
        ix--;
        ///从末尾找最长递增子序列
    if(ix==1)
        return;
        ///最后一个排列了
    else{
        for(int i=n;i>=ix;--i)
            if(a[i]>a[ix-1]){
                swap(a[i],a[ix-1]);
                break;
            }
        ///找到第一个大于最长递增子序列首的数字
        ///交换它们可以使得字典序更大
        for(int i=ix,j=n;i<j;++i,--j)
            swap(a[i],a[j]);
        ///维护字典序的变化量尽量小
        ///使得序列后半段尽量递减
    }
}

int main()
{
    memset(a,0,sizeof(a));
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    while(m--)
        next_permutation(a+1,a+1+n);
    out();
    return 0;
}
