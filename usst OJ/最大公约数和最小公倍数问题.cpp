#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
    while(b!=0)
    {
        int i=a%b;
        a=b;
        b=i;
    }
    return a;
}
//�뷨Ӧ���������˻��������Լ������С������֮�˻�
int main()
{
    int x,y;
    int out=0;
    cin>>x>>y;
    if(x==y)
    {
        cout<<"1";
        return 0;
    }
    int cheng=x*y;
    for(int i=x;i<=sqrt(cheng);i++)
    {
        if((cheng%i==0)&&(gcd(cheng/i,i)==x))
            out++;
    }
    printf("%d",out*2);
    return 0;
}
