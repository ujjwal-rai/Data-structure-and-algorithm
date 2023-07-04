#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

// int main()
// {
//     int A[5]={2,4,6,8,10};
//     int *p;
//     int *P;
//     p=new int[5];
//     P=(int *)malloc(5*sizeof(int));
//     P[0]=3;
//     P[1]=5;
//     P[2]=7;
//     P[3]=9;
//     P[4]=11;
//     for(int i = 0; i<5; i++)
//     {
//         printf("%d  ", A[i]);
//     }
//     printf("\n");
//     for(int i = 0; i<5; i++)
//     {
//         printf("%d  ", P[i]);
//     }
//     free(P);
//     delete []p;
//     return 0;
// }

// int main()
// {
//     int *p=(int *)malloc(5*sizeof(int));
//     int *q;
//     p[0]=3; p[1]=5; p[2]=7; p[3]=9;; p[4]=11; 

//     q=(int *)malloc(10*sizeof(int));
//     for(int i = 0; i<5; i++)
//     {
//         q[i]=p[i];
//     }
//     free(p);
//     p=q;
//     q=NULL;
//     for(int i = 0; i<5; i++)
//     {
//         printf("%d  ",p[i]);
//     }
//     return 0;
// }

int main()
{
    int A[3][4]={{1,2,3,4},{2,4,6,8},{1,3,5,7}};
    int *B[3];
    int **C;

    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<4; j++)
        {
            printf("%d\t",A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    //B[0]=new int [4];
    //B[1]=new int [4];
    //B[2]=new int [4];
    B[0]=(int *)malloc(4*sizeof(int));
    B[1]=(int *)malloc(4*sizeof(int));
    B[2]=(int *)malloc(4*sizeof(int));
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<4; j++)
        {
            printf("%d\t",B[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    C=(int **)malloc(3*sizeof(int));
    C[0]=(int *)malloc(4*sizeof(int));
    C[1]=(int *)malloc(4*sizeof(int));
    C[2]=(int *)malloc(4*sizeof(int));
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<4; j++)
        {
            printf("%d\t",C[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    free(B);
    free(C);
    return 0;
}