#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

char *change_case(char str[])
{
    for(int i = 0; str[i]!='\0'; i++)
    {
        if(str[i]>=65 && str[i]<=90)
        {
            str[i]+=32;
        }
        if(str[i]>=97 && str[i]<=122)
        {
            str[i]-=32;
        }
    }
    return str;
}

void count_vow_cons(char str[])
{
    int vow=0;
    int cons=0;
    int words=1;
    for(int i = 0; str[i]!='\0'; i++)
    {
        if(str[i]==' ' && str[i-1]!=' ')
        {
            words++;
        }
        else if(str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U' || str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
        {
            vow++;
        }
        else if((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122))
        {
            cons++;
        }
    }
    printf("The words are: %d\n", words);
    printf("The vowels are: %d\n", vow);
    printf("The consonents are: %d\n", cons);
}

bool valid(char name[])
{
    for(int i = 0; name[i]!='\0';i++)
    {
        if(!(name[i]>=65 && name[i]<=90) && !(name[i]>=97 && name[i]<=122) && !(name[i]>=48 && name[i]<=57))
        {
            return false;
        }
    }
    return true;
}

char *rev_str(char name[])
{
    int n=0;
    for(int i = 0; name[i]!='\0'; i++)
    {
        n++;
    }
    char *newstr=(char *)malloc(n*sizeof(char));
    for(int i = 0; name[i]!='\0'; i++)
    {
        newstr[n-1-i]=name[i];
    }
    newstr[n]='\0';
    return newstr;
}

void g_rev(char name[])
{
    int n=0;
    for(int i = 0; name[i]!='\0'; i++)
    {
        n++;
    }
    int i = 0, j = n-1;
    for(;i<j;i++,j--)
    {
        name[j] ^= name[i] ^= name[j] ^= name[i];
    }
}

int comp_str(char A[], char B[])
{
    int x=0;
    int i = 0;
    for(; A[i]!='\0' && B[i]!='\0'; i++)
    {
        if(A[i]>=65 && A[i]<=90)
            A[i]+=32;
        if(B[i]>=65 && B[i]<=90)
            B[i]+=32;
        if(A[i]!=B[i])
            break;
    }
    if(A[i]>B[i])
        x=1;
    else if(B[i]>A[i])
        x=-1;
    return x;
}

bool palindrome(char A[])
{
    int n = 0;
    for(int i = 0; A[i]!='\0'; i++)
    {
        n++;
    }
    n--;
    for(int i = 0; i<n; i++,n--)
    {
        if(A[i]!=A[n])
        {
            return false;
        }
    }
    return true;
}

void compare_duplicate(char A[])
{
    int x = 1;
    for(int i = 0; A[i]!='\0'; i++)
    {
        for(int j = i+1; A[j]!='\0'; j++)
        {
            if(!(A[i]>=65 && A[i]<=90) && !(A[i]>=97 && A[i]<=122))
            {
                break;
            }
            if(A[i]==A[j])
            {
                x++;
                A[j]='1';
            }
        }
        if((A[i]>=65 && A[i]<=90) || (A[i]>=97 && A[i]<=122))
        {
            cout<<A[i]<<" "<<x<<endl;
        }
        x=1;
    }
    cout<<"\n";
}

void duplicate_hash(char A[])
{
    int H[26]={0};
    for(int i = 0; A[i]!='\0'; i++)
    {
        H[A[i]-97]++;
    }
    for(int i = 0; i<26; i++)
    {
        if(H[i]>1)
        {
            cout<<char(i+97)<<" "<<H[i]<<endl;
        }
    }
}

void bitwise_dup(char A[])
{
    long int H=0, x=0;
    //f = 102 - 97 = 5;
    //i = 105 - 97 = 8;, 
    for(int i=0; A[i]!='\0'; i++)
    {
        x=1;
        x=x<<(A[i]-97);
        if((x&H)>0) //masking
        {
            printf("%c is Duplicate\n", A[i]);
        }
        else
        {
            H=x|H; //merging
        }
    }
}

void Anagram_1(char A[], char B[])
{
    int x = 0;
    for(int i = 0; A[i]!='\0' && x==0; i++)
    {
        for(int j = 0; B[j]!='\0'; j++)
        {
            if(A[i]==B[j])
            {
                B[j]='0';
                break;
            }
            else if(A[i]!=B[j] && B[j+1]=='\0')
            {
                x=1;
                printf("Not anagram\n");
                break;
            }
        }
    }
    if(x==0)
        printf("Anagram\n");    
}

void Anagram_hash(char A[], char B[])
{
    int x = 0;
    int *H = new int[26];
    for(int i = 0; i<26; i++)
    {
        H[i]=0;
    }
    for(int i = 0; A[i]!='\0'; i++)
    {
        H[A[i]-97]++;
        H[B[i]-97]--;
    }
    for(int i = 0; i<26; i++)
    {
        if(H[i]!=0)
        {
            printf("Not anagram\n");
            x=1;
            break;
        }
    }
    if(x==0)
        printf("Anagram\n");
}

void permutation_string(char str[], int k)
{
    static char res[10];
    static int A[10]={0};
    int i;
    if(str[k]=='\0')
    {
        res[k]='\0';
        printf("%s\t",res);
    }
    else
    {
        for(i=0; str[i]!='\0';i++)
        {
            if(A[i]==0)
            {
                res[k]=str[i];
                A[i]=1;
                permutation_string(str,k+1);
                A[i]=0;
            }
        }
    }
}

void permu(char A[],int l, int h)
{
    if(l==h)
    {
        cout<<A<<endl;
    }
    else
    {
        for(int i=l; i<=h; i++)
        {
            char temp = A[i];
            A[i]=A[l];
            A[l]=temp;
            permu(A,l+1,h);
            char flag = A[i];
            A[i]=A[l];
            A[l]=flag;
        }
    }
}

int main()
{
    char str[]="123";
    permu(str,0,2);
    return 0;
}


//Bitwise operations
//1. left shift <<
//2. Bits ORing (Merging)
//3. Bits ANDing (Masking)

//permutation of a string
//state space tree
//back tracking - it will perform brute force
//brute force - finding out all the permutation
//recursion - for back tracking