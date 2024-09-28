#include <iostream>
using namespace std;

// 2. LCM (Least Common Multiple)
// Tìm LCM của 2 số nguyên dương a, b


int gcd(int a, int b)
{
    if(a==0) return b;
    return gcd(b%a,a);
}

int lcm(int a, int b)
{
    return a/gcd(a,b)*b;
}

int main()
{
    long long a,b;
    cout <<"Nhap a:"; cin >>a;
    cout <<"Nhap b:"; cin >>b;
    cout <<"Output:"<<lcm(a,b);
}

