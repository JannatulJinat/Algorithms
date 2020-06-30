/*
-rotate toward right
-no duplicate element
variation - [finding smallest value in rotated sorted array]
sorted:  2 5 6 8 11 12 15 18
rotate: 18 2 5 6  8 11 12 15
rotate: 15 18 2 5 6  8 11 12
rotate: 12 15 18 2 5 6  8 11
rotate: 11 12 15 18 2 5 6  8  <- this will be given
we have to find out how many times main stream was rotated.
output- 4
min element of the sorted array -> 0 index -> indicates rotation 0

min element given array -> 4 index -> indicates rotation 4

here min element 2 < the left value 18
min element 2 also < the right value 5

to understand modulo parts
case 1:
if mid = 0 or the first index
for instance num = [1, 2]
prev = mid - 1 = -1 which thrown an error because num[-1] is out of range
prev = (mid - 1 + n) % n = 1, it prevent an error from negative index

case 2:
if mid = n - 1 or the last index
such as num = [2, 3, 1] , assuming that mid = 2
next = mid + 1 = 3, which num[3] is out of range
next = (mid + 1) % n = 0, loop index is initialized to the first index,  like a circular array
*/
#include<iostream>
#include<vector>
using namespace std;
rotation_count(vector<int>num)
{
    int n = num.size();
    int start_num = 0, end_num = num.size()-1;
    int mid, previous, next;    // to avoid int overflow ,not using (start_num+end_num) / 2
    while(start_num <= end_num)
    {
        if(num[start_num] <= num[end_num])    //when the array is not rotated at all / there is only one element
            return start_num;

        mid = start_num + (end_num-start_num) / 2;
        previous = (mid+n-1) % n;
        next =( mid+1) %n;

        if(num[mid] < num[previous] && num[mid] < num[next])    //case {16,18,2,5,6}
            return mid;

        else if(num[mid] <= num[end_num])
        {
            end_num = mid - 1;
        //case {18,16,1,2,5,6}If middle element is smaller than last element,then the minimum element lies in left half
        }
        else if(num[mid]>=num[start_num])
        {
            start_num = mid + 1;
        }
    }
    return -1;
}
int main()
{
    vector<int>sorted_num{11, 12, 15, 18, 2, 5, 6, 8}; //2,2 will not give the correct ans
    int min_index = rotation_count(sorted_num);
    cout << "number of rotation "<<min_index  << endl;
}
