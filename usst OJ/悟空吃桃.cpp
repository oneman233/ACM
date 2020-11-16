#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  int n;
  long long ans[55];
  ans[1]=1;
  for(int i=2;i<=51;i++){
    ans[i]=(ans[i-1]+1)*2;
  }
  while(cin>>t){
  cout<<ans[t]<<endl;
  }
  return 0;
}
