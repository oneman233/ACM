#include <bits/stdc++.h>
using namespace std;
const int MN = 1005;

unordered_map<int,int>mp;
char a[15][MN];
char s[15][MN]=
{
//12345678901234578901234567890123457890
"***   * *** *** * * *** *** *** *** ***",
"* *   *   *   * * * *   *     * * * * *",
"* *   * *** *** *** *** ***   * *** ***",
"* *   * *     *   *   * * *   * * *   *",
"***   * *** ***   * *** ***   * *** ***"
};

int main()
{
	for(int t=0; t<40; t+=4)
	{
		int msk=0;
		for(int i=0; i<5; ++i)
			for(int j=0; j<3; ++j)
//cout<<(1<<(i*3+j))<<' ',
				msk+=(1<<(i*3+j))*(s[i][t+j]=='*');
//printf("%d %d\n",t/4,msk);
		mp[msk]= t? t/4: 12;
	}
	for(int i=0; i<5; ++i) gets(a[i]);//scanf("%s",a[i]);
//for(int i=0; i<5; ++i) puts(a[i]);
	int len=strlen(a[0]);
	for(int t=1; t<5; ++t) len=max(len,(int)strlen(a[t]));
	int sm=0,fnl=0;
	for(int t=0; t<len; t+=4)
	{
		int msk=0;
		for(int i=0; i<5; ++i)
			for(int j=0; j<3; ++j)
				msk+=(1<<(i*3+j))*(a[i][t+j]=='*');
		if(!mp[msk]) return puts("BOOM!!"), 0;
		fnl=mp[msk], sm+=fnl;
//printf("%d %d \n",msk,fnl);
	}
	puts(fnl%2==0 && sm%3==0? "BEER!!" : "BOOM!!");
	return 0;
}
/*
***   * * * *** *** *** ***
* *   * * *   *   *   * *
* *   * *** *** *** *** ***
* *   *   * *     * *   * *
***   *   * *** *** *** ***

  *   * *** *** *** * *
  *   * **    * * * * *
  *   * *** *** *** ***
  *   * *   *   * *   *
  *   * *** *** ***   *

*** ***   * *** *** *
*   * *   * * *   * *
*** * *   * *** *** *
  * * *   *   * *   *
*** ***   * *** *** *

*** *** *** * * ***
  *   *   * * * * *
***   * *** *** ***
*     *   *   * * *
***   * ***   * ***
*/
