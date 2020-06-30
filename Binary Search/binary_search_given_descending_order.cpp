/*
sorted in descending order
O(logN)
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
        else if(value < num[mid])
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
    vector<int>sorted_num{95,85,75,65,55,45,35,25,15,5};
    int search_num = 5;
    int result = binary_search_func(sorted_num, search_num);
    cout << result << endl;  //9
}
