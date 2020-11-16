#include <bits/stdc++.h>
using namespace std;

void mov(int i,char a,char b)
{
    cout<<i<<":"<<a<<"->"<<b<<endl;
}

void hanoi(int i,char a,char b,char c)//��a����c�ƶ���b��
{
    if(i==1)
        mov(i,a,c);//����1��ʱ��ֱ���ƶ�������1��С��һ����������
    else
    {
        hanoi(i-1,a,c,b);
        mov(i,a,c);
        hanoi(i-1,b,a,c);
    }
}

int main()
{
    int n;
    cin>>n;
    hanoi(n,'A','B','C');
    return 0;
}
