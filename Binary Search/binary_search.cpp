/*
O(logN)
N/2^0
N/2^1
N/2^4...
N/2^k = 1
N = 2^k
log(N) = log2base(2^k)
log(N) = k log2base(2)
log(N) = k
*/
#include<iostream>
#include<vector>
using namespace std;
binary_search_func(vector<int>num, int value)
{
    int start_num = 0, end_num = num.size()-1;
    int mid;    // to avoid int overflow ,not using (start_num+end_num) / 2
    while(start_num <= end_num)
    {
        mid = start_num +(end_num-start_num)/2;
        if(value == num[mid])
        {
            return mid;
        }
        else if(value > num[mid])
        {
            start_num = mid+1;
        }
        else
        {
            end_num = mid-1;
        }
    }
    return -1;
}
int main()
{
    vector<int>sorted_num{12,14,16,18,20,22,24,26};
    int search_num = 18;
    int result = binary_search_func(sorted_num, search_num);
    cout << result << endl;  //3
}
