#include <bits/stdc++.h>

using namespace std;

int main()
{
    double x1,x2,y1,y2,x,y;
    scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
    x=x1+x2;
    y=y1+y2;
    if(x>-0.05&&x<0.05)
        x=0.0;
    if(y>-0.05&&y<0.05)
        y=0.0;
    printf("(%.1lf, %.1lf)",x,y);
    return 0;
}
