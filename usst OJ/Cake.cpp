#include <bits/stdc++.h>


using namespace std;

long long a[10005];
long long sum[10005];
int main()
{
    sum[0] = 0;
    for(int i  =1;i< 10000;i++){
        a[i] = (long long)i * i;
        sum[i] = sum[i-1] + a[i];
    }
    int n;
    cin>>n;
    for(int i = 0;i<10000-2*n;i++){
        if(sum[i+n]-sum[i-1] == sum[i+n +n]-sum[i+n]){
            for(int j = i;j<i+n +n+1;j++){
                if(j != i){
                    cout<<" ";
                }
                cout<<j;
            }
            return 0;
        }
    }
    cout<<"No";
    return 0;
}
