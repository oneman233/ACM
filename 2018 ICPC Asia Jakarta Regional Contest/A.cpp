#include <bits/stdc++.h>
using namespace std;

int cnt[2];
char s[20005],ans[20005],c;

int main()
{
	scanf("%s",s);
	int n=strlen(s);
	for(int i=0;i<n;i++) 
		cnt[s[i]-'0']++;
	if(cnt[0]>cnt[1]) c='1';
	else c='0';
	for(int i=0;i<n;i++) ans[i]=c;
	ans[n]=0;
	if(cnt[0]!=cnt[1])
	{
		printf("%s",ans);
		return 0;
	}
	ans[0]=((s[0]-'0')^1)+'0';
	for(int i=1;i<n;i++)
		ans[i]=((ans[0]-'0')^1)+'0';
	printf("%s",ans);
	return 0;
}
