#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arrand.h"
#include "selection.h"

#define SIZE 100
typedef long long int lli;

int main()
{
    srand(time(NULL));
    int i;
    int lo = 0;
    int hi = 1000;
    int *arr = (int *)malloc(SIZE*sizeof(int)*7);
    if(arr == NULL)
    {
        printf("Buffer Overflow!");
        return -1;
    }
    genrate_random_array(arr,lo,hi,SIZE);
    lli start_s=clock();
    selection_sort(arr,0,SIZE);
    lli stop_s=clock();
    print_array(arr,SIZE);
    free (arr);
    printf("\n\nExecution Time : %f sec\n",(stop_s-start_s)/(double)(CLOCKS_PER_SEC));
    return 0;
}
