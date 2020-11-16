#include <stdio.h>
int main()
{
    int num,n,i,guess;
    scanf("%d %d",&num,&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&guess);
        if(guess<0)
        {
            printf("Game Over");
            return 0;
        }
        if(guess>num)
            printf("Too big\n");
        else if(guess<num)
            printf("Too small\n");
        else if(guess==num&&i==0)
        {
            printf("Bingo!");
            return 0;
        }
        else if(guess==num&&(i==1||i==2))
        {
            printf("Lucky You!");
            return 0;
        }
        else
        {
            printf("Good Guess!");
            return 0;
        }
    }
    printf("Game Over");
    return 0;
}
