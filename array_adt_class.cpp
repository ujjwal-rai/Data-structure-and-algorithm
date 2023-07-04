#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length;
    void swap(int *x, int *y)
    {
        int temp = *x;
        *x=*y;
        *y=temp;
    }
public:
    Array();
    Array(int sz);
    ~Array();
    int Get(int n);
    void Input(int n);
    void Display();
    void Append(int x);
    void Insert(int n, int x);
    void Delete(int n);
    int linear_search(int x);
    int binary_search(int h, int l, int x);
    void Set(int n, int x);
    int Max();
    int Min();
    int Sum();
    float Avg();
    void BReverse();
    void left_rotation();
    void right_rotation();
    Array *Merge(Array arr2);
    Array *Set_union_s(Array arr2);
    Array *Set_intersection_s(Array arr2);
    Array *Set_difference_s(Array arr2);
};
Array::Array()
{
    size = 10;
    length = 0;
    A = new int[size];
}

Array::Array(int sz)
{
    size = sz;
    A = new int[size];
    length = 0;
}

Array::~Array()
{
    delete []A;
}

int Array::Get(int n)
{
    if (n >= 0 && n < length)
    {
        return A[n];
    }
    return -1;
}

void Array::Input(int n)
{
    if (n > length)
    {
        n = length;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
}

void Array::Display()
{
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout<<"\n";
}

void Array::Append(int x)
{
    if (length < size)
    {
        A[length++] = x;
    }
}

void Array::Insert(int n, int x)
{
    if (n >= 0 && n <= length)
    {
        for (int i = length; i > n; i--)
        {
            A[i] = A[i - 1];
        }
        A[n] = x;
        length++;
    }
}

void Array::Delete(int n)
{
    if (n >= 0 && n < length)
    {
        for (int i = n; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
    }
}

int Array::linear_search(int x)
{
    for (int i = 0; i < length; i++)
    {
        if (x == A[i])
        {
            return i;
        }
    }
    return -1;
}

int Array::binary_search(int h, int l, int x)
{
    if (l <= h)
    {
        int p = (h + l) / 2;
        if (A[p] == x)
            return p;
        else if (A[p] > x)
            return binary_search(p - 1, l, x);
        else
            return binary_search(h, p + 1, x);
    }
    return -1;
}

void Array::Set(int n, int x)
{
    if (n >= 0 && n < length)
    {
        A[n] = x;
    }
}

int Array::Max()
{
    int max = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

int Array::Min()
{
    int min = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] < min)
            min = A[i];
    }
    return min;
}

int Array::Sum()
{
    int total = 0;
    for (int i = 0; i < length; i++)
    {
        total += A[i];
    }
    return total;
}

float Array::Avg()
{
    int total = 0;
    for (int i = 0; i < length; i++)
    {
        total += A[i];
    }
    return (float)total / length;
}

void Array::BReverse()
{
    for (int i = 0; i < length / 2; i++)
    {
        A[i] ^= A[length - 1 - i] ^= A[i] ^= A[length - 1 - i];
    }
}

void Array::left_rotation()
{
    int flag = A[0];
    for (int i = 0; i < length - 1; i++)
    {
        A[i] = A[i + 1];
    }
    A[length - 1] = flag;
}

void Array::right_rotation()
{
    int flag = A[length - 1];
    for (int i = length - 1; i > 0; i--)
    {
        A[i] = A[i - 1];
    }
    A[0] = flag;
}

int a_f_missing_element_s(int A[],int n)
{
    int total = n*(n+1)/2;
    int sum = 0;
    for(int i = 0; i<n; i++)
    {
        sum=sum+A[i];
    }
    return sum-total;
}

int a_nf_missing_element_s(int A[],int n)
{
    int x=0;
    int c=0;
    int k = A[0]-x;
    for(int i = 1; i<n; i++)
    {
        x++;
        if(A[i]-x!=k)
        {
            c=A[i-1]+1;
            break;
        }
    }
    return c;
}

int *n_nf_missing_element_s(int A[],int n)
{
    int x=0;
    int c=A[0]-x;
    int *C=new int[n];
    int k=0;
    for(int i = 1; i<n; i++)
    {
        x++;
        int d = A[i]-x;
        if(A[i]-x!=c)
        {
            for(int j=0; j<d-c; j++)
            {
                C[k]=A[i-1]+j+1;
                k++;
            }
            c=d;
        }
    }
    return C;
}

int maximum(int A[],int n)
{
    int max=A[0];
    for(int i = 1; i<n; i++)
    {
        if(max<A[i])
        {
            max=A[i];
        }
    }
    return max;
}

int minimum(int A[], int n)
{
    int min=A[0];
    for(int i = 1; i<n; i++)
    {
        if(min>A[i])
        {
            min=A[i];
        }
    }
    return min;
}

void n_nf_missing_element_us(int A[],int n)
{
    int z = maximum(A,n);
    int y = minimum(A,n);
    int H[z+1] = {0};
    for(int i = 0; i<n; i++)
    {
        H[A[i]]++;
    }
    for(int i = y; i<=z; i++)
    {
        if(H[i]==0)
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

void Finding_dup(int A[], int n)
{
    int k = 1;
    for(int i = 1; i<n; i++)
    {
        if(A[i]==A[i-1])
        {
            k++;
        }
        else
        {
            cout<<A[i-1]<<" : "<<k<<endl;
            k=1;
        }
    }
    cout<<A[n-1]<<" : "<<k<<endl;
}

void duplicate_wo_us(int A[], int n)
{
    int count{0};
    for(int i = 0; i<n; i++)
    {
        count=1;
        if(A[i]!=-1)
        {
            for(int j = i+1; j<n; j++)
            {
                if(A[i]==A[j])
                {
                    count++;
                    A[j]=-1;
                }
            }
            if(count > 1)
            {
                cout<<A[i]<<" : "<<count<<endl;
                count=1;
            }
        }
    }
}

void duplicate_hash_us(int A[], int n)
{
    int max=maximum(A,n);
    int min=minimum(A,n);
    int H[max+1]={0};
    for(int i = 0; i<n; i++)
    {
        H[A[i]]++;
    }
    for(int i = min; i<=max; i++)
    {
        if(H[i]>1)
        {
            cout<<i<<" : "<<H[i]<<endl;
        }
    }
}

Array* Array::Merge(Array arr2)
{
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else
            arr3->A[k++] = arr2.A[j++];
    }

    for (; i < length; i++)
        arr3->A[k++] = A[i];
    for (; j < arr2.length; j++)
        arr3->A[k++] = arr2.A[j];

    arr3->length = k;
    return arr3;
}

Array *Array::Set_union_s(Array arr2)
{
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length)
    {
        if (A[i] == arr2.A[j])
        {
            arr3->A[k++] = A[i++];
            j++;
        }
        else if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else
            arr3->A[k++] = arr2.A[j++];
    }

    for (; i < length; i++)
        arr3->A[k++] = A[i];
    for (; j < arr2.length; j++)
        arr3->A[k++] = arr2.A[j];

    arr3->length = k;
    return arr3;
}

Array *Array::Set_intersection_s(Array arr2)
{
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length)
    {
        if (A[i] == arr2.A[j])
        {
            arr3->A[k++] = A[i++];
            j++;
        }
        else if (A[i] < arr2.A[j])
            i++;
        else
            j++;
    }

    arr3->length = k;
    return arr3;
}

Array *Array::Set_difference_s(Array arr2)
{
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length)
    {
        if (A[i] == arr2.A[j])
        {
            i++;
            j++;
        }
        else if (A[i] < arr2.A[j])
        {
            arr3->A[k++] = A[i++];
        }
        else
            j++;
    }

    for (; i < length; i++)
    {
        arr3->A[k++] = A[i];
    }

    arr3->length = k;
    arr3->size = size + arr2.size;
    return arr3;
}

void pair_sum_k(int A[], int n, int k)
{
    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            if(A[i]+A[j]==k)
            {
                cout<<A[i]<<" "<<A[j]<<endl;
            }
        }
    }
}

void pair_sort(int A[], int n, int k)
{
    for(int i=0,j=n-1; i<j;)
    {
        if(A[i]+A[j]>k)
        {
            j--;
        }
        else if(A[i]+A[j]<k)
        {
            i++;
        }
        else
        {
            cout<<A[i]<<" "<<A[j]<<endl;
            i++;
            j++;
        }
    }
}

void pair_hash_k(int A[], int n, int k)
{
    int max=maximum(A,n);
    int H[max+1]={0};
    for(int i = 0; i<n; i++)
    {
        H[A[i]]++;
        if(H[k-A[i]]>0 && A[i]<k)
        {
            if(k-A[i]!=A[i] || H[A[i]]!=1)
            {
                cout<<A[i]<<" "<<k-A[i]<<endl;
                H[A[i]]--;
                H[k-A[i]]--;
            }
        }
    }
}

void max_min(int A[], int n)
{
    int max=A[0];
    int min=A[0];
    for(int i = 1; i<n; i++)
    {
        if(min>A[i])
        {
            min=A[i];
        }
        else if(max<A[i])
        {
            max=A[i];
        }
    }
    cout<<"Maximum :"<<max<<"Minimum :"<<min<<endl;
}

int main()
{
    // int A[11]={1,2,3,4,5,6,8,9,10,11,12};
    // int a[9]={6,7,8,9,10,11,13,14,15};
    // int B[17]={6,7,8,9,10,11,13,14,15,17,21,27,28,29,30,31,33};
    // int C[10]={3,7,4,9,12,6,1,11,2,10};
    int b[10]={3,6,8,8,10,12,15,15,15,20};
    int c[10]={8,3,6,4,6,5,6,8,2,7};
    int D[10]={1,3,4,5,6,8,9,10,12,14};
    pair_sort(D,10,10);
    pair_hash_k(c,10,10);
    // n_nf_missing_element_us(C,10);
    // cout<<a_f_missing_element_s(A,11)<<endl;
    // cout<<a_nf_missing_element_s(a,9)<<endl;
    // int *D = n_nf_missing_element_s(B,17);
    // for(int i = 0; i<11; i++)
    // {
    //     cout<<D[i]<<" ";
    // }
    return 0;
}

// int main()
// {
//     Array *arr1;
//     int sz;
//     int x, index;

//     printf("Enter Size of Array: ");
//     scanf("%d", &sz);
//     arr1=new Array(sz);

//     int ch;

//     do
//     {
//         printf("Menu\n");
//         printf("1. Insert\n");
//         printf("2. Delete\n");
//         printf("3. Search\n");
//         printf("4. Sum\n");
//         printf("5. Display\n");
//         printf("6. Exit\n");

//         printf("Enter your choice: ");
//         scanf("%d", &ch);

//         switch (ch)
//         {
//         case 1:
//             printf("Enter an element and index: ");
//             scanf("%d%d", &x, &index);
//             arr1->Insert(index, x);
//             break;
//         case 2:
//             printf("Enter index: ");
//             scanf("%d", &index);
//             arr1->Delete(index);
//             break;
//         case 3:
//             printf("Enter element to search: ");
//             scanf("%d", &x);
//             index = arr1->linear_search(x);
//             printf("Element index is %d\n", index);
//             break;
//         case 4:
//             printf("Sum is %d:\n ", arr1->Sum());
//             break;
//         case 5:
//             arr1->Display();
//             break;
//         }
//         cout<<"\n\n";
//     } while (ch < 6);

//     return 0;
// }