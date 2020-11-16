#include <bits/stdc++.h>
#define pri(a) printf("%d ",a)
using namespace std;

int n[10]={5,6,3,1,7,8,9,10,4,5};

void merg(int ls,int le,int rs,int re)
{
    int* tmp = (int*)malloc((re-ls+1)*sizeof(int));
    ///临时数组
    int i=ls,j=rs;
    ///左右两个区域的下标
    int k=0;
    ///临时区域的下标
    while(i <= le && j<= re)
    {
        if(n[i] < n [j])
            tmp[k++]=n[i++];
        else
            tmp[k++]=n[j++];
    }
    ///轮流进行比较找到合适的位置
    while(i <= le)
        tmp[k++]=n[i++];
    while(j <= re)
        tmp[k++]=n[j++];
    ///防止两个序列有剩余数字的情况
    for(int flag=0;flag<k;flag++)
        n[ls+flag] = tmp[flag];
    ///排好序后把值赋给原数组
    free(tmp);
    ///回收空间
}

void merg_sort(int s,int e)
{
    if(s>=e)
        return;
    ///只有一个元素
    int mid = (s+e)/2;
    merg_sort(s,mid);
    merg_sort(mid+1,e);
    ///递归拆分数组
    merg(s,mid,mid+1,e);
    ///合并数组
}

int main()
{
    for(int i=0;i<10;++i)
        pri(n[i]);
    merg_sort(0,9);
    printf("\n");
    for(int i=0;i<10;++i)
        pri(n[i]);
    return 0;
}
