#include <bits/stdc++.h>
using namespace std;

int main(){
  int k,maxi;
  long long n[100005];
  long long maxn=0;
  cin>>k;
  for(int i=0;i<k;i++){
    cin>>n[i];
  }
  for(int i=0;i<k;i++){
    if(n[i]>maxn){
      maxn=n[i];
      maxi=i;
    }
  }
  if(maxi==0||maxi==k-1){
    cout<<"No";
    return 0;
  }
  for(int i=0;i<k;i++){
    if(i!=maxi&&n[i]==maxn){
      cout<<"No";
      return 0;
    }
    if(i<maxi&&n[i]<=n[i-1]&&i!=0){
      cout<<"No";
      return 0;
    }
    if(i>maxi&&n[i]>=n[i-1]){
      cout<<"No";
      return 0;
    }
  }
  cout<<"Yes";
  return 0;
}
