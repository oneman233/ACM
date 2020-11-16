#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<ctime>
#include<vector>
#include<set>
#include<map>
#include<stack>
using namespace std;
#define sp cout<<"---------------------------------------------------"<<endl
int c[50][50];
double dp[50];
int main(){
      int n,m,i,j,k;
      double p;
      cin>>n;
      cin>>p;
      c[0][0]=1;
      for(i=1;i<=20;i++)
        c[i][0]=c[i][i]=1;
      for(i=1;i<=20;i++)
        for(j=1;j<i;j++)
          c[i][j]=c[i-1][j]+c[i-1][j-1];
      dp[1]=1;
      for(i=2;i<=n;i++){
        for(j=1;j<i;j++)
          dp[i]+=c[i-1][j-1]*dp[j]*pow((1-p),j*(i-j));
        dp[i]=1-dp[i];
      }
      printf("%0.2lf\n",dp[n]);
      return 0;
}
