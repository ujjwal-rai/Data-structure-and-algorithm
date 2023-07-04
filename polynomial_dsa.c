#include <stdio.h>
#include <stdlib.h>
struct term
{
    int coeff;
    int exp;
};

struct poly
{
    int n;
    struct term *t;
};

void create(struct poly *p)
{
    printf("No of non-zero terms: ");
    scanf("%d", &p->n);
    p->t=(struct term *)malloc(p->n*sizeof(struct term));
    printf("Enter polynomial terms\n");
    for(int i = 0; i<p->n; i++)
    {
        scanf("%d%d",&p->t[i].coeff, &p->t[i].exp);
    }
}

void display(struct poly p)
{
    for(int i = 0; i<p.n; i++)
    {
        printf("%dx%d", p.t[i].coeff, p.t[i].exp);
        if(i<p.n-1)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

struct poly *addition(struct poly *p, struct poly *q)
{
    struct poly *sum;
    sum=(struct poly *)malloc(sizeof(struct poly));
    sum->t=(struct term *)malloc((p->n+q->n)*sizeof(struct term));
    int i=0, j=0, k=0;
    do
    {
        if(i==p->n)
            sum->t[k++]=q->t[j++];
        else if(j==q->n)
            sum->t[k++]=p->t[i++];
        else if(p->t[i].exp==q->t[j].exp)
        {
            sum->t[k].exp=p->t[i].exp;
            sum->t[k++].coeff=p->t[i++].coeff+q->t[j++].coeff;
        }
        else if(p->t[i].exp>q->t[j].exp)
            sum->t[k++]=p->t[i++];
        else if(p->t[i].exp<q->t[j].exp)
            sum->t[k++]=q->t[j++];
    } while (i<p->n || j<q->n);
    sum->n=k;
    return sum;
}

int main()
{
    struct poly p1, p2, *p3;
    create(&p1);
    display(p1);
    create(&p2);
    display(p2);
    p3=addition(&p1,&p2);
    display(*p3);
    return 0;
}