#include <bits/stdc++.h>
#define testcase int t; cin >> t; while (t--)

using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void reverseArrayIterator(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void reverseArrayRecursion(int arr[], int start, int end)
{
    if (start >= end)
        return;
    else
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
        reverseArrayRecursion(arr, start, end);
    }
}

int main()
{
    testcase
    {
        int size;
        cin >> size;
        int arr[size], start = 0, end = size - 1, temp = 0;
        for (int i = 0; i < size; i++)
            cin >> arr[i];

        reverseArrayIterator(arr, start, end);
        //reverseArrayRecursion(arr, start, end);
        printArray(arr, size);
    }
    return 0;
}
