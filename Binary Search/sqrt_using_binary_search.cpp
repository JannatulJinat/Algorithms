/*sqrt(0.5) = 0.7071
sqrt(2) = 4
double 8 byte
500 -> 5*10^2
198765432  ->1.98765432*10^8
float -> . -> 5 cell-store
double - 15/16 digit store
l-r < 10^-6 ->precision 6 cell
eps -> epsilon -> difference
delta -> difference
abs - return type int
fabs - return type float
*/
#include<bits/stdc++.h>
using namespace std;
//#define eps 1e-5

double sqrt_using_bs(double n)
{
    double l,r,m;
    l=0.0;
    r = max(1.0,1.0*n); // if N<1 then r =1;
    int cnt = 80 ;//cnt = 60 reason -> logn->log(10^8) ~ 60
    while(cnt--)
    {
        m=(l+r)/2;
        if(m*m > n)
            r=m;
        else
            l=m;
    }
    return m;
}
int main()
{
    double n;
    cin>>n;
    cout<<setprecision(10)<<fixed<<sqrt_using_bs(n)<<"\n";
    main();
}
