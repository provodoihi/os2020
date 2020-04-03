#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *prime_num(void *param)
{
   int i,j;
    for (i=2 ;i<=1000000 ; i++)
    {
        for (j=2; j<=i; j++)
        {
            if (i%j==0)
            {
                break;
            }
        }
        if (i==j)
        {
            printf("%d \n",i);
        }
    } 
}
int main() 
{
    pthread_t pid;
    pthread_create(&pid, NULL, prime_num, NULL); 
    pthread_join(pid,NULL);
    system("PAUSE");
    return 0;
}