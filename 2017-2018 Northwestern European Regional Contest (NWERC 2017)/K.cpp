#include <bits/stdc++.h>
using namespace std;
const int N=5000;

int n,up=0;
double r[N];
deque<double> q;
double dp[100][N];

double gao3(int i,int j){return q[i]/(q[i]+q[j]);}

double gao2(int cur,int now)
{
	if(cur==0) return 1.0;
	int L=;
	int R=;
	for(int i=L;i<=R;++i)
		dp[cur][now]+=gao2(cur-1,now)*gao2(cur-1,i)*gao3(now,i);
	return dp[cur][now];
}

void gao()
{
	up=(int)log2(n);
	if((1<<up)<n) ++up;
	printf("%.10lf",gao2(up,1));
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lf",&r[i]);
	for(int i=2;i<=n;++i)
		q.push_back(r[i]);
	sort(q.begin(),q.end());
	q.push_front(r[1]);
	q.push_front(0);
	gao();
	return 0;
}
/*
2
1 1

4
3 1 2 4

5
1 1 3 3 3
*/
