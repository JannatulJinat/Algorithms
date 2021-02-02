// Sort Color 
#include <bits/stdc++.h>
#define testcase int t; cin >> t; while (t--)
using namespace std;

void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void countingSort012(int a[], int size)
{
    //requires two traversals of array
    int count0 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] == 0)
            count0++;
        else if (a[i] == 1)
            count1++;
        else if (a[i] == 2)
            count2++;
    }
    int k = 0;
    for (int i = 0; i < count0; i++)
        a[k++] = 0;
    for (int i = 0; i < count1; i++)
        a[k++] = 1;
    for (int i = 0; i < count2; i++)
        a[k++] = 2;
}
void dnfaApproachSort012(int a[], int size)
{
    //Dutch National Flag Algorithm -DNFA
    // l = before l -> 0
    // h = after h -> 2
    int l = 0, m = 0, h = size - 1;
    while (m <= h)
    {
        if (a[m] == 0)
        {
            swap(a[m], a[l]);
            m++;
            l++;
        }
        else if (a[m] == 1)
        {
            m++;
        }
        else if (a[m] == 2)
        {
            swap(a[m], a[h]);
            h--;
        }
    }
}

int main()
{
    testcase
    {
        int size;
        cin >> size;
        int a[size];
        for (int i = 0; i < size; i++)
        {
            cin >> a[i];
        }
        cout << "Couting Sort Approach:";
        countingSort012(a, size);
        printArray(a, size);

        cout << "Dutch National Flag Algorithm :";
        dnfaApproachSort012(a, size);
        printArray(a, size);
    }
    return 0;
}

/*
1
5
0 1 2 1 1

output: 0 1 1 1 2


*/
