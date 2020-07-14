#include <bits/stdc++.h>
using namespace std;

/*
#Primality testing:
    1)
        for(int i = 1; i<=n ; i++)
    2)
        for(int i = 2; i<n ; i++)
        {
            if(n%1 ==0) -->n is composite
        }
        -->otherwise n is prime

    16 = [1],2,4,8,[16]
    12 = 1,[2],3,4,[6],12
    30 = 1,2,3,[5],[6],10,15,30
    
    N = a * b
 => N = a * a [best case,farthest divisor of N]
 => N = a^2
Hence, a = sqrt(N)
*/
bool isPrime(int N) // TC: O(N) LINEAR TIME
{
    if(N<2) return 0;
    //int SR = sqrt(N)
    //   i <= sqrt (N)
    // i*i <= N
    for(int i =2; i*i <= N ; i++)
    {
        if(N % i == 0) return 0;
    }
    return 1;
}
/*
    use case:
    1)1000 number Primality testing
    2)scattered distribution Primality testing: 3,30,456
*/
int count_divisor(int N)
{
    //not effcient
    int cnt = 0;
    for(int first_factor =1; first_factor*first_factor <= N ; first_factor++)
    {
        if(N % first_factor == 0)
        {
            cnt++;
            int second_factor = N/first_factor;
            if(second_factor !=first_factor) cnt++;
        }
    }
    return cnt;
}
/*

efficently divisor count:
https://www.wolframalpha.com/input/?i=prime+factorization+of+12

prime factorization
12 = 2^[2] * 3^[1]
power -> 2 , 1
(2  add 1) * (1  add 1)-> 3*2 -> 6 -> 6 divisor

more efficent:
backtrack: https://ideone.com/JNRMsQ

*/
int main()
{   int mx = 0;
    int num = 0;
    for(int i =1; i<=1000000; i++)
    {
        //if(isPrime(i)) cout << i << endl;
        //cout<<i<<":"<<count_divisor(i)<<endl;
        //mx = max(mx,count_divisor(i));//for 1000000 -> 240
        int cnt = count_divisor(i);
        if(mx<cnt)
        {
            mx = cnt;
            num = i;
        }
    }
    cout<<mx<<" "<<num<<endl; // 240 720720
    return 0;
}