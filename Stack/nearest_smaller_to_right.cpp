/*
NSR = next smaller to right
stack -> right array
Element        Output:NSR
4                   2
5                   2
2                   -1
10                  8
8                   -1
*/
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

void using_stack(vector<int>element, int n)
{
    vector<int> NSR ;
    stack <int> stk;
    for(int i=n-1; i>=0 ; i--)
    {
        if(stk.empty())
        {
            NSR.push_back(-1);
        }
        else if(!stk.empty() && stk.top() < element[i])
        {
            NSR.push_back(stk.top());
        }
        else if(!stk.empty() && stk.top() >= element[i])
        {
            while(!stk.empty() && stk.top() >= element[i])
            {
                stk.pop();
            }
            if(stk.empty())
                NSR.push_back(-1);
            else
                NSR.push_back(stk.top());
        }
        stk.push(element[i]);
    }
    cout<<"Element: ";
    for(int value : element)
        cout<<value<<" ";
    cout<<"\nNSR:\t ";
    reverse(NSR.begin(),NSR.end());
    for(int value : NSR)
        cout<<value<<" ";
}
void brute_force(vector<int>element, int n)
{
    int ans;
    for(int i=0; i<n; i++)
    {
        ans = -1;
        for(int j = i+1; j<n; j++)
        {
            if(element[i]>element[j])
            {
                ans = element[j];
                break;
            }
        }
        cout<< element[i] << "  " << ans <<endl;
    }
}
int main()
{
    vector<int>element{4,5,2,10,8};
    int n = element.size();

    brute_force(element,n); //O(n^2)

    cout<<endl;

    using_stack(element,n); //O(n)

    return  0;
}
