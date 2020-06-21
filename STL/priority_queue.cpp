#include<iostream>
#include<queue>
using namespace std;
/*
Heap data structure
*/
int main()
{
    priority_queue<int> pq;
    pq.push(400); //O(log N)
    pq.push(100);
    pq.push(500);
    pq.push(700);
    pq.push(8);

    while(!pq.empty())
    {
        int x;
        x= pq.top(); //700 500 400 100  8
        cout<<x<<endl;
        pq.pop(); ////O(log N)
    }


    priority_queue<string> name;
    name.push("d");
    name.push("n");
    name.push("a");
    name.push("r");

    while(!name.empty())
    {
        string x;
        x= name.top(); //r n d a
        cout<<x<<endl;
        name.pop();
    }

}
/*
top()
push()
pop()
*/
