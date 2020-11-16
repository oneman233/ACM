#include <bits/stdc++.h>
using namespace std;

int v,n;

int main(){
	scanf("%d%d",&v,&n);
	for(int i=1;i<=9;i++){
		printf("%d ",((v*n*i)+9)/10);
	}
	return 0;
}
