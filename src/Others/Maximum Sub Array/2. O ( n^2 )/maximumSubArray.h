struct list *FIND_MAX_SUB_ARRAY(int *,int,int);

struct list
{
    int p;
    int q;
    int sum;
};

struct list *FIND_MAX_SUB_ARRAY(int *A, int start, int end)
{
    struct list *val = (struct list *)malloc(sizeof(struct list));
    if(val == NULL)
    {
        printf("\nBuffer Overflow!");
        return 0;
    }

    int max_sum = A[0];
    int l = 0;
    int r = 0;
    int sum;
    int i,j;

    for(i=start; i<=end; i++)
    {
        sum = 0;
        for(j=i; j<=end; j++)
        {
            sum += A[j];
            if(sum > max_sum)
            {
                max_sum = sum;
                l = i;
                r = j;
            }
        }
    }

    val->p = l;
    val->q = r;
    val->sum = max_sum;

    return val;
}
