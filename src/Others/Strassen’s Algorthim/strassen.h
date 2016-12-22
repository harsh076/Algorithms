int *MATRIX_MULTIPLICATION(int*,int*,int);

int *MATRIX_MULTIPLICATION(int*A, int*B, int n)
{
    int *C = (int*)malloc(sizeof(int)*n*n);
    if(C == NULL)   printf("Buffer Overflow!\n");

    if(n==1)
    {
        int *C11 = (int*)malloc((sizeof(int)*(n*n))/4);
        if(C11 == NULL)   printf("Buffer Overflow!\n");
        *C11 = A[0]*B[0];
        return C11;
    }
    else
    {
        int *S1 = (int*)malloc((sizeof(int)*(n*n))/4);
        if(S1 == NULL)   printf("Buffer Overflow!\n");

        int *S2 = (int*)malloc((sizeof(int)*(n*n))/4);
        if(S2 == NULL)   printf("Buffer Overflow!\n");

        int *S3 = (int*)malloc((sizeof(int)*(n*n))/4);
        if(S3 == NULL)   printf("Buffer Overflow!\n");

        int *S4 = (int*)malloc((sizeof(int)*(n*n))/4);
        if(S4 == NULL)   printf("Buffer Overflow!\n");

        int *S5 = (int*)malloc((sizeof(int)*(n*n))/4);
        if(S5 == NULL)   printf("Buffer Overflow!\n");

        int *S6 = (int*)malloc((sizeof(int)*(n*n))/4);
        if(S6 == NULL)   printf("Buffer Overflow!\n");

        int *S7 = (int*)malloc((sizeof(int)*(n*n))/4);
        if(S7 == NULL)   printf("Buffer Overflow!\n");

        int *S8 = (int*)malloc((sizeof(int)*(n*n))/4);
        if(S8 == NULL)   printf("Buffer Overflow!\n");

        int *S9 = (int*)malloc((sizeof(int)*(n*n))/4);
        if(S9 == NULL)   printf("Buffer Overflow!\n");

        int *S10 = (int*)malloc((sizeof(int)*(n*n))/4);
        if(S10 == NULL)   printf("Buffer Overflow!\n");

        int i,j;
        for(i=0; i<n/2; i++)
        {
            for(j=0; j<n/2; j++)
            {
                S1  [(i)*(n/2)+(j)] = B[(i)*n+(j+n/2)]  -   B[(i+n/2)*n+(j+n/2)];
                S2  [(i)*(n/2)+(j)] = A[(i)*n+(j)]      +   A[(i)*n+(j+n/2)];
                S3  [(i)*(n/2)+(j)] = A[(i+n/2)*n+(j)]  +   A[(i+n/2)*n+(j+n/2)];
                S4  [(i)*(n/2)+(j)] = B[(i+n/2)*n+(j)]  -   B[(i)*n+(j)];
                S5  [(i)*(n/2)+(j)] = A[(i)*n+(j)]      +   A[(i+n/2)*n+(j+n/2)];
                S6  [(i)*(n/2)+(j)] = B[(i)*n+(j)]      +   B[(i+n/2)*n+(j+n/2)];
                S7  [(i)*(n/2)+(j)] = A[(i)*n+(j+n/2)]  -   A[(i+n/2)*n+(j+n/2)];
                S8  [(i)*(n/2)+(j)] = B[(i+n/2)*n+(j)]  +   B[(i+n/2)*n+(j+n/2)];
                S9  [(i)*(n/2)+(j)] = A[(i)*n+(j)]      -   A[(i+n/2)*n+(j)];
                S10 [(i)*(n/2)+(j)] = B[(i)*n+(j)]      +   B[(i)*n+(j+n/2)];
            }
        }

        int *P1 = (int*)malloc((sizeof(int)*(n*n))/4);
        if(P1 == NULL)   printf("Buffer Overflow!\n");

        int *P2 = (int*)malloc((sizeof(int)*(n*n))/4);
        if(P2 == NULL)   printf("Buffer Overflow!\n");

        int *P3 = (int*)malloc((sizeof(int)*(n*n))/4);
        if(P3 == NULL)   printf("Buffer Overflow!\n");

        int *P4 = (int*)malloc((sizeof(int)*(n*n))/4);
        if(P4 == NULL)   printf("Buffer Overflow!\n");

        int *P5 = (int*)malloc((sizeof(int)*(n*n))/4);
        if(P5 == NULL)   printf("Buffer Overflow!\n");

        int *P6 = (int*)malloc((sizeof(int)*(n*n))/4);
        if(P6 == NULL)   printf("Buffer Overflow!\n");

        int *P7 = (int*)malloc((sizeof(int)*(n*n))/4);
        if(P7 == NULL)   printf("Buffer Overflow!\n");

        int *A11 = (int*)malloc((sizeof(int)*(n*n))/4);
        if(A11 == NULL)   printf("Buffer Overflow!\n");

        int *A22 = (int*)malloc((sizeof(int)*(n*n))/4);
        if(A22 == NULL)   printf("Buffer Overflow!\n");

        int *B11 = (int*)malloc((sizeof(int)*(n*n))/4);
        if(B11 == NULL)   printf("Buffer Overflow!\n");

        int *B22 = (int*)malloc((sizeof(int)*(n*n))/4);
        if(B22 == NULL)   printf("Buffer Overflow!\n");

        for(i=0; i<n/2; i++)
        {
            for(j=0; j<n/2; j++)
            {
                A11[(i)*(n/2)+j] = A[(i)*n+(j)];
                A22[(i)*(n/2)+j] = A[(i+n/2)*n+(j+n/2)];
                B11[(i)*(n/2)+j] = B[(i)*n+j];
                B22[(i)*(n/2)+j] = B[(i+n/2)*n+(j+n/2)];
            }
        }

        P1 = MATRIX_MULTIPLICATION(A11,S1,n/2);
        P2 = MATRIX_MULTIPLICATION(S2,B22,n/2);
        P3 = MATRIX_MULTIPLICATION(S3,B11,n/2);
        P4 = MATRIX_MULTIPLICATION(A22,S4,n/2);
        P5 = MATRIX_MULTIPLICATION(S5,S6,n/2);
        P6 = MATRIX_MULTIPLICATION(S7,S8,n/2);
        P7 = MATRIX_MULTIPLICATION(S9,S10,n/2);

        free(S1);   free(S2);   free(S3);   free(S4);   free(S5);
        free(S6);   free(S7);   free(S8);   free(S9);   free(S10);
        free(A11);   free(A22);   free(B11);   free(B22);

        for(i=0; i<n/2; i++)
        {
            for(j=0; j<n/2; j++)
            {
                C[(i)*(n)+(j)] = P5[(i)*(n/2)+(j)] + P4[(i)*(n/2)+(j)] - P2[(i)*(n/2)+(j)] + P6[(i)*(n/2)+(j)];
                C[(i)*(n)+(j+n/2)] = P1[(i)*(n/2)+(j)] + P2[(i)*(n/2)+(j)];
                C[(i+n/2)*(n)+(j)] = P3[(i)*(n/2)+(j)] + P4[(i)*(n/2)+(j)];
                C[(i+n/2)*(n)+(j+n/2)] = P5[(i)*(n/2)+(j)] + P1[(i)*(n/2)+(j)] - P3[(i)*(n/2)+(j)] - P7[(i)*(n/2)+(j)];
            }
        }

        free(P1);   free(P2);   free(P3);   free(P4);   free(P5);   free(P6);   free(P7);
        return  C;
    }
}
