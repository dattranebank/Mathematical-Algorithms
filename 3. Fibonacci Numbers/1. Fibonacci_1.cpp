#include <iostream>
#include <vector>
using namespace std;

// 1. First n Fibonacci (In ra n số Fibonacci đầu tiên)
// Link exercise: https://www.geeksforgeeks.org/problems/print-first-n-fibonacci-numbers1002/1
// Link answer:

// Cách 1: Tự code
// 100/100
// Hoàn thành
vector<long long> printFibb(int n)
{
    vector <long long> vec;
    long long F0=1;
    long long F1=1;
    long long Fn=0;
    if (n==1) vec.push_back(1);
    if (n>=2)
    {
        vec.push_back(1);
        vec.push_back(1);
    }

    for (int i=2;i<n;i++)
    {
        Fn=F0+F1;
        F0=F1;
        F1=Fn;
        vec.push_back(Fn);
    }
    return vec;
}


int main()
{
    int n;
    cout <<"Nhap n:"; cin >>n;
    vector <long long> vec;
    vec=printFibb(n);
    for (int i=0;i<vec.size();i++)
    {
        cout <<vec[i]<<" ";
    }
}
