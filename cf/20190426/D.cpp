#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k,nn;
ll out[100005];

int main()
{
    cin>>n>>k;
    if(n<k+k*(k-1)/2)
        cout<<"NO";
    else{
        int nn=n-k*(k+1)/2;
        vector<int> a(k);
        for(int i=0;i<k;++i){
            a[i]=i+1
        }
    }
    return 0;
}
