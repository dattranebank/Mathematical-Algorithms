#include <iostream>
#include <string> // for string and to_string()
using namespace std;

// 3. The Nth Fibonnaci (Tìm số Fibonacci thứ N)
// Link exercise: https://www.geeksforgeeks.org/problems/the-nth-fibonnaci3150/1
// Link answer:

// Cách 1: Tự code
// 360/360
// Hoàn thành
int fib1(int n)
{
    int F0=0;
    int F1=1;
    int Fn=0;
    if (n==0) return 0;
    if (n==1) return 1;

    string str0,str1,strn;
    char c0,c1,cn;
    for (int i=1;i<n;i++)
    {
        str0=to_string(F0);
        str1=to_string(F1);
        c0=str0[str0.length()-1];
        c1=str1[str1.length()-1];

        Fn=c0-'0'+c1-'0';
        F0=c1-'0';
        F1=Fn;
    }
    strn=to_string(Fn);
    cn=strn[strn.length()-1];
    Fn=cn-'0';
    return Fn;
}


// Cách 2: Tham khảo trên GFG
// 360/360
// Hoàn thành
int fib2(int n)
{
    int F0=0;
    int F1=1;
    int Fn=0;
    if (n==0) return 0;
    if (n==1) return 1;

    for (int i=1;i<n;i++)
    {
        Fn=(F0+F1)%10;
        F0=F1;
        F1=Fn;
    }
    return Fn;
}


int main()
{
    int n;
    cout <<"Nhap n:"; cin >>n;
    cout <<fib2(n);
}


