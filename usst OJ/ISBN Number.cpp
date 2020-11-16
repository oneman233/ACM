#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,shibie;
    int temp1,temp2,temp3;
    int right;
    scanf("%d-%d-%d-%d",&a,&b,&c,&shibie);
    temp1=a;
    temp2=b;
    temp3=c;
    right=a*1;
    for(int i=4;i>=2;i--)
    {
        right+=b%10*i;
        b/=10;
    }
    for(int i=9;i>=5;i--)
    {
        right+=c%10*i;
        c/=10;
    }
    right%=11;
    if(right==shibie)
        printf("Right");
    else
    {
        if(right==10)
            printf("%d-%03d-%05d-X",temp1,temp2,temp3);
        else
            printf("%d-%03d-%05d-%d",temp1,temp2,temp3,right);
    }
    return 0;
}
