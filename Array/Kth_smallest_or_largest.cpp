#include <bits/stdc++.h>
using namespace std;
int kthSmallest(int arr[], int l, int n, int k)
{
    priority_queue<int> maxHeap;
    for (int i = 0; i < n; i++)
    {
        maxHeap.push(arr[i]);
        if (maxHeap.size() > k)
        {
            maxHeap.pop();
        }
    }
    return maxHeap.top();
}
int kthLargest(int arr[], int l, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; i++)
    {
        minHeap.push(arr[i]);
        if (minHeap.size() > k)
        {
            minHeap.pop();
        }
    }
    return minHeap.top();
}

int main()
{

    int test_case;
    cin >> test_case;
    while (test_case--)

    {
        int number_of_elements;
        cin >> number_of_elements;
        int a[number_of_elements];

        for (int i = 0; i < number_of_elements; i++)
            cin >> a[i];

        int k;
        cin >> k;
        cout << kthSmallest(a, 0, number_of_elements, k) << endl;
        cout << kthLargest(a, 0, number_of_elements, k) << endl;
    }
    return 0;
}
