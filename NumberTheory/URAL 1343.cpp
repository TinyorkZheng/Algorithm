/*	Fairy Tale*/
#include <iostream>
#include <cstdio>
using namespace std;
bool isprime(long long n)
{
    for(long long i=2;i*i<=n;i++)
        if(n%i==0)    
            return false;
    return true;
}
int main()
{
    int n; 
    cin>>n;
    long long x=0;
    if(n) cin>>x;
    for(int i=0;i<12-n;i++) x*=10;
    x=max(x,1LL);
    while(!isprime(x)) ++x;
    printf("%012I64d\n",x);
    return 0;
}
