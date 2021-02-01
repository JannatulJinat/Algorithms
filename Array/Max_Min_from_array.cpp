#include <iostream>
using namespace std;
void naiveApproach(int arr[], int size)
{
    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (max < arr[i])
            max = arr[i];
        else if (min > arr[i])
            min = arr[i];
    }
    cout << max << " " << min << endl;
}
void optimizedApproach(int arr[], int size)
{
    int max, min, index;
    if (size % 2 == 0)
    {
        if (arr[0] > arr[1])
        {
            max = arr[0];
            min = arr[1];
        }
        else
        {
            max = arr[1];
            min = arr[0];
        }
        index = 2;
    }
    else
    {
        max = arr[0];
        min = arr[0];
        index = 1;
    }
    for (int i = index; i < size; i = i + 2)
    {
        if (arr[i] > arr[i + 1])
        {
            if (arr[i] > max)
                max = arr[i];
            if (arr[i + 1] < min)
                min = arr[i + 1];
        }
        else
        {
            if (arr[i + 1] > max)
                max = arr[i + 1];
            if (arr[i] < min)
                min = arr[i];
        }
    }
    cout << max << " " << min << endl;
}
int main()
{

    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        int size = 0;
        cin >> size;
        int arr[size];
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        //naiveApproach(arr, size);   //worst case 5 4 3 2 1:  2(n-1) comparision
        optimizedApproach(arr, size); //3(n-1)/2 comparison
    }
    return 0;
}
