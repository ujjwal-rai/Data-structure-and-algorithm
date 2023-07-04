#include <iostream>
#include <stdio.h>

using namespace std;

int area1(int length, int breadth)
{
    return length*breadth;
}
int perimeter(int length, int breadth)
{
    return 2*(length+breadth);
}


//monolitic programming
// int main()
// {
//     int length=0, breadth=0;
//     cout<<"Enter length and breadth"<<endl;
//     cin>>length>>breadth;
//     int a=length*breadth;
//     int p=2*(length+breadth);
//     cout<<"Area: "<<a<<endl;
//     cout<<"Perimeter: "<<p<<endl;
//     return 0;
// }

//modular programming
// int main()
// {
//     int length=0, breadth=0;
//     cout<<"Enter length and breadth"<<endl;
//     cin>>length>>breadth;
//     int a=area1(length,breadth);
//     int p=perimeter(length,breadth);
//     cout<<"Area: "<<a<<endl;
//     cout<<"Perimeter: "<<p<<endl;
//     return 0;
// }


struct Rectangle
{
    int length;
    int breadth;
};

void initialize(struct Rectangle *r, int l, int b)
{
    r->length=l;
    r->breadth=b;
}
int area2(struct Rectangle r)
{
    return r.length*r.breadth;
}
int perimeter2(struct Rectangle r)
{
    return 2*(r.length + r.breadth);
}


//structure and functions
// int main()
// {
//     struct Rectangle r={0,0};
//     int length=0, breadth=0;
//     cout<<"Enter length and breadth"<<endl;
//     //cin>>r.length>>r.breadth;
//     cin>>length>>breadth;
//     initialize(&r, length, breadth);
//     int a=area2(r);
//     int p=perimeter2(r);
//     cout<<"Area: "<<a<<endl;
//     cout<<"Perimeter: "<<p<<endl;
//     return 0;
// }

//obect oriented programing
class rectangle
{
    private:
    int length;
    int breadth;
    public:
    rectangle (int l, int b)
    {
        length=l;
        breadth=b;
    }
    int area3()
    {
        return length*breadth;
    }
    int perimeter3()
    {
        return 2*(length+breadth);
    }
};

// int main()
// {
//     int l=0,b=0;
//     cout<<"Enter length and breadth"<<endl;
//     cin>>l>>b;
//     rectangle r(l,b);
//     int a=r.area3();
//     int p=r.perimeter3();
//     cout<<"Area: "<<a<<endl;
//     cout<<"Perimeter: "<<p<<endl;
//     return 0;
// }
template <class T>
class Arithametic
{
    private:
    T a;
    T b;
    public:
    Arithametic(T a, T b);
    T add();
    T sub();
};
template <class T>
Arithametic<T>::Arithametic(T a, T b)
{
    this->a=a;
    this->b=b;
}
template <class T>
T Arithametic<T>::add()
{
    return a+b;
}
template <class T>
T Arithametic<T>::sub()
{
    return a-b;
}


int main()
{
    Arithametic<int> ar(10,5);
    cout<<ar.add()<<endl;
    Arithametic<float> ar1(0.7,0.8);
    cout<<ar1.add()<<endl;
    return 0;
}


// class rec
// {
//     private:
//     int l;
//     int b;
//     public:
//     rec(){l=b=1;} //constructor
//     rec(int len, int bre); //constructor
//     int area4();
//     int perimeter4();
//     int getlength(){return l;}
//     void setlength(int len){l=len;}
//     ~rec(); //Destructor
// };

// rec::rec(int len, int bre)
// {
//     l=len;
//     b=bre;
// }
// int rec::area4()
// {
//     return l*b;
// }
// int rec::perimeter4()
// {
//     return 2*(l+b);
// }
// rec::~rec()
// {}

// int main()
// {
//     rec r(10,5);
//     cout<<r.area4()<<endl;
//     cout<<r.perimeter4()<<endl;
//     r.setlength(20);
//     cout<<r.getlength();
//     return 0;
// }

