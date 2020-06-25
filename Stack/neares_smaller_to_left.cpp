/*
NSE = next smaller to left (NEAREST SMALLER ELEMENT)
stack -> left array
Element        Output:NSE
4                   -1
5                   4
2                   -1
10                  2
8                   2
*/
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

void using_stack(vector<int>element, int n)
{
    vector<int> NSE ;
    stack <int> stk;
    for(int i=0; i<n ; i++)
    {
        if(stk.empty())
        {
            NSE.push_back(-1);
        }
        else if(!stk.empty() && stk.top() < element[i])
        {
            NSE.push_back(stk.top());
        }
        else if(!stk.empty() && stk.top() >= element[i])
        {
            while(!stk.empty() && stk.top() >= element[i])
            {
                stk.pop();
            }
            if(stk.empty())
                NSE.push_back(-1);
            else
                NSE.push_back(stk.top());
        }
        stk.push(element[i]);
    }
    cout<<"Element: ";
    for(int value : element)
        cout<<value<<" ";
    cout<<"\nNSE:\t ";

    for(int value : NSE)
        cout<<value<<" ";
}
void brute_force(vector<int>element, int n)
{
    int ans;
    for(int i=0; i<n; i++)
    {
        ans = -1;
        for(int j = i-1; j>=0; j--)
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
