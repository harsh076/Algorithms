void heap_sort(int *,int,int);
void build_max_heap(int *,int,int);
void max_heapify(int *,int,int,int);

#define swap(t,a,b) t temp = a; a = b; b = temp;

void heap_sort(int *A, int start, int end)
{
    int i;
    build_max_heap(A,start,end);
    for(i=end; i>start; i--)
    {
        swap(int,A[start],A[i]);
        max_heapify(A,start,i-1,start);
    }
}

void build_max_heap(int *A,int start,int end)
{
    int o = start-1;
    int n = end-start+1;
    int i;
    for(i = (n/2)+o; i>=start; i--)
    {
        max_heapify(A,i,end,i);
    }
}

void max_heapify(int *A,int start,int end,int i)
{
    int o = start-1;
    int l = 2*(i-o) + o;
    int r = l+1;
    int largest = start;

    if((A[i]<A[l]) && (l<end))
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    if((A[largest]<A[r]) && (r<end))
    {
        largest = r;
    }
    if(!(largest == i))
    {
        swap(int,A[i],A[largest]);
        max_heapify(A,largest,end,largest);
    }
}
