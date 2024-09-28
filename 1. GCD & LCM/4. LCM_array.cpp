#include <iostream>
using namespace std;

// 4. LCM (Least Common Multiple)
// Tìm LCM của n số nguyên dương
// Link exercise: https://www.geeksforgeeks.org/problems/lcm-of-given-array-elements3919/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
// Link answer: https://www.geeksforgeeks.org/lcm-of-given-array-elements/


// Cách 1: Copy code cách giải của GCD rồi đưa qua
// 2/1115
int gcd1(int a, int b)
{
    if(a==0) return b;
    return gcd1(b%a,a);
}

int lcmOfArray1(int A[], int N)
{
    int ans;
    for (int i=1;i<N;i++)
    {
        ans=(A[i]*ans)/gcd1(A[i],ans)%1000000007;
    }
    return ans%1000000007;
}

// Cách 2: Tham khảo code trên GFG
long long gcd2(int a,int b)
{
    if(a==0) return b;
    return gcd2(b%a,a);
}

long long lcm2(int a,int b)
{
    return a/gcd2(a,b)*b;
}

long long lcmOfArray2(int A[],int N)
{
    int ans=A[0];
    int mod=1e9+7;
    for(int i=1;i<N;++i)
    {
        ans=lcm2(ans,A[i])%mod;
    }
    return ans%mod;
}


int main()
{
    int N;
    cout <<"Nhap n:"; cin >>N;
    int A[N];
    for (int i=0;i<N;i++)
    {
        cout <<"A["<<i<<"]:"; cin >>A[i];
    }
    cout <<"Output:"<<lcmOfArray2(A,N);
}


