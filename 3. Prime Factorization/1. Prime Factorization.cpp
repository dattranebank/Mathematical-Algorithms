#include <iostream>
#include <math.h>
using namespace std;

// 3. Prime Factorization (Thừa số nguyên tố)
// Link exercise: https://www.geeksforgeeks.org/problems/largest-prime-factor2601/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
// Link answer: https://www.geeksforgeeks.org/find-largest-prime-factor-number/

// Cách 1: Tự code
// 230/1257
// Lỗi: Vượt quá thời gian
long long int largestPrimeFactor1(int n)
{
    int largest=2;
    // Chia n cho 2 trước vì 2 là số nguyên tố chẵn duy nhất
    while (n%2==0)
    {
        largest=2;
        n=n/2;
    }

    // Toàn bộ số nguyên tố phía sau là số lẻ như 3 5 7
    for (int i=3;i<=n;i=i+2)
    {
        bool chk=true; // Biến kiểm tra i có phải là prime number hay không
        for (int j=2;j<sqrt(i);j++)
        {
            if (i%j==0) chk=false;

        }

        if (n%i==0 && chk==true)
        {
            largest=i;
            n=n/i;
        }

    }
    return largest;
}

// Cách 2: Cải tiến từ cách 1
// 937/1257, có cải thiện so với cách 1
// Lỗi: Vượt quá thời gian
long long int largestPrimeFactor2(int n)
{
    // Kiểm tra n có phải là số nguyên tố không
    bool chk=true;
    for (int i=2;i<=sqrt(n);i++)
    {
        if (n%i==0) chk=false;
    }
    if (chk==true) return n;


    int largest=1;
    // Chia n cho 2 trước vì 2 là số nguyên tố chẵn duy nhất
    while (n%2==0)
    {
        largest=2;
        n=n/2;
    }

    // Toàn bộ số nguyên tố phía sau là số lẻ như 3 5 7
    for (int i=3;i<=n;i=i+2)
    {
        bool chk=true; // Biến kiểm tra i có phải là prime number hay không
        for (int j=2;j<=sqrt(i);j++)
        {
            if (i%j==0) chk=false;
        }

        while (n%i==0 && chk==true)
        {
            largest=i;
            n=n/i;
        }
    }
    return largest;
}

// Cách 3: Cải tiến từ cách 2
// 1018/1257, có cải thiện so với cách 2
// Lỗi: Vượt quá thời gian
long long int largestPrimeFactor3(int n)
{
    // Kiểm tra n có phải là số nguyên tố không
    bool chk=true;
    if (n%2==0) chk=false;
    for (int i=3;i<=sqrt(n);i=i+2)
    {
        if (n%i==0) chk=false;
    }
    if (chk==true) return n;

    int largest=1;
    // Chia n cho 2 trước vì 2 là số nguyên tố chẵn duy nhất
    while (n%2==0)
    {
        largest=2;
        n=n/2;
    }

    // Toàn bộ số nguyên tố phía sau là số lẻ như 3 5 7
    for (int i=3;i<=n;i=i+2)
    {
        bool chk=true; // Biến kiểm tra i có phải là prime number hay không
        for (int j=3;j<=sqrt(i);j=j+2)
        {
            if (i%j==0) chk=false;
        }

        while (n%i==0 && chk==true)
        {
            largest=i;
            n=n/i;
        }
    }
    return largest;
}

// Cách 4: Coi đáp án
// 1257/1257
long long int largestPrimeFactor4(int n)
{
    int largest_prime=-1;
    for (int i=2; i*i<=n;i++)
    {
        while (n%i==0)
        {
            largest_prime=i;
            n=n/i;
        }
    }
    if (n>1) largest_prime=n;
    return largest_prime;
}

// Cách 5: Chỉnh sửa một chút từ cách 4
// 1257/1257
// Kết luận: Việc kiểm tra i là số nguyên tố hay không là thừa thãi
// bởi vì nó đã được xử lý bởi những con số 2, 3, 5 trước đó rồi, ví dụ i=9 thì không thể xảy ra
// trường hợp while (n%9==0) được vì trước đó đã xảy ra n%3 nhiều lần
long long int largestPrimeFactor4(int n)
{
    int largest_prime=-1;
    for (int i=2; i<=sqrt(n);i++)
    {
        while (n%i==0)
        {
            largest_prime=i;
            n=n/i;
        }
    }
    if (n>1) largest_prime=n;
    return largest_prime;
}

int main()
{
    int n;
    cout <<"Nhap n:"; cin >>n;
    cout <<largestPrimeFactor4(n);
}
