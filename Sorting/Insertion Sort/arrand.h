#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void genrate_random_array(int *a, int lo, int hi, int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        a[i] = rand()%hi + lo;
    }
}

void print_array(int *a,int size)
{
    printf("\n");
    int i;
    for(i=0; i<size; i++)
    {
        if(i%10 == 0)
        {
            printf("\n");
        }
        printf("%d\t",a[i]);
    }
}
