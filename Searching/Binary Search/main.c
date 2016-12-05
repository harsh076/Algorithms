#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "merge.h"
#include "bsearch.h"

#define SIZE 100
typedef long long int lli;

int main()
{
    srand(time(NULL));
    int lo = 0;
    int hi = 100;
    int element = (rand() % hi) + lo;

    int *arr = (int *)malloc(sizeof(int)*SIZE);
    if(arr == NULL)
    {
        printf("Buffer Overflow!");
        return 0;
    }

    int i;
    for(i=0; i<SIZE; i++)
    {
        arr[i] = rand() % hi + lo;
    }

    int position = -1;
    merge_sort(arr,0,SIZE);
    lli start_s=clock();
    position = binary_search(arr,element,0,SIZE);
    lli stop_s=clock();

    for(i=0; i<SIZE; i++)
    {
        if(i%10 == 0)
        {
            printf("\n");
        }
        printf("%d\t",arr[i]);
    }

    free (arr);
    if(position != -1)
    printf("\n\nElement %d found at %d",element,position+1);
    else
    printf("\n\nElement %d not found!",element);
    printf("\n\nExecution Time : %f sec\n",(stop_s-start_s)/(double)(CLOCKS_PER_SEC));

    return 0;
}
