int *MATRIX_MULTIPLICATION  (int *,int *,int);

#define _1_1 (i*size)+j
#define _1_2 (i*size)+(j+(size/2))
#define _2_1 ((i+(size/2))*size) + j
#define _2_2 ((i+(size/2))*size)+(j+(size/2))

int *MATRIX_MULTIPLICATION(int *A,int *B,int size)
{
    int i,j;
    if(size == 1)
    {
        int *C = (int *)malloc(sizeof(int));
        if(C == NULL)printf("Buffer Overflow!\n");

        *C = A[0]*B[0];
        return C;
    }
    int *S1 = (int *)malloc((sizeof(int)*size*size)/4);
    if(S1 == NULL)printf("Buffer Overflow!\n");

    int *S2 = (int *)malloc((sizeof(int)*size*size)/4);
    if(S2 == NULL)printf("Buffer Overflow!\n");

    int *S3 = (int *)malloc((sizeof(int)*size*size)/4);
    if(S3 == NULL)printf("Buffer Overflow!\n");

    int *S4 = (int *)malloc((sizeof(int)*size*size)/4);
    if(S4 == NULL)printf("Buffer Overflow!\n");

    int *S5 = (int *)malloc((sizeof(int)*size*size)/4);
    if(S5 == NULL)printf("Buffer Overflow!\n");

    int *S6 = (int *)malloc((sizeof(int)*size*size)/4);
    if(S6 == NULL)printf("Buffer Overflow!\n");

    int *S7 = (int *)malloc((sizeof(int)*size*size)/4);
    if(S7 == NULL)printf("Buffer Overflow!\n");

    int *S8 = (int *)malloc((sizeof(int)*size*size)/4);
    if(S8 == NULL)printf("Buffer Overflow!\n");

    int *S9 = (int *)malloc((sizeof(int)*size*size)/4);
    if(S9 == NULL)printf("Buffer Overflow!\n");

    int *S10 = (int *)malloc((sizeof(int)*size*size)/4);
    if(S10 == NULL)printf("Buffer Overflow!\n");

    for(i=0; i<size/2; i++)
    {
        for(j=0; j<size/2; j++)
        {
            S1  [i*size+j] = B[_1_2] - B[_2_2];
            S2  [i*size+j] = A[_1_1] + A[_1_2];
            S3  [i*size+j] = A[_2_1] + A[_2_2];
            S4  [i*size+j] = B[_2_1] - B[_1_1];
            S5  [i*size+j] = A[_1_1] + A[_2_2];
            S6  [i*size+j] = B[_1_1] + B[_2_2];
            S7  [i*size+j] = A[_1_2] - A[_2_2];
            S8  [i*size+j] = B[_2_1] + B[_2_2];
            S9  [i*size+j] = A[_1_1] - A[_2_1];
            S10 [i*size+j] = B[_1_1] + B[_1_2];
        }
    }

    for(i=0; i<size/2; i++)
    {
        for(j=0; j<size/2; j++)
        {
            printf("%4d", A[((i+(size/2))*size) + j]);
            printf("!!%d!!", size);
        }
        printf("\n");
    }

    int *P1 = (int *)malloc((sizeof(int)*size*size)/4);
    if(P1 == NULL)printf("Buffer Overflow!\n");

    int *P2 = (int *)malloc((sizeof(int)*size*size)/4);
    if(P2 == NULL)printf("Buffer Overflow!\n");

    int *P3 = (int *)malloc((sizeof(int)*size*size)/4);
    if(P3 == NULL)printf("Buffer Overflow!\n");

    int *P4 = (int *)malloc((sizeof(int)*size*size)/4);
    if(P4 == NULL)printf("Buffer Overflow!\n");

    int *P5 = (int *)malloc((sizeof(int)*size*size)/4);
    if(P5 == NULL)printf("Buffer Overflow!\n");

    int *P6 = (int *)malloc((sizeof(int)*size*size)/4);
    if(P6 == NULL)printf("Buffer Overflow!\n");

    int *P7 = (int *)malloc((sizeof(int)*size*size)/4);
    if(P7 == NULL)printf("Buffer Overflow!\n");

    int *A11 = (int *)malloc((sizeof(int)*size*size)/4);
    if(A11 == NULL)printf("Buffer Overflow!\n");

    int *A22 = (int *)malloc((sizeof(int)*size*size)/4);
    if(A22 == NULL)printf("Buffer Overflow!\n");

    int *B11 = (int *)malloc((sizeof(int)*size*size)/4);
    if(B11 == NULL)printf("Buffer Overflow!\n");

    int *B22 = (int *)malloc((sizeof(int)*size*size)/4);
    if(B22 == NULL)printf("Buffer Overflow!\n");

    for(i=0; i<size/2; i++)
    {
        for(j=0; j<size/2; j++)
        {
            A11[size*i+j] = A[size*i+j];
        }
    }

    for(i=size/2; i<size; i++)
    {
        for(j=size/2; j<size; j++)
        {
            A22[size*(i-size/2)+(j-size/2)] = A[size*i+j];
        }
    }

    for(i=0; i<size/2; i++)
    {
        for(j=0; j<size/2; j++)
        {
            B11[size*i+j] = B[size*i+j];
        }
    }

    for(i=size/2; i<size; i++)
    {
        for(j=size/2; j<size; j++)
        {
            B22[size*(i-size/2)+(j-size/2)] = B[size*i+j];
        }
    }

    P1 = MATRIX_MULTIPLICATION(A11,S1,size/2);
    P2 = MATRIX_MULTIPLICATION(S2,B22,size/2);
    P3 = MATRIX_MULTIPLICATION(S3,B11,size/2);
    P4 = MATRIX_MULTIPLICATION(A22,S4,size/2);
    P5 = MATRIX_MULTIPLICATION(S5,S6,size/2 );
    P6 = MATRIX_MULTIPLICATION(S7,S8,size/2 );
    P7 = MATRIX_MULTIPLICATION(S9,S10,size/2);

    free(S1);   free(S2);   free(S3);   free(S4);   free(S5);
    free(S6);   free(S7);   free(S8);   free(S9);   free(S10);
    free(A11);  free(A22);  free(B11);  free(B22);

    int *C11 = (int *)malloc((sizeof(int)*size*size)/4);
    if(C11 == NULL)printf("Buffer Overflow!\n");

    int *C12 = (int *)malloc((sizeof(int)*size*size)/4);
    if(C12 == NULL)printf("Buffer Overflow!\n");

    int *C21 = (int *)malloc((sizeof(int)*size*size)/4);
    if(C21 == NULL)printf("Buffer Overflow!\n");

    int *C22 = (int *)malloc((sizeof(int)*size*size)/4);
    if(C22 == NULL)printf("Buffer Overflow!\n");

    for(i=0; i<size/2; i++)
    {
        for(j=0; j<size/2; j++)
        {
            C11[size*i+j] = P4[size*i+j] + P5[size*i+j] - P2[size*i+j] + P6[size*i+j];
        }
    }

    for(i=0; i<size/2; i++)
    {
        for(j=0; j<size/2; j++)
        {
            C12[size*i+j] = P1[size*i+j] + P2[size*i+j];
        }
    }

    for(i=0; i<size/2; i++)
    {
        for(j=0; j<size/2; j++)
        {
            C21[size*i+j] = P3[size*i+j] + P4[size*i+j];
        }
    }

    for(i=0; i<size/2; i++)
    {
        for(j=0; j<size/2; j++)
        {
            C22[size*i+j] = P5[size*i+j] + P1[size*i+j] - P3[size*i+j] - P7[size*i+j];
        }
    }

    free(P1);   free(P2);   free(P3);   free(P4);   free(P5);   free(P6);   free(P7);

    int *C = (int *)malloc(sizeof(int)*size*size);
    if(C == NULL)printf("Buffer Overflow!\n");

    for(i=0; i<size/2; i++)
    {
        for(j=0; j<size/2; j++)
        {
            C[size*i+j] = C11[size*i+j];
        }
    }

    for(i=0; i<size/2; i++)
    {
        for(j=size/2+1; j<size; j++)
        {
            C[size*i+j] = C12[size*i+j];
        }
    }

    for(i=size/2+1; i<size; i++)
    {
        for(j=size/2+1; j<size; j++)
        {
            C[size*i+j] = C21[size*i+j];
        }
    }

    for(i=size/2+1; i<size; i++)
    {
        for(j=size/2+1; j<size; j++)
        {
            C[size*i+j] = C22[size*i+j];
        }
    }

    return C;
}
