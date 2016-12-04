int binary_search(int *, int, int, int);

int binary_search(int *a, int n, int p, int r)
{
    if (n<=r)
    {
        int q = (p+r)/2;
        if(n == a[q])
        {
            return q;
        }
        else if (n<a[q])
        {
            return binary_search(a,n,p,q-1);
        }
        else if (n>a[q])
        {
            return binary_search(a,n,q+1,r);
        }
    }
    return -1;
}
