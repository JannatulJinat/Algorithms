#include<iostream>
#include<queue>
using namespace std;
void show(queue<string> tempLine)
{
    while(!tempLine.empty())
    {
        cout << tempLine.front() << endl;
        tempLine.pop();
    }
}
int main()
{
    queue <string> que;

    que.push("Jannatul Ferdous");
    que.push("Jannatul Jinat");
    que.push("Rezwan Ahamed");


    cout<<que.size()<<endl;   //3
    cout<<que.front()<<endl; //Jannatul Ferdous
    cout<<que.back()<<endl;  //Rezwan Ahamed
    cout<<que.empty()<<endl; //0

    show(que);

    return 0;
}
/*
Queue -> FIFO

Member function:

push(): O(1)
pop(): O(1)
front(): O(1)
back(): O(1)

size()
empty(): if empty then 1,else 0
*/

