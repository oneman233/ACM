#include <iostream>

using namespace std;

int main()
{
    int d,p;
    scanf("%d %d",&d,&p);
    //d����ʯ��p����
    if(p==3)
        printf("%d",d-1);
    else
        printf("%d",d-(p/2+1));
    return 0;
}
