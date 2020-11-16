#include <bits/stdc++.h>

using namespace std;

char m[20];

void to10(int &n){
    int t=1;
    int r=0;
    while(n){
        r+= n%10*t;
        n/=10;
        t*=8;
    }
    n=r;
}

void to16(int n){
    if(n==0){
        printf("0\n");
        return;
    }
    if(n<0)
        printf("-");
    char q[10];
    int len=0;
    while(n){
        q[len++]=m[n%16];
        n/=16;
    }
    for(int i=len-1; i>-1; --i)
        printf("%c",q[i]);
    puts("");
}

int main()
{
    for(int i=0; i<10; ++i)
        m[i]= '0'+ i;
    for(int i=10; i<16; ++i)
        m[i]= 'a'+ i- 10;
    int n;
    scanf("%d",&n);
    while(n--){
        int a,b;
        scanf("%d%d",&a,&b);
        to10(a);
        to10(b);
        to16(a+b);
    }

    return 0;
}
