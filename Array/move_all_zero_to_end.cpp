#include <bits/stdc++.h>
using namespace std;
void twoPointerMethod(int arr[], int n)
{
    if (n == 0 || n == 1)
        return;
    int left = 0, right = 0;
    while (right < n)
    {
        if (arr[right] != 0)
        {
            swap(arr[left], arr[right]);
            ++right;
            ++left;
        }
        else
        {
            ++right;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
}
void naiveApproach(int arr[], int n)
{
    int j = 0;

    int arr2[n] = {0};
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            arr2[j] = arr[i];
            j++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr2[i] << ' ';
    }
}

int main()
{
    int n = 5;
    int arr[n] = {0, 6, 0, 2, 1};
    naiveApproach(arr, n); // TC: O(N), SC: O(N)
    cout << endl;
    twoPointerMethod(arr, n); //TC: O(N), SC:O(1)
}
