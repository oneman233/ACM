#include <bits/stdc++.h>

using namespace std;

int n,m,l;
//n���㣬m�����l������
int a,b,x[200005];
//��������x��
int man;
//��������λ��
int ans[200005];
//�����

int main()
//������飬����++�����޵���һ��--����������
{
    memset(x,0,sizeof(x));
    cin>>n>>m>>l;
    while(n--)
    {
        cin>>a>>b;
        if(b>l)
            continue;
        else if(b==l)
        {
            x[a]++;
            x[a+1]--;
        }
        else//b<l�����
        {
            if(a+b-l<0)
                x[0]++;
            else
                x[a+b-l]++;
            if(a+l-b>200000);//������ʮ��ľͱ����
            else
                x[a+l-b+1]--;
        }
    }
    ans[0]=x[0];
    for(int i=1;i<=200000;i++)
        ans[i]=ans[i-1]+x[i];
    while(m--)
    {
        cin>>man;
        cout<<ans[man]<<endl;
    }
    return 0;
}
