void selection_sort(int *a, int p, int q)
{
    int i,j,temp;
    int small;
    for(i=p; i<q; i++)
    {
        small = i;
        for(j=i; j<q; j++)
        {
            if(a[small]>a[j])
            {
                small = j;
            }
        }
        temp = a[small];
        a[small] = a[i];
        a[i] = temp;
    }
}
