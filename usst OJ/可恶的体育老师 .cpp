#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i;
    int n;
    int xue[65],gongji[65];
    int sha_xue,sha_gongji;
    cin>>n;
    for(i=0;i<n;i++)
        scanf("%d %d",&xue[i],&gongji[i]);
    scanf("%d %d",&sha_xue,&sha_gongji);
    for(i=0;i<n;i++)
    {
        if(sha_gongji>=xue[i])//一拳超人
            ;
        else//一拳打不死
        {
            while(1)//循环狂打
            {
                xue[i]-=sha_gongji;
                if(xue[i]<=0)
                    break;
                sha_xue-=gongji[i];
                if(sha_xue<=0)
                    break;
            }
        }
        if(sha_xue<=0)
        {
            printf("oh shit!");
            return 0;
        }
    }
    printf("yes!!very good");
    return 0;
}
