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
        ///��ĩβ�������������
    if(ix==1)
        return;
        ///���һ��������
    else{
        for(int i=n;i>=ix;--i)
            if(a[i]>a[ix-1]){
                swap(a[i],a[ix-1]);
                break;
            }
        ///�ҵ���һ������������������׵�����
        ///�������ǿ���ʹ���ֵ������
        for(int i=ix,j=n;i<j;++i,--j)
            swap(a[i],a[j]);
        ///ά���ֵ���ı仯������С
        ///ʹ�����к��ξ����ݼ�
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
