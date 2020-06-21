#include<bits/stdc++.h>
#include<map>
using namespace std;
/*
to access negative index
to access huge index
when index range is unknown
*/
int main()
{
    map<string,int> m1; //key MUST BE unique ,value
    string key;

    m1["Samin"] = 20;
    m1["Sifat"] = 15;
    m1.insert(make_pair("Ratul",16));
    m1.insert(pair<string,int>("Mahin",18));


    for (auto it : m1)
        cout << it.first << "\t" << it.second << endl; //auto sorted (key) lexicographically

    if(m1.find("Ratul") != m1.end())
        cout << "Found" << endl;
    else
        cout << "not found";

    cin >> key;   // enter Samin
    m1.erase(key);
    for (auto it : m1)
        cout << it.first << "\t" << it.second << endl;

    //frequency of letter in a string
    map <char,int> frequency ;
    string x = "Jannatul Jinat";
    for (char c: x)
    {
        frequency[c]++; //(Nlog(N))
    }
    cout << frequency['J'] << " " << frequency['a'] << endl; //2 , 3
}
/*
find():O(logN)
erase() : log(N)
*/
