#include<iostream>
#include<stack>
using namespace std;

int min_value ;
stack <int> major_stack;

int top()
{
    if(major_stack.empty())
        return -1;
    else
    {
        if(major_stack.top()>=min_value)
            return major_stack.top();
        else
        {
            return min_value;
        }
    }
}

int get_min()
{
    if(major_stack.empty())
        return -1;
    else
        return min_value;
}

void push(int x)
{
    if(major_stack.empty())
    {
        major_stack.push(x);
        min_value = x;
    }
    else
    {
        if(x>= min_value)
        {
            major_stack.push(x);
        }
        else
        {
            major_stack.push( 2*x - min_value);
            min_value = x;
        }
    }
}

void pop()
{
    if(major_stack.empty())
        return;
    else
    {
        if(major_stack.top() >= min_value)
            major_stack.pop();
        else
        {
            min_value = 2*min_value - major_stack.top(); // flag
            major_stack.pop();
        }
    }
}

int main()
{
    //input
    cout<<get_min()<<endl;  //-1
    push(8);     //major_stack 8 ; min_value = 8
    push(5);    //major_stack 8 2; min_value = 5
    push(3);    //major_stack 8 2 1; min_value = 3
    cout<<get_min()<<endl;  //3

    push(20);   //major_stack 8 2 1 20; min_value = 3
    push(9);    //major_stack 8 2 1 20 9; min_value = 3
    cout<<get_min()<<endl;  //3
    pop();  //major_stack 8 2 1 20 ; min_value = 3
    pop();  //major_stack 8 2 1 ; min_value = 3
    pop(); //major_stack 8 2 ; min_value = 5
    cout<<get_min()<<endl; // 5

    return 0;
}
/*
Output:
-1
3
3
5
*/
