int merge(int *,int,int,int);
int merge_sort(int *,int,int);

int merge_sort(int *a,int p, int r)
{
    int q;
    int L = 0;
    int R = 0;
    int S = 0;
    q = (p+r)/2;
    if(p<r)
    {
        L = merge_sort(a,p,q);
        R = merge_sort(a,q+1,r);
        S = merge(a,p,q,r);
    }
    return L+R+S;
}

int merge(int *a, int p, int q, int r)
{
    int n1 = q-p+1;
    int n2 = r-q;
    int *L = (int *)malloc(n1*sizeof(int));
    int *R = (int *)malloc(n2*sizeof(int));
    if((L == NULL) || (R == NULL))
    {
        printf("Buffer Overflow !");
        exit(0);
    }
    int i;
    for(i=0; i<n1; i++)
    {
        L[i] = a[p+i];
    }
    int j;
    for(j=0; j<n2; j++)
    {
        R[j] = a[q+j+1];
    }
    int k;
    int count = 0;
    i = 0;  j = 0;  k = 0;
    while((i<n1)&&(j<n2))
    {
        if(L[i]<=R[j])
        {
            a[p+k] = L[i];
            ++i;    ++k;
        }
        else
        {
            a[p+k] = R[j];
            ++j;    ++k;
            count += n1-i;
        }
    }
    while(i<n1)
    {
        a[p+k] = L[i];
        ++i;
        ++k;
    }
    while(j<n2)
    {
        a[p+k] = R[j];
        ++j;
        ++k;
    }
    free(L);
    free(R);
    return count;
}
