#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,tiao[10005];
    int bu[10005];//�ִ�ĳһ���������С����
    for(int i=0;i<10005;i++)
        bu[i]=1000000;//��ȫ����Ϊ���޴�
    bu[0]=0;//�ִ��0����Ҫ�κβ���
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>tiao[i];
    for(int i=0;i<n;i++)
    {
        if(i+tiao[i]>=n&&bu[i]!=1000000)//һ�����ӣ�ֱ�����
        {
            cout<<bu[i]+1;
            return 0;
        }
        for(int j=1;j<=tiao[i];j++)
            bu[i+j]=min(bu[i]+1,bu[i+j]);
    }
    cout<<"-1";//����������ѭ���������޷��ִ��ô��û�취�ִ�԰�
    return 0;
}
