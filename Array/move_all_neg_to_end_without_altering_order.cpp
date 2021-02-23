#include <bits/stdc++.h>
using namespace std;

void move(int arr[], int n)
{
    int j = 0;
    int arr2[n];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            arr2[j] = arr[i];
            j++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            arr2[j] = arr[i];
            j++;
        }
    }
    for (int i = 0; i < n; i++)
        cout << arr2[i] << " ";
}

int main()
{
    int n = 8;
    int arr[n] = {-5, 7, -3, -4, 9, 10, -1, 11};
    move(arr, n); // TC: O(N), SC: O(N)
    cout << endl;
}
