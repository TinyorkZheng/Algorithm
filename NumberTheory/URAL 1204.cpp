/* Idempotents */
/* n*n=k(pq)+n
     n(n-1) = 0 (mod pq)
   get n|q&&(n-1)|p or n|p&&(n-1)|q 
     so n=px,n-1=qy or n=qx,n-1=py
     that is 1=px+qy or 1=qx+py
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int N = 40000;

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
    int k,n,p,q,x,y;
    scanf("%d",&k);
    CreatePrimeTable(N);
    while(k--){
        scanf("%d",&n);
        // get p,q
        for(int i=0; ; ++i){
            if(n%prime[i]==0){
                p=prime[i];
                q=n/p;
                break;
            }
        }
        // cal equation px+qy=1
        ExGcd(p,q,x=0,y=0);
        int ans1 = x<0? p*x+n : p*x;
        // cal equation qx+py=1
        ExGcd(q,p,x,y);
        int ans2 = x<0? q*x+n : q*x;
        printf("%d %d %d %d\n",0,1,min(ans1,ans2),max(ans1,ans2));
    }   
    return 0;
}
