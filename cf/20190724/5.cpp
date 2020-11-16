#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <stack>
#include <map>
#include <iomanip>
#define PI acos(-1.0)
#define Max 100005
#define inf 1<<28
#define LL(x) (x<<1)
#define RR(x)(x<<1|1)
using namespace std;

int M(int x){
    return (x%3+3)%3;
}

signed main(void){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
    int q;
    cin>>q;
    while(q--){
        int b,w;
        scanf("%lld %lld",&b,&w);
        if(b<w){
            int mx = b*3+1;
            if(w>mx){
                printf("NO\n");
                continue;
            }
            printf("YES\n");
            int posx=1000000LL,posy=1000001LL;
            for(int i=0;i<b;i++){
                printf("%lld %lld\n",posx+2*i,posy);
                printf("%lld %lld\n",posx+2*i+1,posy);
            }
            for(int i=0;i<min(w,2*b)-b;i++)
            {
                printf("%lld %lld\n",posx+2*i,posy+1);
            }
            for(int i=0;i<min(w,3*b)-2*b;i++)
            {
                printf("%lld %lld\n",posx+2*i,posy-1);
            }
            if(w==mx){
                printf("%lld %lld\n",posx-1,posy);
            }
        }
        else{
            int mx = w*3+1;
            if(b>mx){
                printf("NO\n");
                continue;
            }
            printf("YES\n");
            int posx=1000000LL,posy=1000000LL;
            for(int i=0;i<w;i++){
                printf("%lld %lld\n",posx+2*i,posy);
                printf("%lld %lld\n",posx+2*i+1,posy);
            }
            for(int i=0;i<min(b,2*w)-w;i++)
            {
                printf("%lld %lld\n",posx+2*i,posy+1);
            }
            for(int i=0;i<min(b,3*w)-2*w;i++)
            {
                printf("%lld %lld\n",posx+2*i,posy-1);
            }
            if(b==mx){
                printf("%lld %lld\n",posx-1,posy);
            }
        }
    }
    return 0;
}
