#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *prime_num(void *param)
{
    int i,j;
    printf("Prime number from 2 to 1000000:\n");
    for (i=2 ;i<=100 ; i++)
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

void *fibo_seq(void *param)
{
    int num1=2, num2=3, numnext;
    printf("Here is Fibonacci Sequence to 1000000: %d, %d, ",num1,num2);
    numnext=num1+num2;
    while (numnext<=100)
    {
        printf("%d, ",numnext);
        num1=num2;
        num2=numnext;
        numnext=num1+num2;
    }
}

int main()
{
    pthread_t pid,pid1;
    pthread_create(&pid, NULL, prime_num, NULL);
    pthread_create(&pid1, NULL, fibo_seq, NULL);
    pthread_join(pid,NULL);
    pthread_join(pid1,NULL);
    system("PAUSE");
    return 0;
}
