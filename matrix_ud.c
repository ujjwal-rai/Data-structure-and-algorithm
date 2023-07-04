#include <stdio.h>
#include <stdlib.h>

void Diagonal()
{
    int *A,n,ch,x,i,j;
    printf("Enter Dimension: ");
    scanf("%d", &n);
    A=(int *)malloc(n*sizeof(int));
    do
    {
        printf("Menu\n");
        printf("1. Create\n");
        printf("2. Get\n");
        printf("3. Set\n");
        printf("4. Display\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                for(i = 1; i<=n; i++)
                {
                    scanf("%d", &A[i-1]);
                    break;
                }
            case 2:
                printf("Enter indices: ");
                scanf("%d%d", &i,&j);
                if(i==j)
                {
                    printf("%d\n", A[i-1]);
                }
                else
                {
                    printf("0\n");
                }
                break;
            case 3:
                printf("Enter row, column and element: ");
                scanf("%d%d%d",&i,&j,&x);
                if(i==j)
                {
                    x=A[i-1];
                }
                break;
            case 4:
                for(int i = 1; i<=n; i++)
                {
                    for(int j = 1; j<=n; j++)
                    {
                        if(i==j)
                        {
                            printf("%d\t", A[i-1]);
                        }
                        else
                        {
                            printf("0\t");
                        }
                    }
                    printf("\n");
                }

        }
    } while (0<ch && ch<=4);
    
}

void Lower_triangle_row_major()
{
    int *A,n,ch,x,i,j;
    printf("Enter Dimension: ");
    scanf("%d", &n);
    A=(int *)malloc((n*(n+1)/2)*sizeof(int));
    do
    {
        printf("Menu\n");
        printf("1. Create\n");
        printf("2. Get\n");
        printf("3. Set\n");
        printf("4. Display\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                for(i = 1; i<=n*(n+1)/2; i++)
                {
                    scanf("%d", &A[i*(i-1)/2 + j-1]);
                    break;
                }
            case 2:
                printf("Enter indices: ");
                scanf("%d%d", &i,&j);
                if(i<=j)
                {
                    printf("%d\n", A[i*(i-1)/2 + j-1]);
                }
                else
                {
                    printf("0\n");
                }
                break;
            case 3:
                printf("Enter row, column and element: ");
                scanf("%d%d%d",&i,&j,&x);
                if(i<=j)
                {
                    x=A[i*(i-1)/2 + j-1];
                }
                break;
            case 4:
                for(int i = 1; i<=n; i++)
                {
                    for(int j = 1; j<=n; j++)
                    {
                        if(i==j)
                        {
                            printf("%d\t", A[i*(i-1)/2 + j-1]);
                        }
                        else
                        {
                            printf("0\t");
                        }
                    }
                    printf("\n");
                }
        }
    } while (0<ch && ch<=4);
    
}

void Lower_triangle_column_major()
{
    int *A,n,ch,x,i,j;
    printf("Enter Dimension: ");
    scanf("%d", &n);
    A=(int *)malloc((n*(n+1)/2)*sizeof(int));
    do
    {
        printf("Menu\n");
        printf("1. Create\n");
        printf("2. Get\n");
        printf("3. Set\n");
        printf("4. Display\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                for(i = 1; i<=n*(n+1)/2; i++)
                {
                    scanf("%d", &A[i-1]);
                    break;
                }
            case 2:
                printf("Enter indices: ");
                scanf("%d%d", &i,&j);
                if(i<=j)
                {
                    printf("%d\n", A[(j-1)*n - (j-1)*(j-2)/2 + i-j]);
                }
                else
                {
                    printf("0\n");
                }
                break;
            case 3:
                printf("Enter row, column and element: ");
                scanf("%d%d%d",&i,&j,&x);
                if(i<=j)
                {
                    x=A[(j-1)*n - (j-1)*(j-2)/2 + i-j];
                }
                break;
            case 4:
                for(int i = 1; i<=n; i++)
                {
                    for(int j = 1; j<=n; j++)
                    {
                        if(i==j)
                        {
                            printf("%d\t", A[(j-1)*n - (j-1)*(j-2)/2 + i-j]);
                        }
                        else
                        {
                            printf("0\t");
                        }
                    }
                    printf("\n");
                }
        }
    } while (0<ch && ch<=4);
    
}

struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse_matrix
{
    int m;
    int n;
    int num;
    struct Element *e;
};

void create(struct Sparse_matrix *s)
{
    printf("Enter Dimension: ");
    scanf("%d%d", &s->m, &s->n);
    printf("Enter nunber of non-zero: ");
    scanf("%d", &s->num);
    s->e=(struct Element *)malloc(s->num*sizeof(struct Element));
    for(int t = 0; t<s->num; t++)
    {
        scanf("%d%d%d",&s->e[t].i, &s->e[t].j, &s->e[t].x);
    }
}

void Display(struct Sparse_matrix s)
{
    int k = 0;
    for(int i = 1; i<=s.m; i++)
    {
        for(int j = 1; j<=s.n; j++)
        {
            if(i==s.e[k].i && j==s.e[k].j)
            {
                printf("%d  ",s.e[k].x);
                k++;
            }
            else
            {
                printf("0  ");
            }
        }
        printf("\n");
    }
}

struct Sparse_matrix Addition(struct Sparse_matrix s, struct Sparse_matrix t)
{
    struct Sparse_matrix k;
    if(s.n!=t.n || s.m!=t.n)
    {
        k.m=0;
        k.n=0;
        k.num=0;
        printf("Gadari karbe tohri bahin ki chodo\n");
        return k;
    }
    int a=0,b=0,c=0;
    k.m=s.m;
    k.n=s.n;
    k.num=s.num+t.num;
    k.e=(struct Element *)malloc(k.num*sizeof(struct Element));
    do
    {
        if(a==s.num)
            k.e[c++]=t.e[b++];
        else if(b==t.num)
            k.e[c++]=s.e[a++];
        else if(s.e[a].i==t.e[b].i && s.e[a].j==t.e[b].j)
        {
            k.e[c]=s.e[a++];
            k.e[c++].x+=t.e[b++].x;;
            k.num--;
        }
        else if(s.e[a].i<t.e[b].i)
            k.e[c++]=s.e[a++];
        else if(s.e[a].i>t.e[b].i)
            k.e[c++]=t.e[b++];
        else if(s.e[a].i==t.e[b].i && s.e[a].j<t.e[b].j)
            k.e[c++]=s.e[a++];
        else if(s.e[a].i==t.e[b].i && s.e[a].j>t.e[b].j)
            k.e[c++]=t.e[b++];
    } while (a<s.num || b<t.num);
    
    return k;
}

void main()
{
    struct Sparse_matrix s,t;
    create(&s);
    Display(s);
    create(&t);
    Display(t);
    struct Sparse_matrix k = Addition(s,t);
    Display(k);
}