struct list *FIND_MAX_SUB_ARRAY(int *,int,int);
struct list *FIND_MAX_CROSSING_SUB_ARRAY(int *,int,int,int);

struct list
{
    int l;
    int r;
    int sum;
};

struct list *FIND_MAX_SUB_ARRAY(int *A, int start, int end)
{
    int mid = (start+end)/2;
    if(start == end)
    {
        struct list *base = (struct list *)malloc(sizeof(struct list));
        if(base == NULL)
        {
            printf("\nBuffer Overflow!");
            return 0;
        }
        base->l = start;
        base->r = start;
        base->sum = A[start];
        return base;
    }
    else if(start < end)
    {
        struct list *L = (struct list *)malloc(sizeof(struct list));
        struct list *R = (struct list *)malloc(sizeof(struct list));
        struct list *C = NULL;

        if((L == NULL)||(R == NULL))
        {
            printf("\nBuffer Overflow!");
            return 0;
        }

        L = FIND_MAX_SUB_ARRAY(A,start,mid);
        R = FIND_MAX_SUB_ARRAY(A,mid+1,end);
        C = FIND_MAX_CROSSING_SUB_ARRAY(A,start,mid,end);

        if(((L->sum)>=(R->sum))&&((L->sum)>=(C->sum)))
        {
            return L;   free(R);    free(C);
        }
        if(((R->sum)>=(L->sum))&&((R->sum)>=(C->sum)))
        {
            return R;   free(L);    free(C);
        }
        if(((C->sum)>=(L->sum))&&((C->sum)>=(R->sum)))
        {
            return C;   free(L);    free(R);
        }
    }
}

struct list *FIND_MAX_CROSSING_SUB_ARRAY(int *A, int start, int mid, int end)
{
    int i;

    int lsum = 0;
    int lmax = A[mid];
    int l_index = mid;
    for(i=mid; i>=0; --i)
    {
        lsum += A[i];
        if(lsum > lmax)
        {
            lmax = lsum;
            l_index = i;
        }
    }

    int rsum = 0;
    int rmax = A[mid+1];
    int r_index = mid+1;
    for(i=mid+1; i<=end; i++)
    {
        rsum += A[i];
        if(rsum > rmax)
        {
            rmax = rsum;
            r_index = i;
        }
    }
    struct list *C_obj = (struct list *)malloc(sizeof(struct list));
    C_obj->l = l_index;
    C_obj->r = r_index;
    C_obj->sum = lmax + rmax;
    return C_obj;
}
