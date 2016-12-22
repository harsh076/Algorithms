#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define swap(a,b) {int t = a;   a = b;  b = t;}

int select(int*,int,int,int);
int partition(int*,int,int);

int select(int*A, int p, int r, int i)
{
    if((i<=0)||(i>(r-p+1)))
    {
        return 0;
    }
    if(p==r)
    {
        return A[p];
    }
    int x = rand()%(r-p+1) + p;
    swap(A[x],A[r]);
    int q = partition(A,p,r);
    int k = q-p+1;
    if(k == i)
    {
        return A[q];
    }
    else if(i<k)
    {
        return select(A,p,q-1,i);
    }
    else
    {
        return select(A,q+1,r,i-k);
    }
}

int partition(int *A,int p,int r)
{
    int i = p-1;
    int x = A[r];
    int j;

    for(j=p; j<r; j++)
    {
        if(A[j]<x)
        {
            ++i;
            swap(A[i],A[j]);
        }
    }
    swap(A[j],A[i+1]);
    return (i+1);
}
