#include <bits/stdc++.h>

using namespace std;

int sumout=0;
int n;
int out[405];//������400���ַ�

void shuchu(int * out,int n)
{
    for(int i=0;i<2*n;i++)
    {
        if(out[i]==1)
            cout<<"(";
        else if(out[i]==2)
            cout<<")";
    }
    cout<<"\n";
}

void dfs(int tian,int i,int zuo,int you)
//�������������ڼ�¼Ŀǰ�����Ÿ����������Ÿ���
{
    if(zuo>n||you>n||you>zuo)
    //����Ĺ���
    //�����Ŷ��������ţ��˳�
        return;
    if(tian==1)
    {
        out[i]=1;
        dfs(2,i+1,zuo,you+1);
        //���������ž�������������
        dfs(1,i+1,zuo+1,you);
    }
    if(tian==2)
    {
        out[i]=2;
        dfs(2,i+1,zuo,you+1);
        //����������Ҳ������������
        dfs(1,i+1,zuo+1,you);
    }
    if((zuo==you)&&(zuo+you==2*n)&&(i==(2*n-1)))
    //�㶨������������һ�����
    //ȫ���������������
    {
        shuchu(out,n);
        sumout++;
        return;
    }
}

int main()
{
    cin>>n;
    dfs(1,0,1,0);//��0��ʼ��������
    cout<<sumout;
    return 0;
}
