#include <bits/stdc++.h>
using namespace std;

int _;
int year,month,day,hour,minute,second;

int when(int y,int m,int d){
	int ans;
	if(m==1||m==2) m+=12,y--;
	if((y<1752)||(y==1752&&m<9)||(y==1752&&m==9&&d<3))
		ans=(d+2*m+3*(m+1)/5+y+y/4+5)%7;
	else
		ans=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
	return ans+1;
}

int main()
{
	scanf("%d",&_);
	for(int Case=1;Case<=_;++Case){
		scanf("%d-%d-%d %d:%d:%d",&year,&month,&day,&hour,&minute,&second);
		int Begin=1,End=1;
		while(when(year,11,End)!=7) End++;
		int cnt=0;
		while(1){
			if(when(year,3,Begin)==7) cnt++;
			if(cnt==2) break;
			Begin++;
		}
		if(month<3||month>11) printf("Case #%d: PST\n",Case);
		else if(month>3&&month<11) printf("Case #%d: PDT\n",Case);
		else if(month==3){
			if(day<Begin) printf("Case #%d: PST\n",Case);
			else if(day>Begin) printf("Case #%d: PDT\n",Case);
			else{
				if(hour==2) printf("Case #%d: Neither\n",Case);
				else if(hour>=3) printf("Case #%d: PDT\n",Case);
				else printf("Case #%d: PST\n",Case);
			}
		}
		else if(month==11){
			if(day<End) printf("Case #%d: PDT\n",Case);
			else if(day>End) printf("Case #%d: PST\n",Case);
			else{
				if(hour>=2) printf("Case #%d: PST\n",Case);
				else if(hour<=0) printf("Case #%d: PDT\n",Case);
				else printf("Case #%d: Both\n",Case);
			}
		}
	}
	return 0;
}
/*
4
2016-03-13 01:59:59
2016-03-13 02:00:00
2016-11-06 00:59:59
2016-11-06 01:00:00
*/
