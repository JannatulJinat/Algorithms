/**
gcd : greatest common divisor/factor
(10, 15) -->1, [5]
(12, 16) --> 1, 2, [4]
Euclidean method: gcd finding algo: efficent

10 |  15 | 1
      10
      --------
[gcd]  5| 10 |2
          10
       --------
           0 | 5 [return this]|

assume a < b,
gcd(a, b) = gcd(a, b-a)=gcd(a, b-a-a)
   a |  b |k1
        k2
       --------
   b%a| a

**/

/**
15 % 8 = 7
 7 % 4 = 3
 3 % 2 = 1
 1% 1 = 0
**/
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) ///O(logN) ;N =max(a,b)
{
    ///b%a == 0 (terminate korbe)
    ///b%a next -> a
    while(a!=0)
    {
        int new_a = b%a;
        int new_b = a;
        a = new_a;
        b = new_b;

    }
    return b;
}
int main()
{
    cout<<gcd(10, 15)<<endl; ///5
    ///built in
    cout<< __gcd(10,15)<<endl;
}
