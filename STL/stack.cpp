#include<iostream>
#include<stack>
using namespace std;
void show(stack<string> tempBook)
{
    while(!tempBook.empty())
    {
        cout << tempBook.top() << endl;
        tempBook.pop();
    }
}
int main()
{
    stack <string> book_stack;

    book_stack.push("Pattern Recognition");
    book_stack.push("Computer Graphics");
    book_stack.push("Digital Image Processing");

    cout<<book_stack.empty()<<endl; //0
    cout<<book_stack.size()<<endl;  //3

    show(book_stack);

    return 0;
}
/*
stack -> LIFO

Member function:

push(): O(1)
pop(): O(1)
top(): O(1)

size()
empty(): if empty then 1,else 0

*/
