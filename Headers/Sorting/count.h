int* count_sort(int *,int,int,int);

int* count_sort(int *A,int p,int q,int k)
{
    int *B = (int *)malloc(sizeof(int)*(q-p+1));
    if(B == NULL)
    {
        printf("Buffer Overflow!");
        return 0;
    }
    int *C = (int *)malloc(sizeof(int)*(k+1));
    if(C == NULL)
    {
        printf("Buffer Overflow!");
        return 0;
    }
    int i;
    for(i=0; i<=k; i++)
    {
        C[i] = 0;
    }
    for(i=p; i<=q; i++)
    {
        C[A[i]] += 1;
    }
    for(i=p+1; i<=q; i++)
    {
        C[i] += C[i-1];
    }
    for(i=q; i>=p; i--)
    {
        B[C[A[i]]] = A[i];
        C[A[i]] -= 1;
    }
    free(C);
    return B;
}
