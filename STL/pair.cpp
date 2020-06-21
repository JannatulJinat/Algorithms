#include<iostream>
#include<utility>
using namespace std;
int main()
{
    //1
    pair <int, int>p1(30 , 40);
    cout << p1.first << " " << p1.second << endl;

    //2
    pair <int, int>p2;
    p2.first = 10;
    p2.second = 20;
    cout << p2.first << " " << p2.second << endl;

    //3
    pair <int, int>p3;
    p3 = make_pair(50, 30);
    cout << p3.first << " " << p3.second << endl;

    //4
    pair <string, pair <int, string> >student;
    student = make_pair("Jannatul_Jinat", make_pair(127, "A+"));
    cout << student.first << " " << student.second.first << " " << student.second.second << endl;

    return 0;
}
