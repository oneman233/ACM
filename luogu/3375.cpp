#include <bits/stdc++.h>
using namespace std;
const int MAX=1000005;

char a[MAX],b[MAX];
int nxt[MAX],la,lb;

void go(){
	int j=0;
	for(int i=2;i<=lb;++i){
		while(j&&b[i]!=b[j+1]) j=nxt[j];
		if(b[i]==b[j+1]) j++;
		nxt[i]=j;
	}
}

void kmp(){
	int j=0;
	for(int i=1;i<=la;++i){
		while(j&&a[i]!=b[j+1]) j=nxt[j];
		if(a[i]==b[j+1]) j++;
		if(j==lb){
			printf("%d\n",i-lb+1);
			j=nxt[j];
		}
	}
}

int main()
{
    scanf("%s",a+1);
    scanf("%s",b+1);
    la=strlen(a+1),lb=strlen(b+1);
    go();
    kmp();
    for(int i=1;i<=lb;++i)
    	printf("%d ",nxt[i]);
    return 0;
}
