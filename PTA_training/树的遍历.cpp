//Asimple
#include <bits/stdc++.h>
#define INF 1e10
#define mod 10007
#define swap(a,b,t) t = a, a = b, b = t
#define CLS(a, v) memset(a, v, sizeof(a))
#define debug(a)  cout << #a << " = "  << a <<endl
#define abs(x) x<0?-x:x
using namespace std;
typedef long long ll;
const int maxn = 35;
int n;
int pos[maxn], in[maxn];
vector<int> res(10000, -1);

void solve(int root, int s, int e, int index) {
    if( s > e ) return ;
    cout<<index<<endl;
    int i = s;
    while( i<e && in[i]!=pos[root])i++;
    //cout<<i<<endl;
    res[index] = pos[root];
    solve(root-1-e+i, s, i-1, index*2+1);
    solve(root-1, i+1, e, index*2+2);
}

void input() {
    cin >> n;
    for(int i=0; i<n; i++) cin >> pos[i] ;
    for(int i=0; i<n; i++) cin >> in[i];
    solve(n-1, 0, n-1, 0);
    int cnt = 0;
    for(int i=0; i<res.size(); i++) {
        if( res[i]!=-1 && cnt!=n-1 ) {
            printf("%d ", res[i]);
            cnt ++;
        } else if(res[i]!=-1){
            printf("%d\n", res[i]);
            break;
        }
    }
}

int main() {
    input();
    return 0;
}
