#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "strassen.h"

#define SIZE 4
typedef long long int lli;

int main()
{
    srand(time(NULL));
    int *A = (int *)malloc(sizeof(int)*SIZE*SIZE);
    if(A == NULL)
    {
        printf("Buffer Overflow!\n");
    }
    int *B = (int *)malloc(sizeof(int)*SIZE*SIZE);
    if(B == NULL)
    {
        printf("Buffer Overflow!\n");
    }

    int i,j;
    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            *(A + i*SIZE + j) = (rand() % (8*SIZE)) - 4*SIZE;
            *(B + i*SIZE + j) = (rand() % (8*SIZE)) - 4*SIZE;
        }
    }

    printf("\n   MATRIX A\n\n");
    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            printf("%4d", A[i*SIZE+j]);
        }
        printf("\n");
    }
    printf("\n   MATRIX B\n\n");
    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            printf("%4d", B[i*SIZE+j]);
        }
        printf("\n");
    }

    lli start = clock();
    int *RES = MATRIX_MULTIPLICATION(A,B,SIZE);
    lli stop = clock();

    printf("\n   MATRIX C = A x B\n\n");
    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            printf("%4d\t",RES[i*SIZE+j]);
        }
        printf("\n");
    }

    free(A);    free(B);    free(RES);
    printf("\n\nExecution Time : %f sec\n",(stop-start)/(double)(CLOCKS_PER_SEC));
    return 0;
}
