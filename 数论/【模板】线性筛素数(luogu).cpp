#include <bits/stdc++.h>
using namespace std;

int n,m,tmp;
int idx=0;///����prime����
int prime[500000];
int check[10000000];

inline void get_list()
{
    memset(check,0,sizeof(check));
    for(int i=2;i<=n;++i)
    {
        if(!check[i])
            prime[idx++]=i;///��������
        for(int j=0;j<idx;++j)
        {
            if(i*prime[j]>n)///����������
                break;
            check[i*prime[j]]=1;///ȥ�������ı���
            if(i%prime[j]==0)
            ///��ʱi��һ�����������ǵĳ˻�һ����һ����С�����Ѿ�ɸȥ��
                break;
        }
    }
}

int main()
{
    cin>>n>>m;
    get_list();
    for(int i=0;i<m;++i)
    {
        cin>>tmp;
        if(!check[tmp]||tmp%2==0||tmp%3==0)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    /*
    for(int i=0;i<idx;++i)
        cout<<prime[i]<<endl;
    */
    return 0;
}
