#include <bits/stdc++.h>
#define pri(a) printf("%d ",a)
using namespace std;

int n[10]={5,6,3,1,7,8,9,10,4,5};

void merg(int ls,int le,int rs,int re)
{
    int* tmp = (int*)malloc((re-ls+1)*sizeof(int));
    ///��ʱ����
    int i=ls,j=rs;
    ///��������������±�
    int k=0;
    ///��ʱ������±�
    while(i <= le && j<= re)
    {
        if(n[i] < n [j])
            tmp[k++]=n[i++];
        else
            tmp[k++]=n[j++];
    }
    ///�������бȽ��ҵ����ʵ�λ��
    while(i <= le)
        tmp[k++]=n[i++];
    while(j <= re)
        tmp[k++]=n[j++];
    ///��ֹ����������ʣ�����ֵ����
    for(int flag=0;flag<k;flag++)
        n[ls+flag] = tmp[flag];
    ///�ź�����ֵ����ԭ����
    free(tmp);
    ///���տռ�
}

void merg_sort(int s,int e)
{
    if(s>=e)
        return;
    ///ֻ��һ��Ԫ��
    int mid = (s+e)/2;
    merg_sort(s,mid);
    merg_sort(mid+1,e);
    ///�ݹ�������
    merg(s,mid,mid+1,e);
    ///�ϲ�����
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
