#include <bits/stdc++.h>

using namespace std;

int pow(int n)
{
    int out=1;
    for(int i=0;i<n;i++)
        out*=2;
    return out-1;
}

void hanoi(int n,char a,char b,char c)
{
    if(n==1)
        printf("%d from %c to %c\n",n,a,c);
    else
    {
        hanoi(n-1,a,c,b);
        printf("%d from %c to %c\n",n,a,c);
        hanoi(n-1,b,a,c);
    }
}

int main()
{
    int n;
    cin>>n;
    cout<<pow(n)<<endl;
    hanoi(n,'A','B','C');
    return 0;
}
