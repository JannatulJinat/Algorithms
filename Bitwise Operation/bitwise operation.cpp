/*****
-5    = 10000000 00000000 00000000 00000101

left shift    <<
5    = 00000000 00000000 00000000 00000101
5(1) = 00000000 00000000 00000000 00001010 = 10
5(2) = 00000000 00000000 00000000 00010100 = 20
5(3) = 00000000 00000000 00000000 00101000 = 40
5(3) = 00000000 00000000 00000000 01010000 = 80
value -> double


right shift   >>
12    = 00000000 00000000 00000000 00001100
12(1) = 00000000 00000000 00000000 00000110 = 6
12(2) = 00000000 00000000 00000000 00000011 = 3
12(3) = 00000000 00000000 00000000 00000001 = 1
12(3) = 00000000 00000000 00000000 00000000 = 0
value -> half -> floor

AND :
5  = 0101
12 = 1100
-------------
4  = 0100

OR :
5  = 0101
12 = 1100
-------------
13  = 1101

X-OR : same value - 0 , different value - 1
5  = 0101
12 = 1100
-------------
9  = 1001

1)check if an integer is a power of 2
1 2 4 8 16 32 64 128 256 512...

512 = 1000000000
511 = 0111111111
----------------
and = 0000000000[bitmask]

2)count the number of SET bits :
use " __builtin_popcount " function

3)Leetcode :https://leetcode.com/problems/single-number
Single Number:
Given a non-empty array of integers,
every element appears twice except for one. Find that single one.
2^4^2 = 4
4^2^2 = 4
2^2^4 = 4
xor commutative property
int single = 0 ;
for(int num : nums)
{
  single  = single ^ num;
}
return single ;

*****/

#include <iostream>

using namespace std;
bool is_power_of_two(int n)
{
    int bitmask = n & (n-1);
    return bitmask == 0; 
}
int main()
{
    int a = 5, b = 12 ,ans;
    int x = 3;
    
    ans = a << x ; //left shift
    cout<<ans<<endl;
   
    ans = b >> x ; //right shift
    cout<<ans<<endl;
    
    ans = a & b;  //and
    cout<<ans<<endl;
    
    ans = a | b;  //or
    cout<<ans<<endl;

    ans = a ^ b;  //xor
    cout<<ans<<endl;
    
    //1
    cout<<"Integer is a power of 2:"<<endl;
    for(int i = 1; i<1000000; i++)
    {
        if(is_power_of_two(i))cout<<i<<endl;
    }
    
    //2
    cout<<__builtin_popcount(5)<<endl; 

  
	
    return 0;
}
