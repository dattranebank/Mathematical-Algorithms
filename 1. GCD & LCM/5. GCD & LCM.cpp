// 5. GCD & LCM
// Tìm GCD & LCM của 2 số nguyên dương
// Link exercise: https://www.geeksforgeeks.org/problems/lcm-and-gcd4516/1
// Link answer:


vector<long long> lcmAndGcd(long long A , long long B)
{
    vector <long long> vec;
    vec.push_back(lcm(A,B));
    vec.push_back(gcd(A,B));
    return vec;
}

long long gcd(long long A , long long B)
{
    if(A==0) return B;
    return gcd(B%A,A);
}

long long lcm(long long A , long long B)
{
    return A/gcd(A,B)*B;
}
