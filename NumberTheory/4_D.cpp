#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int N = 16000;
/*  n=pq ;
    ed = 1(mod(p-1)(q-1)) ; 
      get d: ed+()y=1
      use exGcd(e,(),d,k)
    c^d = m(mod n) ;
*/

vector<int> prime;
vector<bool> isprime(N,true);

void CreatePrimeTable(int n)
{
    for(int i=2; i<n; ++i)
        if(isprime[i]){
            prime.push_back(i);
            for(int j=i+i; j<n; j+=i)
                isprime[j]=false;
        }
}

int quickMul(int a,int n,int mod)  // a^n 
{
   int t=a , res=1 ; 
   while(n) { 
        if(n&1) res = (res*t)%mod ;
        t = (t*t)%mod ;
        n >>= 1 ; 
    }
    return res ;
}

void ExGcd(int a,int b,int &x,int &y)
{
    if(b==0) { x=1;y=0;return;}
    ExGcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-a/b*y;
}

int main()
{
    int k,e,n,c,p,q,x,y;
    cin >> k ;
    CreatePrimeTable(N);
    while(k--){
        scanf("%d %d %d",&e,&n,&c);
        // get p,q
        for(int i=0; ; ++i){
            if(n%prime[i]==0){
                p=prime[i];
                q=n/p;
                break;
            }
        }
        // cal equation  ed+()y=1  
        int b=(p-1)*(q-1);
        ExGcd(e,b,x,y);
        int d = (x<0) ? (x+b)%b: x;
        // c^d mod n
        int ans = quickMul(c,d,n);
        printf("%d\n",ans);
    }   
    return 0;
}
