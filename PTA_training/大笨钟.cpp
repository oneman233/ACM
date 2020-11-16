#include <bits/stdc++.h>
using namespace std;

void qiao(int ci)
{
    for(int i=0;i<ci;i++)
        printf("Dang");
}

int main()
{
    int h,m;
    scanf("%d:%d",&h,&m);
    int time=h*60+m;
    if(time>=0&&time<=720)
        printf("Only %02d:%02d.  Too early to Dang.",h,m);
    else
    {
        if(time%60==0)
            qiao((time-720)/60);
        else
            qiao((time-720)/60+1);
    }
    return 0;
}
