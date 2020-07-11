/*
Insertion Sort -> similar to how most people arrange a hand of poker
Outer loop executes N-1 times.O(N-1)= O(N)
But the inner loop depends on the input.
Best case : the array is already sorted and arr[j] > X is always false.
no shifting will occur.inner loop runs O(1).
Worst case : the array is reversely sorted and arr[j]>X is always true.
Insertion will occur all the time.so the inner loop executes O(N)

Insertion sorting algorithm:
best case : O(N*1) = O(N)
worst case : O(N*N) = O(N^2)
memory complexity,X = O(1)

when to use :
1.to identify is the data sorted or not
2.less amount of data which need to be sorted
quick sort /merge sort doesn't work well on this case
because there occurs some extra execution with nlogn .
n^2 works better on that case.
assume,
n = 10 -> n^2 = 10^2 = 100
mlogn = 10log10 = ~33 but with some extra execution it becomes = 33*4(assume) = 132
*/
#include <iostream>
using namespace std;
void insertion_sort(int *arr,int N);
int main()
{
    //worst case ; {10,9,8,7,6,5,4,3,2,1};
    //best case : {1,2,3,4,5,6,7,8,9,10};
    int arr[] = {15,19,20,45,0,12,16};
    int N = sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr,N);
    for(int x : arr)
        cout<<x<<" ";
    return 0;
}

void insertion_sort(int *arr,int N)
{
    for (int i = 1; i<N; ++i) //O(N-1)= O(N)
    {
        int X = arr[i]; //the item which needs to be inserted
        for(int j = i-1; j>=0 && arr[j] > X   ; --j)
        {
            arr[j+1] = arr[j];
            arr[j] = X;
        }
    }
}
