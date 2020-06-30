/*
sorted in ascending order
*/
#include<iostream>
#include<vector>
using namespace std;
last_occurrence_using_BS(vector<int>num, int value)
{
    int start_num = 0, end_num = num.size()-1;
    int mid;    // to avoid int overflow ,not using (start_num+end_num) / 2
    int res=-1;
    while(start_num <= end_num)
    {
        mid = start_num +(end_num-start_num)/2;
        if(value == num[mid])
        {
            res = mid;
            start_num = mid+1;
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
    return res;
}
int main()
{
    vector<int>sorted_num{12,14,20,20,20,20,24,26};
    int search_num = 20;
    int result = last_occurrence_using_BS(sorted_num, search_num);
    cout << result << endl;  //5
}
