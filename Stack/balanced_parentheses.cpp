/*
[{()}] valid
([{)}  invalid
*/
#include<bits/stdc++.h>
using namespace std;
bool is_balance_1(string &thread)
{
    int n = thread.size();
    if( n%2 != 0 )
        return 0;
    stack <char> stk;
    for(int i = 0; i < n; i++)
    {
        if(thread[i]== '(')
        {
            stk.push('(');
        }
        else if(thread[i]== ')')
        {
            if(stk.empty())
                return 0;
            else
                stk.pop();

        }
    }
    if( stk.empty())
        return 1;
    else
        return 0;
}

bool is_balance_2(string &thread)
{
    int n = thread.size();
    if( n%2 != 0 )
        return 0;
    stack <char> stk;
    for(int i = 0; i < n; i++)
    {
        if(thread[i]== '(' || thread[i]== '{')
        {
            stk.push(thread[i]);
        }
        else if(thread[i]== ')' || thread[i]== '}')
        {
            if(stk.empty())
                return 0;
            else
            {
                if(thread[i] == ')' && stk.top() == '(')
                    stk.pop();
                else if(thread[i] == '}' && stk.top() == '{')
                    stk.pop();
            }
        }
    }
    if( stk.empty())
        return 1;
    else
        return 0;
}

bool is_balance_mutiple(string &thread)
{
    string open = "({[" ;
    string close = ")}]" ;

    int n = thread.size();
    if( n%2 != 0 )
        return 0;

    stack <char> stk;
    for(int i = 0; i < n; i++)
    {
        ///if(thread[i]== '(' || thread[i]== '{')
        bool open_condition = 0;
        for(int j = 0 ; j<open.size() ; j++)
        {
            if(thread[i] == open[j])
                open_condition = 1;
        }
        if(open_condition)
        {
            stk.push(thread[i]);
        }
        ///else if(thread[i]== ')' || thread[i]== '}')
        bool close_condition = 0;
        for(int j = 0 ; j<close.size() ; j++)
        {
            if(thread[i] == close[j])
                close_condition = 1;
        }
        if(close_condition)
        {
            if(stk.empty())
                return 0;
            else
            {
                ///if(thread[i] == ')' && stk.top() == '(')stk.pop();
                ///else if(thread[i] == '}' && stk.top() == '{')stk.pop();
                for(int j = 0 ; j<open.size() ; j++)
                {
                    if(thread[i] == close[j] && stk.top() == open[j])
                    {
                        stk.pop();
                        break;
                    }
                }

            }
        }
    }
    if( stk.empty())
        return 1;
    else
        return 0;
}
int main()
{
    string str;
    cin >> str;

    if ( is_balance_mutiple(str) == 1 )
        cout << "Valid" << endl;
    else
        cout << "Invalid" << endl;
    main();
}
