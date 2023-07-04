#include <stdio.h>
#include <stdlib.h>


//ARRAYS
// int main()
// {
//     int b[5] = {2,9,6,8,10};
//     b[2]=13;
//     return 0;
// }


//STRUCTURES
// struct rectangle
// {
//     int length;
//     int breadth;
// };
// int main()
// {
//     //struct rectangle r;
//     struct rectangle r = {10,5};
//     r.length=15;
//     r.breadth=10;
//     printf("Area of rectangleis %d", r.length*r.breadth);
//     return 0;
// }


// POINTERS
// int summ(int *a, int *b)
// {
//     return *a+*b;
// }
// int main()
// {
//     int a=10, b=5;
//     int *p;
//     p = &a;
//     printf("%d  ", a);
//     printf("%d", *p);
//     printf("  %d", &a);
//     printf("  %d", p);
//     printf("  %d", summ(&a, &b));
//     return 0;
// }


//REFERENCE
//used in cpp not in c......
// int main()
// {
//     int a = 10;
//     int &r = a;
//     printf("%d", a);
//     r++;
//     printf("  %d", r);
//     printf("  %d", a);
//     return 0;
// }


//POINTER TO A STRUCTURE
// struct Rectangle
// {
//     int l;
//     int b;
// };
// int main()
// {
//     struct Rectangle r = {10,5};
//     struct Rectangle *p=&r;
//     r.l = 15;
//     p->l = 20;
//     //(*p).l = 20;
//     printf("%d", r.l);

//     struct Rectangle *q;
//     (struct Rectangle *) malloc(sizeof(struct Rectangle));
//     q->l = 10;
//     q->b = 5;
// }


//FUNCTIONS
// int add(int a, int b)
// {
//     return a+b;
// }
// int main()
// {
//     int a = 8;
//     int b = 7;
//     printf("%d", add(a,b));
//     return 0;
// }


//PARAMETER PASSING METHODS
//pass by value
// void swap1(int x, int y)
// {
//     int temp;
//     temp = x;
//     x=y;
//     y=temp;
// }

//pass by address
// void swap2(int *x, int *y)
// {
//     int temp;
//     temp=*x;
//     *x=*y;
//     *y=temp;
// }

//pass by reference
//c++ only
// void swap3(int x, int & y)
// {
//     int temp;
//     temp = x;
//     x=y;
//     y=temp;
// }

// int main()
// {
//     int a,b;
//     a=10;
//     b=20;
//     swap1(a,b);
//     printf("%d %d\n", a,b);
//     swap2(&a,&b);
//     printf("%d %d", a,b);
//     // swap3(a,b);
//     // printf("%d %d", a,b);
//     return 0;
// }


//ARRAYS AS PARAMETERS
// void fun(int a[], int n)
// {
//     int i;
//     for(i=0; i<n; i++)
//     {
//         printf("%d ", a[i]);
//     }
// }
// int main()
// {
//     int a[5]={2,4,6,8,10};
//     fun(a,5);
// }


//STRUCTURE AS PARAMETER
//call by value
struct rectangle
{
    int length;
    int breadth;
};
// int area(struct rectangle r1)
// {
//     return r1.length*r1.breadth;
// }
// int main()
// {
//     struct rectangle r = {10,5};
//     printf("%d", area(r));
//     return 0;
// }

//call by refernce
// int area(struct rectangle &r1)
// {
//     return r1.length*r1.breadth;
// }
// int main()
// {
//     struct rectangle r = {10,5};
//     printf("%d", area(r));
//     return 0;
// }

//call by value
// int area(struct rectangle *r1)
// {
//     return r1->length*r1->breadth;
// }
// void changelength(struct rectangle *p, int l)
// {
//     p->length=l;
// }
// int main()
// {
//     struct rectangle r = {10,5};
//     changelength(&r, 20);
//     printf("%d", area(&r));
//     return 0;
// }