#include <iostream>
using namespace std;

// 1. GCD_array (Greatest Common Divisor)
// Tìm GCD của n số nguyên dương


// Cách 1: Euclidean Optimization using division
// Chưa biết đúng hay sai
int gcd(int a, int b)
{
    if (a==0) return b;
    return gcd(b%a,a);
}

int gcd_array(int A[], int n)
{
    int answer=0;

    for (int i=0;i<n-1;i++)
    {
        answer=gcd(A[i],A[i+1]);
    }
    return answer;
}

int main()
{
    int n;
    cout <<"Nhap n:"; cin >>n;

    int A[n];
    for (int i=0;i<n;i++)
    {
        cout <<"A["<<i<<"]:"; cin >>A[i];
    }
    cout <<"Output:"<<gcd_array(A,n);
}

