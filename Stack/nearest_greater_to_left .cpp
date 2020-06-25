/*
NGL = next greater to left
stack -> left array
Element        Output:NGE
1                   -1
3                   -1
2                   3
4                  -1
*/
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

void using_stack(vector<int>element, int n)
{
    vector<int> NGL ;
    stack <int> stk;
    for(int i=0; i<n ; i++)
    {
        if(stk.empty())
        {
            NGL.push_back(-1);
        }
        else if(!stk.empty() && stk.top()> element[i])
        {
            NGL.push_back(stk.top());
        }
        else if(!stk.empty() && stk.top() <= element[i])
        {
            while(!stk.empty() && stk.top() <= element[i])
            {
                stk.pop();
            }
            if(stk.empty())
                NGL.push_back(-1);
            else
                NGL.push_back(stk.top());
        }
        stk.push(element[i]);
    }
    cout<<"Element: ";
    for(int value : element)
        cout<<value<<" ";
    cout<<"\nNGE:\t ";

    for(int value : NGL)
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
            if(element[i]<element[j])
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
    vector<int>element{1,3,2,4};
    int n = element.size();

    brute_force(element,n); //O(n^2)

    cout<<endl;

    using_stack(element,n); //O(n)

    return  0;
}
