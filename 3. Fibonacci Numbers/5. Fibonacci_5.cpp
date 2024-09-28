#include <iostream>
#include <string> // for string and to_string()
using namespace std;

// 5. Fibonacci Sum
// Link exercise: https://www.geeksforgeeks.org/problems/fibonacci-sum1423/1
// Link answer:


// Cách 1: Tự làm
// 1115/1115
// Hoàn thành
long long int fibSum1(int n)
{
    long long int F0=1;
    long long int F1=1;
    long long int Fn=0;
    long long int sum=2;
    int mod=1e9+7; // 10^9+7
    if (n==0) return 0;
    if (n==1) return 2;

    for (int i=2;i<n;i++)
    {
        Fn=(F0+F1)%mod;
        F0=F1;
        F1=Fn;
        sum=sum+Fn;
    }
    return sum%mod;
}


int main()
{
    long long int n;
    cout <<"Nhap n:"; cin >>n;
    cout <<fibSum1(n);
}



