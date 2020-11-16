#include <bits/stdc++.h>
using namespace std;

void mov(int i,char a,char b)
{
    cout<<i<<":"<<a<<"->"<<b<<endl;
}

void hanoi(int i,char a,char b,char c)//从a经过c移动到b上
{
    if(i==1)
        mov(i,a,c);//等于1的时候直接移动，反正1最小，一定放最上面
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
