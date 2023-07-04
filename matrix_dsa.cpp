/*special matrices
1. Diagonal Matrix
2. Lower Triangular matrix
3. upper Triangular matrix
4. symmetric matrix
5. tridiagonal matrix
6. band matrix
7. toeptitz matrix
8. sparse matrix*/

#include <bits/stdc++.h>
using namespace std;

class Lower_triang_mat
{
private:
    int n;
    int *A;
public:
    Lower_triang_mat(int n)
    {
        this->n=n;
        A=new int[n*(n+1)/2];
    }
    void Set_r(int i, int j, int x)
    {
        if(i>=j)
            A[((i*(i-1))/2) + (j-1)]=x;
    }
    int Get_r(int i, int j)
    {
        if(i>=j)
            return A[((i*(i-1))/2) + (j-1)];
        return 0;
    }
    void Display_r()
    {
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=n; j++)
            {
                if(i>=j)
                    cout<<A[((i*(i-1))/2) + (j-1)]<<"\t";
                else
                    cout<<0<<"\t";
            }
            cout<<"\n";
        }
    }
    void Set_c(int i, int j, int x)
    {
        if(i>=j)
            A[(n*(j-1)) - ((j-2)*(j-1)/2) + (i-j)]=x;
    }
    int Get_c(int i, int j)
    {
        if(i>=j)
            return A[(n*(j-1)) - ((j-2)*(j-1)/2) + (i-j)];
        return 0;
    }
    void Display_c()
    {
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=n; j++)
            {
                if(i>=j)
                    cout<<A[(n*(j-1))-((j-2)*(j-1)/2)+(i-j)]<<"\t";
                else
                    cout<<0<<"\t";
            }
            cout<<"\n";
        }
    }
    ~Lower_triang_mat()
    {
        delete []A;
    }
};

class Diagonal
{
private:
    int n;
    int *A;
public:
    Diagonal(int n)
    {
        this->n=n;
        A=new int[n];
    }
    void Set_d(int i, int j, int x)
    {
        if(i==j)
            A[i-1]=x;
    }
    int Get_d(int i, int j)
    {
        if(i==j)
            return A[i-1];
        return 0;
    }
    void Display_d()
    {
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(i==j)
                    cout<<A[i]<<"\t";
                else
                    cout<<0<<"\t";
            }
            cout<<"\n";
        }
    }
    ~Diagonal()
    {
        delete []A;
    }
};

struct Matrix
{
    int *A;
    int n;
};

void Set(struct Matrix *m,int i, int j, int x)
{
    if(i==j)
        m->A[i-1]=x;
    else
        m->A[i-1]=0;
}

void Set_ltm_r(struct Matrix *m,int i, int j, int x)
{
    if(i>=j)
        m->A[(i*(i-1)/2+(j-1))]=x;
}

int get_ltm_r(struct Matrix m,int i, int j)
{
    if(i>=j)
        return m.A[(i*(i-1)/2+(j-1))];
    else
        return 0;
}

void Display_ltm_r(struct Matrix m)
{
    for(int i = 1; i<=m.n; i++)
    {
        for(int j = 1; j<=m.n; j++)
        {
            if(i>=j)
                cout<<m.A[(i*(i-1)/2+(j-1))]<<"\t";
            else
                cout<<0<<"\t";
        }
        cout<<"\n";
    }
}

void Set_ltm_c(struct Matrix *m,int i, int j, int x)
{
    if(i>=j)
        m->A[(((m->n)*(j-1))-((j-2)*(j-1)/2)+(i-j))]=x;
}

int get_ltm_c(struct Matrix m,int i, int j)
{
    if(i>=j)
        return m.A[(((m.n)*(j-1))-((j-2)*(j-1)/2)+(i-j))];
    else
        return 0;
}

void Display_ltm_c(struct Matrix m)
{
    for(int i = 1; i<=m.n; i++)
    {
        for(int j = 1; j<=m.n; j++)
        {
            if(i>=j)
                cout<<m.A[(((m.n)*(j-1))-((j-2)*(j-1)/2)+(i-j))]<<"\t";
            else
                cout<<0<<"\t";
        }
        cout<<"\n";
    }
}

int get(struct Matrix m,int i, int j)
{
    if(i==j)
        return m.A[i-1];
    else
        return 0;
}

void Display(struct Matrix m)
{
    for(int i = 0; i<m.n; i++)
    {
        for(int j = 0; j<m.n; j++)
        {
            if(i==j)
                cout<<m.A[i]<<"\t";
            else
                cout<<0<<"\t";
        }
        cout<<"\n";
    }
}

bool is_diag_mat(int **A, int n)
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(A[i]==A[j]!=0 && j!=i)
            {
                return false;
            }
        }
    }
    return true;
}

class upper_triang_mat
{
    private:
    int n;
    int *A;
    public:
    upper_triang_mat(int n)
    {
        this->n=n;
        A=new int[n*(n+1)/2];
    }
    void Set_utm_r(int i, int j, int x)
    {
        if(i<=j)
            A[n*(i-1)-(i-1)*(i-2)/2 + j-i]=x;
    }
    int Get_utm_r(int i, int j)
    {
        if(i<=j)
            return A[n*(i-1)-(i-1)*(i-2)/2 + j-i];
        else
            return 0;
    }
    void Display_utm_r()
    {
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=n; j++)
            {
                if(i<=j)
                    cout<<A[n*(i-1)-(i-1)*(i-2)/2 + j-i]<<"\t";
                else
                    cout<<0<<"\t";
            }
            cout<<"\n";
        }
    }
    void Set_utm_c(int i, int j, int x)
    {
        if(i<=j)
            A[j*(j-1)/2 + i-1]=x;
    }
    int Get_utm_c(int i, int j)
    {
        if(i<=j)
            return A[j*(j-1)/2 + i-1];
        else
            return 0;
    }
    void Display_utm_c()
    {
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=n; j++)
            {
                if(i<=j)
                    cout<<A[j*(j-1)/2 + i-1]<<"\t";
                else
                    cout<<0<<"\t";
            }
            cout<<"\n";
        }
    }
};

class tridiagonal_matrix
{
    private:
    int n;
    int *A;
    public:
    tridiagonal_matrix(int n)
    {
        this->n=n;
        A=new int[3*n-2];
    }
    void Set_tm_r(int i, int j, int x)
    {
        if(abs(i-j)<=1)
            A[3*(i-1)+j-i]=x;
    }
    int Get_tm_r(int i, int j)
    {
        if(abs(i-j)<=1)
            return A[3*(i-1)+j-i];
        else
            return 0;
    }
    void Display_tm_r()
    {
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=n; j++)
            {
                if(abs(i-j)<=1)
                    cout<<A[3*(i-1)+j-i]<<"\t";
                else
                    cout<<0<<"\t";
            }
            cout<<"\n";
        }
    }
    ~tridiagonal_matrix()
    {
        delete []A;
    }

};

class square_band_matrix
{
    private:
    int n;
    int t;
    int *A;
    public:
    square_band_matrix(int n, int t)
    {
        this->n=n;
        this->t=t;
        A=new int[(2*t+1)*n - t*(t+1)];
    }
    void Set_tm_r(int i, int j, int x)
    {
        if(abs(i-j)<=t)
            A[(2*t+1)*(i-1)+j-i]=x;
    }
    int Get_tm_r(int i, int j)
    {
        if(abs(i-j)<=t)
            return A[(2*t+1)*(i-1)+j-i];
        else
            return 0;
    }
    void Display_tm_r()
    {
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=n; j++)
            {
                if(abs(i-j)<=t)
                    cout<<A[(2*t+1)*(i-1)+j-i]<<"\t";
                else
                    cout<<0<<"\t";
            }
            cout<<"\n";
        }
    }
    ~square_band_matrix()
    {
        delete []A;
    }

};

class toeplitz_matrix
{
    private:
    int n;
    int *A;
    public:
    toeplitz_matrix(int n)
    {
        this->n=n;
        A=new int[2*n-1];
    }
    void Set_tm_r(int i, int j, int x)
    {
        if(i<=j)
            A[j-i]=x;
        else if(i>j)
            A[n+i-j-1]=x;
    }
    int Get_tm_r(int i, int j)
    {
        if(i<=j)
            return A[j-i];
        else if(i<=j)
            return A[n+i-j-1];
    }
    void Display_tm_r()
    {
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=n; j++)
            {
                if(i<=j)
                    cout<<A[j-i]<<"\t";
                else if(i>j)
                    cout<<A[n+i-j-1]<<"\t";
            }
            cout<<"\n";
        }
    }
    ~toeplitz_matrix()
    {
        delete []A;
    }

};

class Element
{
public:
    int i;
    int j;
    int x;
};

class Sparse_matrix
{
    private:
    int m;
    int n;
    int num;
    Element *e;
    public:
    Sparse_matrix(int m, int n, int num)
    {
        this->m=m;
        this->n=n;
        this->num=num;
        e = new Element[this->num];
    }

    
    friend istream & operator>>(istream &is, Sparse_matrix &s);
    friend ostream & operator<<(ostream &os, Sparse_matrix &s);

    Sparse_matrix operator+(Sparse_matrix &t);

    ~Sparse_matrix()
    {
        delete [] e;
    }
};

istream & operator>>(istream &is, Sparse_matrix &s)
{
    cout<<"Enter non-zero elements\n";
    for(int i = 0; i<s.num; i++)
        cin>>s.e[i].i>>s.e[i].j>>s.e[i].x;
    return is;
}
ostream & operator<<(ostream &os, Sparse_matrix &s)
{
    int k = 0;
    for(int i = 1; i<=s.m; i++)
    {
        for(int j = 1; j<=s.n; j++)
        {
            if(i==s.e[k].i && j==s.e[k].j)
                cout<<s.e[k++].x<<"  ";
            else
                cout<<"0  ";
        }
        cout<<"\n";
    }
    return os;
}

Sparse_matrix Sparse_matrix::operator+(Sparse_matrix &t)
{
    if(n!=t.n || m!=t.n)
    {
        Sparse_matrix *k = new Sparse_matrix(0,0,0);
        cout<<"Gadari karbe tohri bahin ki chodo\n";
        return *k;
    }
    Sparse_matrix *k=new Sparse_matrix(m,n,num+t.num);
    int a=0,b=0,c=0;
    do
    {
        if(a==num)
            k->e[c++]=t.e[b++];
        else if(b==t.num)
            k->e[c++]=e[a++];
        else if(e[a].i==t.e[b].i && e[a].j==t.e[b].j)
        {
            k->e[c]=e[a++];
            k->e[c++].x+=t.e[b++].x;
        }
        else if(e[a].i<t.e[b].i)
            k->e[c++]=e[a++];
        else if(e[a].i>t.e[b].i)
            k->e[c++]=t.e[b++];
        else if(e[a].i==t.e[b].i && e[a].j<t.e[b].j)
            k->e[c++]=e[a++];
        else if(e[a].i==t.e[b].i && e[a].j>t.e[b].j)
            k->e[c++]=t.e[b++];
    } while (a<num || b<t.num);
    
    return *k;
}

int main()
{
    Sparse_matrix s1(5,5,5);
    Sparse_matrix s2(5,5,7);
    cin>>s1;
    cin>>s2;
    Sparse_matrix s3=s1+s2;
    cout<<s3;
    return 0;
}