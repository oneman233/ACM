#include <stdio.h>
int main()
{
  int n,count=0,i=0,read;
  double ave,sum=0.0;
  scanf("%d",&n);
  if(n==0)
  {
    printf("average = 0\ncount = 0");
    return 0;
  }
  for(;i<n;i++)
  {
    scanf("%d",&read);
    if(read>=60)
      count++;
    sum+=read;
  }
  ave=sum/n;
  printf("average = %.1lf\ncount = %d",ave,count);
  return 0;
}
