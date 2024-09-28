#include <iostream>
using namespace std;

// 1. GCD (Greatest Common Divisor)
// Tìm GCD của 2 số nguyên dương a, b
// Link exercise: https://www.geeksforgeeks.org/problems/gcd-of-two-numbers3459/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
// Link answer: https://www.geeksforgeeks.org/program-to-find-gcd-or-hcf-of-two-numbers/


// Cách 1: Naive Approach dùng vòng lặp for
// 1063/1115: Vượt quá thời gian 1s
int gcd1(int a, int b)
{
    int answer;
    int value=min(a,b);

    for (int i=1;i<=value;i++)
    {
        if (a%i==0 && b%i==0)
        {
            answer=i;
        }
    }
    return answer;
}

// Cách 2: Cải tiến cách 1
// 1063/1115: Vượt quá thời gian 1s
// Nói là cải tiến nhưng cũng y chang =)))
int gcd2(int a, int b)
{
    int answer;
    int value=min(a,b);

    for (int i=value;i>=1;i--)
    {
        if (a%i==0 && b%i==0)
        {
            answer=i;
            break;
        }
    }
    return answer;
}

// Cách 3: Euclidean algorithm by subtraction
// 1036/1115: Segmentation Fault (SIGSEGV)
int gcd3(int a, int b)
{
    if (a==0) return b;
    if (b==0) return a;

    if (a==b) return a;
    else if (a>b) return gcd3(a-b,b);
    else return gcd3(a,b-a);
}

// Cách 4: Euclidean Optimization by checking divisibility
// 1036/1115: Segmentation Fault (SIGSEGV)
// Lỗi y chang cách 3
int gcd4(int a, int b)
{
    if (a==0) return b;
    if (b==0) return a;

    if (a==b) return a;
    else if (a>b)
    {
        if (a%b==0) return gcd4(a%b,b);
        return gcd4(a-b,b);
    }
    else
    {
        if (b%a==0) return gcd4(a,b%a);
        return gcd4(a,b-a);
    }
}

// Cách 5: Euclidean Optimization using division
// 1115/1115
// Hoàn thành
int gcd5(int a, int b)
{
    if (a==0) return b;
    return gcd5(b%a,a);
}

int main()
{
    long long a,b;
    cout <<"Nhap a:"; cin >>a;
    cout <<"Nhap b:"; cin >>b;
    cout <<gcd5(a,b);
}
