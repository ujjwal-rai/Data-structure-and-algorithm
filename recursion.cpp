#include <stdio.h>


//tail recursion
void fun1(int n)
{
    if(n>0)
    {
        printf("%d ", n); //winding phase
        fun1(n-1);
    }
}


//head recursion
void fun2(int n)
{
    if(n>0)
    {
        fun2(n-1);
        printf("%d ", n); //unwinding phase
    }
}


//tree recursion
void fun3(int n)
{
    if(n>0)
    {
        printf("%d ", n); //winding phase
        fun3(n-1);
        fun3(n-1);
    }
}


//indirect recursion
void id_fun2(int n);

void id_fun1(int n)
{
    if(n>0)
    {
        printf("%d ", n);
        id_fun2(n-1);
    }
}
void id_fun2(int n)
{
    if(n>1)
    {
        printf("%d ", n);
        id_fun1(n/2);
    }
}


//nested recursion
int fun4(int n)
{
    if(n>100)
        return n-10;
    else
        return fun4(fun4(n+11));
}

int sum_n(int n)
{
    if(n>0)
    return n+sum_n(n-1);
    else
    return 0;
}
int I_sum(int n)
{
    int s = 0;
    for(int i = 0; i<n; i++)
    {
        s=s+i+1;
    }
    return s;
}
int D_sum(int n)
{
    return n*(n+1)/2;
}

double factorial(int n)
{
    if(n==0 || n==1)
    return 1;
    else
    return n*factorial(n-1);
}
int power(int p, int n)
{
    if(n>0)
    return p*power(p,n-1);
    else
    return 1;
}
double power_f(int p, int n)
{
    if(n==0)
    {
        return 1;
    }
    if(n%2==0)
        return power_f(p*p, n/2);
    else
        return p*power_f(p*p, (n-1)/2);
}

double e(int x, int n)
{
    static double p=1,f=1;
    double r;
    if(n==0)
        return 1;
    r=e(x,n-1);
    p=p*x;
    f=f*n;
    return r+p/f;
}

double e1(int x, int n)
{
    static double s=1;
    if(n==0)
    {
        return s;
    }
    s=1+((x*s)/n);
    return e1(x,n-1);
}
double e2(int x, int n)
{
    double s=1;
    int num=1;
    int den=1;
    for(int i = 1; i<=n; i++)
    {
        num=num*x;
        den=den*i;
        s = s + (num/den);
    }
    return s;
}

double e3(int x, int n)
{
    double s=1;
    for(; n>0; n--)
    {
        s=1+((x*s)/n);
    }
    return s;
}

double taylor_series(int x, int n)
{
    if(x==0 || n==1)
    {
        return 1;
    }
    return (power_f(x,n-1)/factorial(n-1)) + taylor_series(x,n-1);
}

int fibonachi(int n)
{
    int x = 1;
    int y = 0;
    for(int i = 0; i<n; i++)
    {
        int c = y;
        y=y+x;
        x=c;
    }

    return y;
}


//excessive recursion
int fib(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    return fib(n-1) + fib(n-2);
}
int F[10];
int m_fib(int n)
{
    if(n<=1)
    {
        F[n]=n;
        return n;
    }
    else
    {
        if(F[n-2]==0)
        {
            F[n-2]=m_fib(n-2);
        }
        if(F[n-1]==0)
        {
            F[n-1]=m_fib(n-1);
        }
        F[n]=F[n-1]+F[n-2];
        return F[n-1]+F[n-2];
    }
}

int nCr(int n, int r)
{
    if(r==0 || r==n)
    {
        return 1;
    }
    return n*nCr(n-1,r)/(n-r);
}
int com(int n, int r)
{
    if(r==0||r==n)
    {
        return 1;
    }
    else
    {
        return com(n-1,r) + com(n-1,r-1);
    }
}


void TOH(int n, int A, int B, int C)
{
    if(n>0)
    {
        TOH(n-1, A, C, B);
        printf("from %d to %d\n", A, C);
        TOH(n-1,B,A,C);
    }
}
int functual(int &x, int c) 
{
    c=c-1; 
    if (c == 0)
    {
        return 1;
    }
    x = x + 1; 
    int t = functual(x,c)*x;
    return t;
}

int main()
{
    int p = 5;
    int t = functual(p,p);
    printf("%d\n", t);
    return 0;
}