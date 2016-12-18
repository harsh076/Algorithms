#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "count.h"

#define SIZE 100
typedef long long int lli;

int main()
{
    srand(time(NULL));
    int *arr = (int *)malloc(sizeof(int)*SIZE);
    if(arr == NULL)
    {
        printf("Buffer Overflow!");
        return 0;
    }
    int i;
    for(i=1; i<=SIZE; i++)
    {
        arr[i] = rand() % SIZE + 1;
    }

    lli start_s=clock();
    int *sorted = count_sort(arr,1,SIZE,SIZE);
    lli stop_s=clock();

    for(i=1; i<=SIZE; i++)
    {
        printf("%d\t",sorted[i]);
        if(i%10 == 0)
        {
            printf("\n");
        }
    }
    free (arr);
    free (sorted);
    printf("\n\nExecution Time : %f sec\n",(stop_s-start_s)/(double)(CLOCKS_PER_SEC));

    return 0;
}
