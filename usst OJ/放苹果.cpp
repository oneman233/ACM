#include <bits/stdc++.h>

using namespace std;

int f(int a,int b)
{
    if(a<b)
        return f(a,a);
    if(a==0||b==1)
        return 1;
    return f(a,b-1)+f(a-b,b);
    //������һ��Ϊ���Լ�ȫ������
}

int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    printf("%d",f(m,n));
    return 0;
}
