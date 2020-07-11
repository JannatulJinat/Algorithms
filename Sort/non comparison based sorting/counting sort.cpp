/*
Counting sort
Linear-time sorting

runtime depends on (Max_value - Min_value) of the input.
declared as linear time.

work best when the difference between max and min is less.

to handle neg value, adding offset which is the abs value of the min_value
then finding the frequency, after that reducing the offset.

string freq in a word can be easily found by using counting sort.

Drawback:
1) massive memory loss
2) if there exist any element beyond the max size of array,
error occurs.
*/
#include <bits/stdc++.h>
using namespace std;
void only_positive_elements_counting_sort(int *arr,int N);//can't handle neg value
void optimzed_counting_sort(int *arr,int N); //can handle neg value

int main()
{
    int arr[] = {48,45,42,46,46};
    int N = sizeof(arr)/sizeof(arr[0]);
    only_positive_elements_counting_sort(arr,N);


    int arr2[] = {-5,8,15,2};
    int N2 = sizeof(arr)/sizeof(arr[0]);
    optimzed_counting_sort(arr2,N2);

    return 0;
}
void only_positive_elements_counting_sort(int *arr, int N)
{
    int min_value = *min_element(arr,arr+N);
    int max_value = *max_element(arr,arr+N);
    vector <int> freq(max_value+1,0);//filled with 0
    for(int i = 0; i<N; i++)
        ++freq[arr[i]];

    int index = 0;
    for(int i = min_value; i<=max_value; i++)
    {
        while(freq[i]>0)
        {
            arr[index]= i;
            --freq[i];
            ++index;
        }
    }
    cout<<"only positive elements :counting sort"<<endl;
    for(int i = 0; i<N; i++)
        cout<<arr[i]<<" ";
}
void optimzed_counting_sort(int *arr,int N)
{
    int min_value = *min_element(arr,arr+N);
    int max_value = *max_element(arr,arr+N);
    vector <int> freq(max_value + abs(min_value) + 1, 0);//filled with 0

    int OFFSET = 0;

    if (min_value< 0) OFFSET = abs(min_value);

    for(int i = 0; i<N; i++)
        ++freq[arr[i] + OFFSET];

    int index = 0;
    for(int i = min_value + OFFSET; i<=max_value + OFFSET; i++)
    {
        while(freq[i]>0)
        {
            arr[index]= i-OFFSET;
            --freq[i];
            ++index;
        }
    }
    cout<<"\n\ncan handle neg value :counting sort"<<endl;
    for(int i = 0; i<N; i++)
        cout<<arr[i]<<" ";
}
