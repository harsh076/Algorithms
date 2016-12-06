#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "merge.h"

#define SIZE 10
typedef long long int lli;

int main()
{
    srand(time(NULL));
    int lo = 1;
    int hi = 9;

    int *arr = (int *)malloc(sizeof(int)*SIZE);
    if(arr == NULL)
    {
        printf("Buffer Overflow!");
        return 0;
    }

    int i;
    printf("\nOriginal Array");
    for(i=0; i<SIZE; i++)
    {
        arr[i] = rand() % hi + lo;
        if(i%10 == 0)
        {
            printf("\n");
        }
        printf("%d\t",arr[i]);
    }

    printf("\n");
    lli start_s=clock();
    int inversions = merge_sort(arr,0,SIZE);
    lli stop_s=clock();

    printf("\nSorted Array");
    for(i=0; i<SIZE; i++)
    {
        if(i%10 == 0)
        {
            printf("\n");
        }
        printf("%d\t",arr[i]);
    }

    free (arr);
    printf("\n\nTotal Inversion : %d\n",inversions);
    printf("\n\nExecution Time : %f sec\n",(stop_s-start_s)/(double)(CLOCKS_PER_SEC));

    return 0;
}
