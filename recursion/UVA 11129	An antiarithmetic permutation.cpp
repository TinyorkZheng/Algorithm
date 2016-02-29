#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
/* 5: 2 0 1 4 3  
-> 0 1 2 3 4
-> 0 2 4 1 3 
-> 0 4 2 1 3 
*/    
int v[10010],save[10010];
int n;

void spice(int l,int r)
{
    if(r-l<=1) return;  
	for(int i=l;i<=r;i++)   
        save[i] = v[i]; 
	//////
  	int t = l;
	for (int i=l; i<=r; i+=2) 
	    v[t++]=save[i];
	for (int i=l+1; i<=r; i+=2) 
	    v[t++]=save[i];
	spice(l,l+(r-l)/2);
    spice(l+(r-l)/2+1,r);
}

int main()
{
    while(cin>>n && n)
	{
        for(int i=0;i<n;++i) v[i]=i;
        spice(0,n-1);
        cout << n << ":" << v[0];
	    for(int i=1;i<n;++i) cout << " " << v[i];
        cout << endl; 
    }
    return 0;
}
