#include <iostream>
using namespace std;

// pass by reference
// c++ only
// void swap3(int & x, int & y)
// {
//     int temp;
//     temp = x;
//     x=y;
//     y=temp;
// }
// int main()
// {
//     int a=10, b=20;
//     swap(a,b);
//     cout<<a<<" "<<b<<endl;
//     return 0;
// }


//REFERENCE
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

// int main()
// {
//     int *p;
//     p=new int[5];
//     string x = "abcde";
//     for(char z: x)
//     {
//         cout<<z;
//     }
//     return 0;
// }


//RETURN ARRAY AS PARAMETER
// int *func(int size)
// {
//     int *p;
//     p=new int[size];
//     for(int i = 0; i<size; i++)
//     {
//         p[i]=i+1;
//     }
//     return p;
// }
// int main()
// {
//     int *ptr, sz=5;
//     ptr=func(sz);
//     for(int i = 0; i<sz; i++)
//     {
//         cout<<ptr[i]<<endl;
//     }
// }



struct rec
{
    int a[5];
    int n;
};
// void fun(struct rec & t1)
// {
//     t1.a[0]=10;
//     t1.a[1]=9;
//     t1.a[2]=8;
//     t1.a[3]=7;
//     t1.a[4]=6;
// }
// int main()
// {
//     struct rec r1 = {{1,2,3,4,5},5};
//     fun(r1);
//     for(int i = 0; i<5; i++)
//     {
//         cout<<r1.a[i]<<" ";
//     }
// }