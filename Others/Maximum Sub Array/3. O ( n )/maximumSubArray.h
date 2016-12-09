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

    int sum = 0;
    int max_sum = 0;
    int p,p_max,q_max;  p = p_max = q_max = start;
    int i;

    for(i=start; i<=end; i++)
    {
        sum += A[i];
        if(sum <= 0)
        {
            sum = 0;
            p = i+1;
        }

        else if(sum > max_sum)
        {
            max_sum = sum;
            q_max = i;
            p_max = p;
        }
    }

    val->p = p_max;
    val->q = q_max;
    val->sum = max_sum;

    return val;
}
