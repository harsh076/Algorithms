#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quick.h"

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
    for(i=0; i<SIZE; i++)
    {
        arr[i] = rand() % (SIZE*10);
    }

    lli start_s=clock();
    quick_sort(arr,0,SIZE-1);
    lli stop_s=clock();

    for(i=0; i<SIZE; i++)
    {
        if(i%10 == 0)
        {
            printf("\n");
        }
        printf("%3d\t",arr[i]);
    }

    free (arr);
    printf("\n\nExecution Time : %f sec\n",(stop_s-start_s)/(double)(CLOCKS_PER_SEC));

    return 0;
}
