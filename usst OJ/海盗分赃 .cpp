#include <iostream>

using namespace std;

int main()
{
    int d,p;
    scanf("%d %d",&d,&p);
    //d个钻石，p个人
    if(p==3)
        printf("%d",d-1);
    else
        printf("%d",d-(p/2+1));
    return 0;
}
