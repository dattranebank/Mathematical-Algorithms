#include <iostream>
#include <vector>
using namespace std;

// 2. Fibonacci to N (In ra dãy Fibonacci cho đến khi giá trị N)
// Link exercise: https://www.geeksforgeeks.org/problems/fibonacci-to-n0811/1
// Link answer:

// Cách 1: Tự code
// 68477/68477
// Hoàn thành
vector<int> nFibonacci(int n)
{
    vector <int> vec;
    int F0=1;
    int F1=1;
    int Fn=0;
    if (n>=1)
    {
        vec.push_back(0);
        vec.push_back(1);
        vec.push_back(1);
    }

    for (int i=1;i<n;i++)
    {
        Fn=F0+F1;
        F0=F1;
        F1=Fn;
        if (n>=Fn) vec.push_back(Fn);
        else break;
    }
    return vec;
}


int main()
{
    int n;
    cout <<"Nhap n:"; cin >>n;
    vector <int> vec;
    vec=nFibonacci(n);
    for (int i=0;i<vec.size();i++)
    {
        cout <<vec[i]<<" ";
    }

}

