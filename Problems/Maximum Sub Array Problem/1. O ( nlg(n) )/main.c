#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "maximumSubArray.h"

#define SIZE 10
typedef long long int lli;

int main()
{
    srand(time(NULL));
    int *A = (int *)malloc(SIZE*sizeof(int));
    if(A == NULL)
    {
        printf("\nBuffer Overflow!");
        return 0;
    }
    int i;
    for(i=0; i<SIZE; i++)
    {
        int min,max;
        min = (rand()%SIZE) + 0;
        max = (rand()%SIZE) + 0;
        A[i] = max - min;
        if(i%10 == 0)   printf("\n");
        printf("%d\t",A[i]);
    }

    lli start = clock();
    struct list *p = FIND_MAX_SUB_ARRAY(A,0,SIZE-1);
    lli stop = clock();
    free(A);
    printf("\n\nSTART : %d\tSTOP : %d\tSUM : %d\n",p->l,p->r,p->sum);
    free(p);
    printf("\n\nExecution Time : %.3fsec\n",(stop-start)/(double)1000);
    return 0;
}
