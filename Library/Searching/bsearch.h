int binary_search(int *, int, int, int);

int binary_search(int *a, int n, int low, int high)
{
    int mid = (low+high)/2;
    if(low == high)
    {
        return -1;
    }
    else if(a[mid] == n)
    {
        return mid;
    }
    else if(a[mid]>n)
    {
        return binary_search(a,n,low,mid);
    }
    else if(a[mid]<n)
    {
        return binary_search(a,n,mid+1,high);
    }
}
