#include <bits/stdc++.h>
using namespace std;

int n,c;
int x[100005];

bool check(int nu)
{
    ///��ʱnu�ǿ��ܵ���̾���
    int sum=0;
    int l=x[0];
    for(int i=1;i<n;++i)
    {
        if(x[i]-l<nu)
        ///���ĳһͷţ������һͷţ�ľ����nuС
        ///����ζ�����Ǳ������ͷţ�ŵ���һ��ţ����ȥ
        ///�������ܱ�֤nu����С����
            sum++;
        else
        ///���ĳһͷţ������һͷţ�ľ�����ڵ���nu
        ///˵����ţ��û���⣬���Է�ţ
            l=x[i];
        if(sum>(n-c))
        ///��ʵ�ϣ�num��¼���ǿճ�����ţ����
        ///�����Ҫ�ճ�����ţ��������������ţ����
        ///�ô�һ��������
            return false;
    }
    return true;
}

int half()
{
    int l=1;
    int r=x[n-1]-x[0];
    ///������a[n-1]-a[0]����С����1
    while(l+1<r)
    ///Ϊʲô��l+1<r�أ�
    ///���������l<r�Ļ�����ѭ��
    ///ʵ��������ϣ���ı����յ���l+1=r
    ///����ֻ��Ҫ����ȡ���ϴ���Ǹ��𰸼���
    ///�����������ʱ���ȼ��r�ټ��l
    {
        int mid=(l+r)/2;
        if(check(mid))
            l=mid;
        else
            r=mid;
        ///��Ҫ�𰸾�������ô��Ҫ�����������������Ҵ�
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
    ///���ֵ������������Ҵ�
    cout<<half();
    return 0;
}
