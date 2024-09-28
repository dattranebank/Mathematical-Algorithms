#include <iostream>
using namespace std;

// 4. Modified Fibonacci
// Link exercise: https://www.geeksforgeeks.org/problems/modified-fibonacci4449/1
// Link answer:

// Cách 1: Tự code
// 109/207
// Lỗi: Vượt quá thời gian
long long modifiedFib1(long long n, int A, int B, int C)
{
    long long F0=A+B;
    long long F1=B+C;
    long long Fn=0;
    if (n==1) return F0;
    if (n==2) return F1;

    long long mod=1e9+7; // 10^9+7
    for (int i=2;i<n;i++)
    {
        Fn=(F1-F0)%mod;
        F0=F1;
        F1=Fn;
    }
    if (Fn<0) return Fn+mod;
    else return Fn%mod;
}


// Cách 2: Tham khảo trên GFG
// 207/207
// Hoàn thành
long long modifiedFib2(long long n, int A, int B, int C)
{
    n=n-1;
    int m=n%6;
    int mod=1e9+7; // 10^9+7
    switch(m)
    {
        case 0: return (A+B+mod)%mod;
        case 1: return (B+C+mod)%mod;
        case 2: return (C-A+mod)%mod;
        case 3: return (-A-B+mod)%mod;
        case 4: return (-B-C+mod)%mod;
        default: return (A-C+mod)%mod;
    }
}


int main()
{
    int n,A,B,C;
    cout <<"Nhap n:"; cin >>n;
    cout <<"Nhap A:"; cin >>A;
    cout <<"Nhap B:"; cin >>B;
    cout <<"Nhap C:"; cin >>C;
    cout <<modifiedFib2(n,A,B,C);
}


