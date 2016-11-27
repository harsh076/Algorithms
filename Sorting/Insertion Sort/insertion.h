void insertion_sort(int *a, int p, int q)
{
    int i,j;
    int num;
    for(i=p; i<q; i++)
    {
        j = i+1;
        num = a[j];
        while ((j<=q)&&(j>p)&&(a[j-1]>num))
        {
            a[j] = a[j-1];
            --j;
        }
        a[j] = num;
    }
}
