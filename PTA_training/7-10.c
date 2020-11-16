#include <stdio.h>
int main()
{
  int num[10],i,n,max=-20000,min=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&num[i]);
    if(num[i]>=max)
     max=num[i];
  }
  for(i=0;i<n;i++)
  {
      if(num[i]==max)
      {
          min=i;
          break;
      }
  }
  printf("%d %d",max,min);
  return 0;
}
