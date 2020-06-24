/*
LeetCode
155. Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/
#include<iostream>
#include<stack>
using namespace std;

stack <int> major_stack;
stack <int> min_stack;

int top()
{
    return major_stack.top();
}

int get_min()
{
    return min_stack.top();
}

void push(int x)
{
    major_stack.push(x);
    if(min_stack.empty() || x<= get_min())
        min_stack.push(x);
    else
        min_stack.push(get_min());
}

void pop()
{
    if(!major_stack.empty())
    {
        major_stack.pop();
        min_stack.pop();
    }
}

int main()
{
    //input
    push(8);
    push(5);
    push(3);
    push(20);
    push(9);    //major_stack 8 5 3 20 9 ; min_stack : 8 5 3 3 3
    cout<<get_min()<<endl;  //3
    pop();  //major_stack 8 5 3 20  ; min_stack : 8 5 3 3
    pop();  //major_stack 8 5 3  ; min_stack : 8 5 3
    pop();  //major_stack 8 5   ; min_stack : 8 5
    cout<<get_min()<<endl; // 5

    return 0;
}
/*
Output:
3 5
*/
