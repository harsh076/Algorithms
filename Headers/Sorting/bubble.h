void bubble_sort(int *,int,int);

void bubble_sort(int *a, int p, int q)
{
    int i,j,temp;
    for(i=p; i<q; i++)
    {
        for(j=i; j<q; j++)
        {
            if(a[i]>a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
