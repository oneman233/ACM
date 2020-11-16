#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<vector>
#include<map>
#include<functional>
#include<cmath>

#define fst first
#define sc second
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,root<<1
#define rson mid+1,r,root<<1|1
#define lc root<<1
//#define rc root<<1|1
#define lowbit(x) ((x)&(-x))

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PI;
typedef pair<ll,ll> PLL;

const db eps = 1e-6;
const int mod = 1e9+7;
const int maxn = 2e6+100;
const int maxm = 2e6+100;
const int inf = 0x3f3f3f3f;


int n;
char s1[maxn];
char s2[maxn];
int A,a,B,b,C,c,D,d;
int main(){
    scanf("%d", &n);
    scanf("%s", s1+1);
    scanf("%s", s2+1);
    for(int i = 1; i <= n; i++){
        if(s1[i]=='0'){
            if((s2[i]=='0'))A++;
            else B++;
        }
        else{
            if(s2[i]=='0')C++;
            else D++;
        }
    }
    int mm = min(A, n/2);
    a = b = c = d = -1;
    int ys = 0;
    for(a = 0; a <= A && a <= n/2; a++){
        if(B+D-n/2+a<=D&&B+D-n/2+a>=0){
            d = B+D-n/2+a;
            //int m = min(min(n/2-a-d,B),n/2);
            //printf("%d %d\n",a,d);
            for(b = 0; b <= B&&b<=n/2-a-d; b++){
                //printf("  %d\n",b);
                if(n/2-a-b-d<=C&&n/2-a-b-d>=0){
                    c = n/2-a-b-d;
                    ys=1;break;
                }
            }
            if(ys)break;
        }
    }
    //printf("%d %d %d %d\n", a,b,c,d);
    if(!ys){
        return printf("-1"),0;
    }
    for(int i = 1; i <= n; i++){
        if(s1[i]=='0'){
            if(s2[i]=='0'&&a){
                a--;
                printf("%d ",i);
            }
            else if(s2[i]=='1'&&b){
                b--;
                printf("%d ",i);
            }
        }
        else if(s1[i]=='1'){
            if(s2[i]=='0'&&c){
                c--;
                printf("%d ",i);
            }
            else if(s2[i]=='1'&&d){
                d--;
                printf("%d ",i);
            }
        }
    }
    return 0;
}
