
#include<bits/stdc++.h>

using namespace std;

const int N = 2e5+10;

int arr[N];

int main(){

	int n,k;

	scanf("%d%d",&n,&k);

	for(int i=0;i<n;i++)

	   scanf("%d",&arr[i]);

	sort(arr,arr+n);

	if(k==0){

		int ans=arr[0]-1;

		if(ans<1) printf("-1\n");

		else printf("%d\n",ans);

	}

	else if(arr[k-1]==arr[k]) printf("-1\n");

	else printf("%d\n",arr[k-1]);

	return 0;

}
