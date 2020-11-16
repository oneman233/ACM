#include <bits/stdc++.h>

using namespace std;

int num[110][110];

int main()
{
	int n;
	int sum=0;
	cin>>n;
	int temp=n;
	int k=1;
	int i=n,j=n;
	int shu=n*n;
	while(n>(temp/2+1))
	{
		i=n;
		j=n;
		while(j>=k)
		{
			num[i][j]=shu;
			shu--;
			j--;
		}
		j=k;
		shu++;
		while(i>=k)
		{
			num[i][j]=shu;
			shu--;
			i--;
		}
		i=k;
		shu++;
		while(j<=n)
		{
			num[i][j]=shu;
			shu--;
			j++;
		}
		j=n;
		shu++;
		while(i<=(n-1))
		{
			num[i][j]=shu;
			shu--;
			i++;
		}
		i=(n-1);
		n--;
		k++;
	}
	num[temp/2+1][temp/2+1]=1;
	for(i=1;i<=temp;i++)
	{
		for(j=1;j<=temp;j++)
		{
			printf("%3d",num[i][j]);
			if(j!=temp)
				printf(" ");
		}
		printf("\n");
	}
	for(i=1;i<=temp;i++)
		sum+=num[i][i];
	i=1;
	while(i<=temp)
	{
		sum+=num[i][temp+1-i];
		i++;
	}
	sum--;
	cout<<sum;
	return 0;
}
