#include <bits/stdc++.h>

const double pi = 3.1415926535;

using namespace std;

	bool b[15];
int main()
{
	int n;
	double ans=0.0;
	double x[15],y[15],r[15];
	cin>>n;
	double x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	if(x1>x2)
		swap(x1,x2);
	if(y1>y2)
		swap(y1,y2);
	for(int i=0;i<n;i++)
		cin>>x[i]>>y[i];
	int idx[n];
	for(int i=0;i<n;i++)
		idx[i]=i;
	do
	{
		for(int i=0;i<n;i++)
		{
		r[i]=x[i]-x1;
		r[i]=min(r[i],x2-x[i]);
		r[i]=min(r[i],y[i]-y1);
		r[i]=min(r[i],y2-y[i]);
		}
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				r[idx[i]]=min(sqrt((x[idx[i]]-x[idx[j]])*(x[idx[i]]-x[idx[j]])+(y[idx[i]]-y[idx[j]])*(y[idx[i]]-y[idx[j]]))-r[idx[j]],r[idx[i]]);
			}
		}
		double temp=0.0;
		for(int i=0;i<n;i++)
			temp+=r[i]*r[i]*pi;
		if(temp>ans)
			ans=temp;
	}
	while(next_permutation(idx,idx+n));
	printf("%.0lf",(x2-x1)*(y2-y1)-ans);
	return 0;
}
