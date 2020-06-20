#include<iostream>
#include<set>
using namespace std;
/*
Set -> Self Balancing Binary Search Tree
Given n integers.Find the number of distinct integer
5
10  40 20 80 30 10
output: 5
*/
int main()
{
    set <int> s1;   //collection of UNIQUE values,//set <int,greater<int> > s1; //descending order
    s1.insert(10);  // O(logN)
    s1.insert(40);
    s1.insert(20);
    s1.insert(80);
    s1.insert(30);
    s1.insert(10);

    for(int x : s1)
        cout<< x <<" "; // auto ascending order ,
    //10 20 30 40 80

    cout<< endl << s1.size();

    //to find
    auto it = s1.find(-1);  //logN
    if(it == s1.end())
        cout<<"\n not present\n";
    else
    {
        cout<<" present\n";
        cout<<*it << "\n";
    }

    set<int>:: iterator l_it, u_it;

    l_it = s1.lower_bound(20); //first_euqal_to_or_greater_than
    u_it = s1.upper_bound(39); //first_greater_than

    s1.erase(l_it,u_it);    //10 20 30 40 80
    cout<<"after delete operation:"<<endl;
    for(int x : s1)
        cout<< x <<" "; // 10 40 80

    return 0;
}
/*
Member Functions:
insert()
erase()

begin()
end()
find()
count()

size()
empty()

*/
