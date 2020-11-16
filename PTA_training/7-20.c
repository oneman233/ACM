#include <stdio.h>
#include <stdlib.h>
struct number
{
  int n;
  struct number * next;
};
int main()
{
    int N,count=0,flag,result;
    struct number *head,*p,*q;
    scanf("%d",&N);
    head=malloc(sizeof(struct number));
    head->next=malloc(sizeof(struct number));
    p=head->next;
    do
    {
        q=malloc(sizeof(struct number));
        scanf("%d",&q->n);
        count++;
        p->next=q;
        q->next=NULL;
        p=q;
    }
    while(q->n>=0);
    if(N>(count-1)||N==0)
    {
        printf("NULL");
        return 0;
    }
    flag=count-N+1;
    p=head->next;
    while(flag--)
    {
        result=p->n;
        p=p->next;
    }
    printf("%d",result);
    return 0;
}
