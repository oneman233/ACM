#include <cstdio>
#include <stdlib.h>
#include <time.h>

char p[4]={'D','U','L','R'};
char s[50050]="";

int main()
{
	srand(time(0));
	for(int i=0;i<50000;i++) s[i]=p[rand()%4];
	s[50000]='\0';
	puts(s);		
	return 0;
}
