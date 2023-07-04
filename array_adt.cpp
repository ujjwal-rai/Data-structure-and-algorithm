#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

struct Array
{
    int *A;
    int size;
    int length;
};

struct Rec
{
    int A[100];
    int size;
    int length;
};


void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}


void Display(struct Array arr)
{
    for(int i = 0; i<arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}
void Display(struct Rec arr)
{
    for(int i = 0; i<arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}


void Append(struct Array *arr,int x)
{
    if(arr->length < arr->size)
    {
        arr->A[arr->length++]=x;
    }
}


void Insert(struct Array *arr, int n, int x)
{
    if(n>=0 && n <= arr->length)
    {
        for(int i = arr->length; i>n; i--)
        {
            arr->A[i]=arr->A[i-1];
        }
        arr->A[n]=x;
        arr->length++;
    }
}


void Delete(struct Array *arr, int n)
{
    if(n>=0 && n <= arr->length)
    {
        for(int i = n; i<arr->length; i++)
        {
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
    }
}
int Delete2(struct Array *arr, int n)
{
    int x=0;
    if(n>=0 && n <= arr->length)
    {
        x=arr->A[n];
        for(int i = n; i<arr->length; i++)
        {
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return x;
}



int linear_search(struct Array arr, int x)
{
    int n=-1;
    for(int i = 0; i<arr.length; i++)
    {
        if(x==arr.A[i])
        {
            n=i;
            return n;
        }
    }
    return n;
}
int transposition_linear_search(struct Array *arr,int x)
{
    int n=-1;
    for(int i = 0; i<arr->length; i++)
    {
        if(x==arr->A[i])
        {
            n=i;
        }
        if(i!=0)
        {
            swap(&arr->A[i],&arr->A[i-1]);
            //arr->A[i] ^= arr->A[i-1] ^= arr->A[i] ^= arr->A[i-1];
        }
        return n;
    }
    return n;
}
int binary_search(struct Array arr, int l, int h, int x)
{
    int p=(h+l)/2;
    if(arr.A[l]>x || arr.A[h]<x)
        return -1;
    else if(arr.A[p]==x)
        return p;
    else if(arr.A[p]>x)
        return binary_search(arr,l,p-1,x);
    else
        return binary_search(arr,p+1,h,x);
}



int Get(struct Array arr, int n)
{
    if(n>=0 && n<arr.length)
        return arr.A[n];
    else
        return -1;
}
void Set(struct Array *arr, int n, int x)
{
    if(n>=0 && n<arr->length)
    {
        arr->A[n] = x;
    }
}
int Max(struct Array arr)
{
    int x = arr.A[0];
    for(int i = 1; i<arr.length; i++)
    {
        if(x<arr.A[i])
            x=arr.A[i];
    }
    return x;
}
int Min(struct Array arr)
{
    int x = arr.A[0];
    for(int i = 1; i<arr.length; i++)
    {
        if(x>arr.A[i])
            x=arr.A[i];
    }
    return x;
}
int Sum(struct Array arr)
{
    int total = 0;
    for(int i = 0; i<arr.length; i++)
    {
        total = total + arr.A[i];
    }
    return total;
}
int Sum1(struct Array arr, int n)
{
    if(n==0)
    {
        return arr.A[0];
    }
    else if(n<0)
    {
        return 0;
    }
    else
    {
        return arr.A[n]+Sum1(arr,n-1);
    }
}
float Avg(struct Array arr)
{
    int total = 0;
    for(int i = 0; i<arr.length; i++)
    {
        total = total + arr.A[i];
    }
    return (float)total/arr.length;
}


void WReverse(struct Array *arr)
{
    struct Array brr;
    brr.size=arr->size;
    brr.length=arr->length;
    brr.A = (int *)malloc(brr.size*sizeof(int));
    for(int i = 0; i<brr.length; i++)
    {
        brr.A[i]=arr->A[brr.length-1-i];
    }
    *arr=brr;
}
void BReverse(struct Array *arr)
{
    for(int i = 0; i<arr->length/2; i++)
        arr->A[i] ^= arr->A[arr->length-1-i] ^= arr->A[i] ^= arr->A[arr->length-1-i];
}
void left_rotation(struct Array *arr)
{
    int flag = arr->A[0];
    for(int i = 0; i<arr->length - 1; i++)
    {
        arr->A[i]=arr->A[i+1];
    }
    arr->A[arr->length-1]=flag;
}
void right_rotation(struct Array *arr)
{
    int flag = arr->A[arr->length-1];
    for(int i = arr->length - 1; i>0; i--)
    {
        arr->A[i]=arr->A[i-1];
    }
    arr->A[0]=flag;
}


void sort_insert(struct Array *arr, int x)
{
    int i = arr->length-1;
    if(arr->length==arr->size)
    {
        return;
    }
    while(i>=0 && arr->A[i]>x)
    {
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}
bool check_sorted(struct Array arr)
{
    for(int i = 0; i<arr.length-1; i++)
    {
        if(arr.A[i]>arr.A[i+1])
        {
            return false;
        }
    }
    return true;
}
void pos_neg(struct Rec *arr)
{
    int i = 0, j = arr->length-1;
    while(i<j)
    {
        if(arr->A[i]<0)
        {
            i++;
        }
        if(arr->A[j]>0)
        {
            j--;
        }
        if(arr->A[i]>0 && arr->A[j]<0)
        {
            arr->A[i] ^= arr->A[j] ^= arr->A[i] ^= arr->A[j];
            i++;
            j--;
        }
    }
}


int *Merge_array(int A[], int a, int B[], int b)
{
    int *D;
    D=(int *)malloc((a+b)*sizeof(int));
    int x=0, y=0;
    for(int i = 0; i<a+b; i++)
    {
        if(A[x]<=B[y] && x<a && y<b)
        {
            D[i]=A[x];
            x++;
        }
        else if(B[y]<A[x] && x<a && y<b)
        {
            D[i]=B[y];
            y++;
        }
        else if(x>=a)
        {
            D[i]=B[y];
            y++;
        }
        else if(y>=a)
        {
            D[i]=A[x];
            x++;
        }
    }
    return D;
}
struct Array *Merge(struct Array *arr1, struct Array *arr2)
{
    int i=0,j=0,k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else
            arr3->A[k++]=arr2->A[j++];
    }
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j];
    arr3->length=arr1->length+arr2->length;
    arr3->size=arr1->size+arr2->size;
    return arr3;
}


struct Rec *Set_union_us(struct Rec *arr1, struct Rec *arr2)
{
    struct Rec *arr=(struct Rec *)malloc(sizeof(struct Rec));
    arr->length=arr1->length+arr2->length;
    arr->size=arr1->size+arr2->size;
    for(int i = 0; i<arr1->length; i++)
        arr->A[i]=arr1->A[i];
    int k=0;
    for(int i = 0; i<arr2->length; i++)
    {
        int x=0;
        for(int j = 0; j<arr1->length; j++)
        {
            if(arr2->A[i]==arr1->A[j])
            {
                x=1;
                break;
            }
        }
        if(x==0)
        {
            arr->A[arr1->length + k]=arr2->A[i];
            k++;
        }
    }
    arr->length=k;
    return arr;
}
struct Array *Set_union_s(struct Array *arr1, struct Array *arr2)
{
    int i=0,j=0,k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]==arr2->A[j])
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
        else if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else
            arr3->A[k++]=arr2->A[j++];
    }
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j];
    arr3->length=k;
    arr3->size=arr1->size+arr2->size;
    return arr3;
}
struct Rec *Set_intersection_us(struct Rec *arr1, struct Rec *arr2)
{
    struct Rec *arr=(struct Rec *)malloc(sizeof(struct Rec));
    arr->length=arr2->length;
    arr->size=arr2->size;
    int k = 0;
    for(int i = 0; i<arr2->length; i++)
    {
        int x=1;
        for(int j = 0; j<arr1->length; j++)
        {
            if(arr2->A[i]==arr1->A[j])
            {
                x=0;
                break;
            }
        }
        if(x==0)
        {
            arr->A[k]=arr2->A[i];
            k++;
        }
    }
    arr->length=k;
    return arr;
}
struct Array *Set_intersection_s(struct Array *arr1, struct Array *arr2)
{
    int i=0,j=0,k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]==arr2->A[j])
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
        else if(arr1->A[i]<arr2->A[j])
            i++;
        else
            j++;
    }
    arr3->length=k;
    arr3->size=arr1->size+arr2->size;
    return arr3;
}
struct Rec *set_difference(struct Rec *arr1, struct Rec *arr2)
{
    struct Rec *arr=(struct Rec *)malloc(sizeof(struct Rec));
    int k = 0;
    for(int i = 0; i<arr1->length; i++)
    {
        int x=0;
        for(int j = 0; j<arr2->length; j++)
        {
            if(arr1->A[i]==arr2->A[j])
            {
                x=1;
                break;
            }
        }
        if(x==0)
        {
            arr->A[k]=arr1->A[i];
            k++;
        }
    }
    arr->length=k;
    return arr;
}



// int main()
// {
//     // struct Array arr;
//     // arr.size = 10;
//     // arr.A=(int *)malloc(arr.size*sizeof(int));
//     // arr.length=5;
//     // for(int i = 0; i<arr.length; i++)
//     // {
//     //     arr.A[i]=i+2;
//     // }

//     // Append(&arr,10);
//     // Insert(&arr,6,11);
//     // Display(arr);
//     // sort_insert(&arr,1);
//     // Display(arr);
//     // printf("%s", check_sorted(arr) ? "true" : "false");
//     struct Rec asr = {{2,-3,25,10,-15,-7},10,6};
//     struct Rec adr = {{4,8,2,15,10,-3,0},10,7};
//     struct Rec *ans = set_difference(&asr,&adr);
//     // pos_neg(&asr);
//     // Display(asr);
//     // free(arr.A);


//     // int A[7]={2,5,9,18,27,31,98};
//     // int B[9]={1,4,7,9,13,29,31,55,105};
//     // int *X = Merge_array(A,7,B,9);
//     for(int i = 0; i<ans->length; i++)
//     {
//         printf("%d ", ans->A[i]);
//     }
//     return 0;
// }


//condition ? true_expression : false_expression
//age < 18 ? printf("A Child") : printf("An Adult");

//swap
//a ^= b ^= a ^= b;

//The -->

//++i is faster than i++

int main()
{
    struct Array arr1;
    int ch;
    int x, index;

    printf("Enter Size of Array: ");
    scanf("%d", &arr1.size);
    arr1.A=(int *)malloc(arr1.size*sizeof(int));
    arr1.length=0;

    do
    {
        printf("Menu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:printf("Enter an element and index: ");
                scanf("%d%d", &x, &index);
                Insert(&arr1, index,x);
                break;
            case 2:printf("Enter index: ");
                scanf("%d", &index);
                x=Delete2(&arr1,index);
                printf("Deleted Element is %d\n", x);
                break;
            case 3:printf("Enter element to search: ");
                scanf("%d", &x);
                index=linear_search(arr1,x);
                printf("Element index is %d\n", x);
                break;
            case 4:printf("Sum is %d\n: ", Sum(arr1));
                break;
            case 5:Display(arr1);
        }
    }while(ch<6);

    return 0;
}