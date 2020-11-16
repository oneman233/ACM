#include <bits/stdc++.h>

using namespace std;

int main()
{
 char c;
 int sai[70000];
 int i=0;
 int w=0,l=0;
 memset(sai,0,sizeof(sai));
 while(scanf("%c",&c))
 {
 if(c=='E')
 break;
 if(c=='\n')
 continue;
 if(c=='W')
 sai[i]=1;
 if(c=='L')
 sai[i]=2;
 i++;
 }
 if(i==0)
 printf("0:0\n\n0:0");
 for(int j=0;j<i;j++)
 {
 if(sai[j]==1)
 w++;
 if(sai[j]==2)
 l++;
 if(w>=11&&(w-l)>=2)
 {
 printf("%d:%d\n",w,l);
 w=0;
 l=0;
 }
 if(l>=11&&(l-w)>=2)
 {
 printf("%d:%d\n",w,l);
 w=0;
 l=0;
 }
 }
 if(w!=0||l!=0)
 printf("%d:%d\n",w,l);
 //printf("\n");
 w=0;
 l=0;
 for(int j=0;j<i;j++)
 {
 if(sai[j]==1)
 w++;
 if(sai[j]==2)
 l++;
 if(w>=21&&(w-l)>=2)
 {
 printf("\n%d:%d",w,l);
 w=0;
 l=0;
 }
 if(l>=21&&(l-w)>=2)
 {
 printf("\n%d:%d",w,l);
 w=0;
 l=0;
 }
 }
 if(w!=0||l!=0)
 printf("\n%d:%d",w,l);
 return 0;
}
