#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
int I,J;

// maxinum prime
// result is odd
// for even , one of its divisors is N/2,result larger than 1/2
// to find a (sum)/N , larger N is better
// if N is even , then (N/2+...)/N > 1/2 

int cal()
{
    if(I==J||I==1) return I;
    if(J%2==0) J--; 
    double minsum=10000000.0;
    int minnum = J;
    for(int n=J; n>=I; n-=2){ 
        double sum = 0;
        for(int i=2; i*i<=n; ++i){
            if(n%i==0){ 
                sum += i+n/i; // bug 1 : n/i should include
                if(i==n/i) sum -= i;
            } // bug 2 : repeat add i when i*i==n
        }
       if( minsum > sum/(n*1.0)){
             minsum = sum/(n*1.0);
             minnum = n;
        }
        if(sum==0) return n; 
    }
    return minnum;
}

int main()
{
    cin >> I >> J;
    cout << cal() << endl;
    return 0;
}
