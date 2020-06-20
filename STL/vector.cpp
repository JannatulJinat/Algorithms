#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;
//int arr[1000][100000] ;
/* creates memory allocation problem : 10^3 *10^5 = 10^8
1 int -> 4 byte
so, 4*10^8 byte = (4*10^8 / 10^3)kb = (4*10^5 / 10^3)mb = 4*10^2 MB = 400MB
*/
void vec_1D()
{
    //1D Vector
    vector <int> v1;
    v1.push_back(100);
    v1.push_back(12);
    v1.push_back(150);
    v1.push_back(12);
    for(auto x : v1)
        cout << x << "\t" ; //100 12 150 12
    cout << "\n";


    //12 12 100 150
    sort(v1.begin(), v1.end()) ;    //Intro sort [Quick + Insertion + Heap Sort], O( N * logN ) , ascending order

    //150 100 12 12
    sort(v1.begin(), v1.end(),greater<int>()) ; //descending order


    bool present = binary_search(v1.begin(), v1.end(), 12) ;    //O(log(N))   , returns 1 -> success case
    present = binary_search(v1.begin(), v1.end(), 5) ;  //returns  0 -> failed case


    v1.pop_back(); //150 100 12
    v1.empty(); //0
    v1.size();  //4
    v1.erase(v1.begin(), v1.end()) ;    // or v1.clear()


    vector <int> v2(5, 0);// 0 0 0 0 0
    vector <int> v3{14, 13, 2, 50, 74, 9};  // 14, 13, 2, 50, 74, 9

    //to replace 1st erase it then insert the number
    v3.erase(v3.begin() + 1);   //delete index 1  -> 14, 2, 50, 74, 9
    v3.insert(v3.begin() + 1, 213); // insert 213 in index 1 -> 14, 213, 2, 50, 74, 9
    for(auto x : v3)
        cout << x << "\t" ;

    cout<<endl;
}
void vec_2D()
{
    //2D Vector
    vector<vector<int> >v4;
    int row = 5,col = 4;

    //insert element into a vector of vectors
    for(int i = 0; i < row; i++)
    {
        vector<int> tempVec;
        for(int j = 0; j < col; j++)
        {
            tempVec.push_back(j);
        }
        v4.push_back(tempVec);
    }

    //print vector of vectors
    for(int i = 0; i < v4.size(); i++)
    {
        for(int j = 0; j <v4[i].size(); j++)
        {
            cout<<v4[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    vec_1D();
    vec_2D();
    return 0;
}

/*
Member functions:

push_back()
pop_back()
begin()
end(): end denotes next cell of the last element
empty() returns 0 or 1
size()
clear()
insert()
erase()
etc.
*/
