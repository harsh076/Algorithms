#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "merge.h"
#include "bsearch.h"

#define SIZE 100

int main()
{
    srand(time(NULL));
    int A[SIZE];
    int i;
    int hi = 100;
    int lo = 0;
    for(i=0; i<SIZE; i++)
    {
        A[i] = (rand() % hi) + lo;
    }
    int x = (rand() % hi) + lo;
    merge_sort(A,0,SIZE);
    int pos1, pos2;
    int key;
    for(i=0; i<SIZE; i++)
    {
        key = x-A[i];
        pos1 = binary_search(A,key,i+1,SIZE);
        if(pos1 != -1)
        {
            pos2 = i;
            break;
        }
    }
    for(i=0; i<SIZE; i++)
    {
        if(i%10 == 0)
        printf("\n");
        printf("%d\t",A[i]);
    }
    if(pos1!=-1)
    printf("\nFor Sum (x) = %d Numbers found are %d and %d at positions %d and %d\n",x,A[pos1],A[pos2],pos1+1,pos2+1);
    else
    printf("\nFor Sum (x) = %d Numbers are not found!\n",x);
    return 0;
}
