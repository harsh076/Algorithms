void quick_sort(int *,int,int);
int partition(int *,int,int);
int randomized_partition(int *,int,int);

#define swap(a,b) int temp; temp = a; a = b; b = temp;

void quick_sort(int *A,int p,int r)
{
    if(p<r)
    {
        int q;
        q = partition(A,p,r);
        quick_sort(A,p,q-1);
        quick_sort(A,q+1,r);
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
